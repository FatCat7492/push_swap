#!/usr/bin/env python3

#! Commands

#! For a quick test:
# python3 test_push_swap_full.py --quick

#! For the complete test suite:
# python3 test_push_swap_full.py

"""Independent black-box tests for 42 Push_swap (no changes to C sources)."""
import argparse
import collections
import json
import random
import re
import subprocess
import sys
import time
from pathlib import Path

OPS = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}
MODES = ("default", "simple", "medium", "complex", "adaptive")
FLAG = {"default": [], "simple": ["--simple"], "medium": ["--medium"],
        "complex": ["--complex"], "adaptive": ["--adaptive"]}

def run_cmd(command, timeout):
    try:
        p = subprocess.run(command, capture_output=True, text=True,
                           timeout=timeout, errors="replace")
        return (p.returncode, p.stdout, p.stderr, None)
    except subprocess.TimeoutExpired:
        return (None, "", "", f"timeout after {timeout}s")
    except OSError as e:
        return (None, "", "", str(e))

def simulate(values, lines):
    a, b = list(values), []
    for op in lines:
        if op not in OPS:
            return False, f"unknown stdout instruction {op!r}", a, b
        if op in ("sa", "ss") and len(a) >= 2:
            a[0], a[1] = a[1], a[0]
        if op in ("sb", "ss") and len(b) >= 2:
            b[0], b[1] = b[1], b[0]
        if op in ("pa",) and b:
            a.insert(0, b.pop(0))
        if op in ("pb",) and a:
            b.insert(0, a.pop(0))
        if op in ("ra", "rr") and len(a) >= 2:
            a.append(a.pop(0))
        if op in ("rb", "rr") and len(b) >= 2:
            b.append(b.pop(0))
        if op in ("rra", "rrr") and len(a) >= 2:
            a.insert(0, a.pop())
        if op in ("rrb", "rrr") and len(b) >= 2:
            b.insert(0, b.pop())
    if a != sorted(values) or b:
        return False, f"final A={a[:15]}{'...' if len(a)>15 else ''}; B={b[:15]}", a, b
    return True, "", a, b

