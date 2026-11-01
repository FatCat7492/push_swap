#!/usr/bin/env python3
"""Automated correctness and operation-count tests for the temporary Radix test executable.

Usage:
    python3 auto_test_radix.py ./test_radix
    python3 auto_test_radix.py ./test_radix --random 20 --seed 42
"""
import argparse
import itertools
import random
import subprocess
import sys

OPERATIONS = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}


def swap(stack):
    if len(stack) > 1:
        stack[0], stack[1] = stack[1], stack[0]


def push(src, dst):
    if src:
        dst.insert(0, src.pop(0))


def rotate(stack):
    if len(stack) > 1:
        stack.append(stack.pop(0))


def reverse_rotate(stack):
    if len(stack) > 1:
        stack.insert(0, stack.pop())


def apply_operations(numbers, operations):
    a, b = list(numbers), []
    for op in operations:
        if op == "sa":
            swap(a)
        elif op == "sb":
            swap(b)
        elif op == "ss":
            swap(a); swap(b)
        elif op == "pa":
            push(b, a)
        elif op == "pb":
            push(a, b)
        elif op == "ra":
            rotate(a)
        elif op == "rb":
            rotate(b)
        elif op == "rr":
            rotate(a); rotate(b)
        elif op == "rra":
            reverse_rotate(a)
        elif op == "rrb":
            reverse_rotate(b)
        elif op == "rrr":
            reverse_rotate(a); reverse_rotate(b)
    return a, b


def run_program(executable, numbers, timeout):
    args = [executable] + (["--complex"] if numbers else []) + [str(x) for x in numbers]
    return subprocess.run(args, capture_output=True, text=True, timeout=timeout)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("executable", nargs="?", default="./test_radix")
    parser.add_argument("--random", type=int, default=10,
                        help="random tests for each of 100 and 500 numbers (default: 10)")
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--timeout", type=float, default=8)
    args = parser.parse_args()

    rng = random.Random(args.seed)
    cases = []
    cases.append(("no arguments", [], None))
    for size in (1, 2, 3, 5):
        for perm in itertools.permutations(range(size)):
            cases.append((f"{size} numbers", list(perm), 5 if size == 3 else 15 if size == 5 else None))
    cases.extend([
        ("negatives", [-42, 100, 5, -100, 0], 15),
        ("int boundaries", [2147483647, -2147483648, 0, -1, 1], 15),
        ("sorted 100", list(range(100)), 1999),
        ("reverse 100", list(range(99, -1, -1)), 1999),
        ("sorted 500", list(range(500)), 11999),
        ("reverse 500", list(range(499, -1, -1)), 11999),
    ])
    for size, limit in ((100, 1999), (500, 11999)):
        for _ in range(max(0, args.random)):
            cases.append((f"random {size}", rng.sample(range(-200000, 200000), size), limit))

    failures = []
    stats = {}
    for idx, (label, numbers, limit) in enumerate(cases, 1):
        record = stats.setdefault(label, {"passed": 0, "total": 0, "worst_moves": 0})
        record["total"] += 1
        try:
            result = run_program(args.executable, numbers, args.timeout)
            if result.returncode != 0:
                raise ValueError(f"Exit code {result.returncode}; stderr={result.stderr.strip()!r}")
            if result.stderr:
                raise ValueError(f"Unexpected stderr: {result.stderr[:200]!r}")
            if result.stdout and not result.stdout.endswith("\n"):
                raise ValueError("Last operation is missing its newline")
            operations = result.stdout.splitlines()
            bad = [op for op in operations if op not in OPERATIONS]
            if bad:
                raise ValueError(f"Unknown/extra output: {bad[:3]!r}")
            a, b = apply_operations(numbers, operations)
            if a != sorted(numbers) or b:
                raise ValueError(f"Incorrect sorting: A={a[:12]!r}, B={b[:12]!r}")
            if not numbers and operations:
                raise ValueError("No-argument invocation should produce no operations")
            if numbers == sorted(numbers) and operations:
                raise ValueError(f"Already-sorted input should produce 0 operations; got {len(operations)}")
            if limit is not None and len(operations) > limit:
                raise ValueError(f"Too many operations: {len(operations)} (maximum {limit})")
            record["passed"] += 1
            record["worst_moves"] = max(record["worst_moves"], len(operations))
        except (ValueError, subprocess.TimeoutExpired, OSError) as error:
            failures.append((idx, label, numbers, str(error)))

    total = len(cases)
    passed = total - len(failures)
    print(f"\nBinary Radix automated tests — {passed}/{total} passed")
    print("-" * 67)
    for label, record in stats.items():
        status = "PASS" if record["passed"] == record["total"] else "FAIL"
        print(f"{status:4}  {label:16}  {record['passed']:>3}/{record['total']:<3}  "
              f"worst passing move count: {record['worst_moves']}")
    invalid_cases = [
        ["1", "1"],
        ["12", "abc"],
        ["2147483648"],
        ["-2147483649"],
        ["--complex", "--complex", "3", "2", "1"],
    ]
    invalid_passed = 0
    for tokens in invalid_cases:
        try:
            proc = subprocess.run([args.executable] + tokens, capture_output=True,
                                  text=True, timeout=args.timeout)
            if proc.returncode != 0 and proc.stdout == "" and proc.stderr.strip() == "Error":
                invalid_passed += 1
            else:
                failures.append((None, "invalid input", tokens,
                                 f"exit={proc.returncode}, stdout={proc.stdout!r}, stderr={proc.stderr!r}"))
        except (subprocess.TimeoutExpired, OSError) as error:
            failures.append((None, "invalid input", tokens, str(error)))
    print(f"Invalid-input handling — {invalid_passed}/{len(invalid_cases)} passed")
    if failures:
        print("\nFirst failures (up to 12):")
        for idx, label, numbers, detail in failures[:12]:
            shown = numbers if len(numbers) <= 10 else numbers[:10] + ["..."]
            print(f"  #{idx} {label}: {detail}\n     input: {shown}")
        if len(failures) > 12:
            print(f"  ... plus {len(failures) - 12} other failures")
    print("\nNote: tests only the temporary --complex/Radix executable, "
          "not your teammate's simple or medium strategies.")
    return 0 if not failures else 1


if __name__ == "__main__":
    sys.exit(main())