def disorder(values):
    n = len(values)
    if n < 2:
        return 0.0
    inv = sum(values[i] > values[j] for i in range(n)
              for j in range(i+1, n))
    return 100.0 * inv / (n*(n-1)//2)

def verify_benchmark(stderr, lines, values, mode):
    issues = []
    totals = re.findall(r"\btotal_ops:\s*(\d+)", stderr)
    if len(totals) != 1:
        issues.append("expected exactly one total_ops on stderr")
    elif int(totals[0]) != len(lines):
        issues.append(f"total_ops={totals[0]} vs stdout instructions={len(lines)}")
    count_lines = [line for line in stderr.splitlines()
                   if re.search(r"\bsa:\s*\d+|\bra:\s*\d+", line)]
    found = {}
    for line in count_lines:
        for op, num in re.findall(r"\b(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr):\s*(\d+)", line):
            found[op] = int(num)
    if set(found) != OPS:
        issues.append("missing/duplicated operation counters in benchmark")
    else:
        actual = collections.Counter(lines)
        mismatch = {op: (found[op], actual[op]) for op in sorted(OPS)
                    if found[op] != actual[op]}
        if mismatch:
            issues.append(f"counters differ from stdout: {mismatch}")
        if totals and sum(found.values()) != int(totals[0]):
            issues.append("sum of counters != total_ops")
    dm = re.search(r"\bdisorder:\s*([0-9]+(?:\.[0-9]+)?)%", stderr)
    if not dm:
        issues.append("disorder percentage missing")
    elif abs(float(dm[1]) - disorder(values)) > 0.035:
        issues.append(f"disorder {dm[1]}% differs from expected {disorder(values):.2f}%")
    sm = re.search(r"\bstrategy:\s*(.+)", stderr)
    if not sm:
        issues.append("strategy label missing")
    else:
        label = sm[1].lower()
        expected = "adaptive" if mode == "default" else mode
        if expected not in label:
            issues.append(f"strategy label does not identify {expected}")
        if "o(n" not in label:
            issues.append("complexity not shown in strategy label")
        if expected == "adaptive":
            real = ("simple" if disorder(values) < 20 else
                    "medium" if disorder(values) < 50 else "complex")
            if real not in label:
                issues.append(f"adaptive expected to select {real}")
    for line in stderr.splitlines():
        if line.strip() and not line.startswith("[bench]"):
            issues.append(f"unexpected stderr outside benchmark: {line[:90]!r}")
            break
    return issues

def make_cases(rng, quick):
    seeds = [
        [], [42], [1, 2], [2, 1], [1, 2, 3], [3, 2, 1],
        [2, 3, 1], [3, 1, 2], [2, 1, 3], [1, 3, 2],
        [1, 2, 3, 4, 5], [5, 4, 3, 2, 1], [2, 5, 1, 4, 3],
        [0, -1, 1], [-2147483648, 0, 2147483647],
        [2147483647, -2147483648], [-5, -4, -3, -2, -1],
        [9, 5, 6, 2, 1, 3, 8, 4, 7],
    ]
    cases = [("fixed", x) for x in seeds]
    sizes = [3, 5, 10, 20, 50, 100, 500]
    repetitions = {3: 2, 5: 2, 10: 2, 20: 2, 50: 1, 100: 1, 500: 1} if quick else \
                  {3: 12, 5: 12, 10: 8, 20: 6, 50: 4, 100: 4, 500: 3}
    for n in sizes:
        for _ in range(repetitions[n]):
            cases.append(("random", rng.sample(range(-100000, 100001), n)))
    return cases

def main():
    p = argparse.ArgumentParser(description="Full Push_swap black-box test runner")
    p.add_argument("--exe", default="./push_swap", help="path to your compiled push_swap")
    p.add_argument("--checker", default=None, help="optional path to external checker")
    p.add_argument("--quick", action="store_true", help="fewer randomized cases")
    p.add_argument("--seed", type=int, default=42)
    p.add_argument("--timeout", type=float, default=6.0)
    p.add_argument("--report", default="push_swap_test_report.json")
    p.add_argument("--mode", choices=("all",)+MODES, default="all")
    p.add_argument("--limit-failures", type=int, default=30)
    args = p.parse_args()
    executable = str(Path(args.exe).resolve())
    checker = str(Path(args.checker).resolve()) if args.checker else None
    if not Path(executable).is_file():
        print(f"Cannot find {executable}. Build push_swap first, then rerun this tester.")
        return 2
    if checker and not Path(checker).is_file():
        print(f"Cannot find checker: {checker}")
        return 2
    rng = random.Random(args.seed)
    results, failures, summaries = [], [], {}
    modes = MODES if args.mode == "all" else (args.mode,)
    start = time.monotonic()

    def record(category, mode, values, ok, note, count=None, bench=False):
        item = {"category":category,"mode":mode,"input":values,
                "pass":bool(ok),"note":note,"operations":count,"benchmark":bench}
        results.append(item)
        key = f"{category}/{mode}"
        stats = summaries.setdefault(key, {"passed":0,"failed":0,"max_ops":0})
        stats["passed" if ok else "failed"] += 1
        if count is not None:
            stats["max_ops"] = max(stats["max_ops"], count)
        if not ok:
            failures.append(item)
            if len(failures) <= args.limit_failures:
                print(f"FAIL [{category}/{mode}] {values[:12]}: {note}")

    for mode in modes:
        for category, values in make_cases(rng, args.quick):
            if not values:
                if mode != "default":
                    continue
                rc, out, err, failure = run_cmd([executable], args.timeout)
                record("no-args", mode, values,
                       failure is None and rc == 0 and out == "" and err == "",
                       failure or f"exit={rc}; stdout={out!r}; stderr={err!r}")
                continue
            argv = [executable]+FLAG[mode]+list(map(str, values))
            rc, out, err, failure = run_cmd(argv, args.timeout)
            if failure:
                record(category, mode, values, False, failure)
                continue
            lines = out.splitlines()
            valid, why, _, _ = simulate(values, lines)
            if out and not out.endswith("\n"):
                valid, why = False, "last stdout instruction lacks newline"
            if rc != 0 or err:
                valid = False
                why = (why+"; " if why else "")+f"exit={rc}, stderr={err[:160]!r}"
            if checker and valid:
                # Feed operation output to checker directly.
                try:
                    cp = subprocess.run([checker]+list(map(str, values)),
                                        input=out, capture_output=True, text=True,
                                        timeout=args.timeout, errors="replace")
                    if cp.returncode != 0 or cp.stdout.strip() != "OK":
                        valid, why = False, f"external checker: {cp.stdout!r} {cp.stderr!r}"
                except (subprocess.TimeoutExpired, OSError) as exc:
                    valid, why = False, f"external checker error: {exc}"
            record(category,mode,values,valid,why or "sorted, B empty",
                   len(lines))
            if not valid:
                continue
            if len(values) in (3,5) and mode in ("default","adaptive"):
                limit = 5 if len(values)==3 else 15
                record("small-operation-limit",mode,values,len(lines)<=limit,
                       f"used {len(lines)} operations, limit {limit}",len(lines))
            # --bench tests for all modes, but limited to avoid doubling huge runs
            if category == "fixed" and len(values) >= 2 or \
               category == "random" and len(values) in (20,100,500):
                brc, bout, berr, bf = run_cmd([executable]+FLAG[mode]+
                                                 ["--bench"]+list(map(str, values)),
                                                 args.timeout)
                issues = [bf] if bf else []
                if not bf:
                    if brc != 0:
                        issues.append(f"exit={brc}")
                    if bout.splitlines() != lines:
                        issues.append("stdout instructions changed when --bench enabled")
                    issues += verify_benchmark(berr, bout.splitlines(), values, mode)
                record("benchmark",mode,values,not issues,
                       "; ".join(issues) if issues else "stderr totals/counters/disorder match",
                       len(bout.splitlines()),True)
    invalid = [
        ("duplicate", ["1","2","1"]), ("invalid-number",["1","xyz","2"]),
        ("overflow-positive",["2147483648"]), ("overflow-negative",["-2147483649"]),
        ("empty-string",[""]), ("unknown-flag",["--unknown","1","2"]),
        ("duplicate-bench",["--bench","--bench","1","2"]),
        ("conflicting-modes",["--simple","--complex","3","2","1"]),
        ("invalid-number-late",["1","2","3","bad"]),
        ("huge-integer",["9"*100]),
    ]
    for category, arglist in invalid:
        rc, out, err, failure = run_cmd([executable]+arglist, args.timeout)
        ok = not failure and out == "" and err == "Error\n" and rc != 0
        record("invalid-input",category,arglist,ok,
               failure or f"exit={rc}, stdout={out[:120]!r}, stderr={err[:120]!r}")
    elapsed = time.monotonic()-start
    counts = collections.Counter("PASS" if r["pass"] else "FAIL" for r in results)
    print("\n"+"="*65)
    print(f"TOTAL: {counts['PASS']} passed | {counts['FAIL']} failed | "
          f"{len(results)} checks | {elapsed:.1f}s | seed={args.seed}")
    print("="*65)
    print(f"{'Category / mode':39s} {'Passed':>8s} {'Failed':>8s} {'Max ops':>8s}")
    for key, st in sorted(summaries.items()):
        print(f"{key[:39]:39s} {st['passed']:8d} {st['failed']:8d} {st['max_ops']:8d}")
    print("\nNOTE: max operation counts for 100/500 are informational; "
          "compare them with your subject's strategy-specific limits.")
    print("NOTE: automated simulation checks output correctness; it does not prove leak freedom.")
    report = {"executable":executable,"seed":args.seed,"time_seconds":round(elapsed,2),
              "passed":counts["PASS"],"failed":counts["FAIL"],
              "summary":summaries,"failures":failures,"results":results}
    output = Path(args.report)
    output.write_text(json.dumps(report, indent=2, ensure_ascii=False)+"\n",
                      encoding="utf-8")
    print(f"Full JSON report: {output.resolve()}")
    if len(failures)>args.limit_failures:
        print(f"Printed first {args.limit_failures} of {len(failures)} failures; see JSON.")
    return 0 if not failures else 1

if __name__ == "__main__":
    sys.exit(main())
