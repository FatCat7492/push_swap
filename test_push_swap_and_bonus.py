#!/usr/bin/env python3

#! Commands

#! For a quick test:
# python3 test_push_swap_and_bonus.py --quick

#! For the complete test suite:
# python3 test_push_swap_and_bonus.py

#! Only one or the other:
# python3 test_push_swap_and_bonus.py --only mandatory
# python3 test_push_swap_and_bonus.py --only bonus 

"""Black-box Push_swap + checker_bonus test runner (Python 3, stdlib only).

Run from the project root after building ./push_swap and ./checker.
This tests binaries; it does not modify C sources or prove Norm/leak safety.
"""
import argparse
import collections
import json
import random
import re
import subprocess
import sys
import time
from pathlib import Path

OPERATIONS = ('sa', 'sb', 'ss', 'pa', 'pb', 'ra', 'rb', 'rr', 'rra', 'rrb', 'rrr')
MODES = {
    'default': [], 'simple': ['--simple'], 'medium': ['--medium'],
    'complex': ['--complex'], 'adaptive': ['--adaptive'],
}


def execute(binary, args, timeout, stdin=''):
    try:
        proc = subprocess.run([str(binary), *args], input=stdin, text=True,
                              capture_output=True, errors='replace', timeout=timeout)
        return {'code': proc.returncode, 'out': proc.stdout,
                'err': proc.stderr, 'error': None}
    except (OSError, subprocess.TimeoutExpired) as exc:
        return {'code': None, 'out': '', 'err': '', 'error': str(exc)}


def simulate(numbers, instructions):
    a, b = list(numbers), []
    for operation in instructions:
        if operation not in OPERATIONS:
            raise ValueError('invalid instruction ' + repr(operation))
        if operation in ('sa', 'ss') and len(a) > 1:
            a[0], a[1] = a[1], a[0]
        if operation in ('sb', 'ss') and len(b) > 1:
            b[0], b[1] = b[1], b[0]
        if operation == 'pb' and a:
            b.insert(0, a.pop(0))
        if operation == 'pa' and b:
            a.insert(0, b.pop(0))
        if operation in ('ra', 'rr') and len(a) > 1:
            a.append(a.pop(0))
        if operation in ('rb', 'rr') and len(b) > 1:
            b.append(b.pop(0))
        if operation in ('rra', 'rrr') and len(a) > 1:
            a.insert(0, a.pop())
        if operation in ('rrb', 'rrr') and len(b) > 1:
            b.insert(0, b.pop())
    return a, b


def expected_checker(numbers, instructions):
    a, b = simulate(numbers, instructions)
    return 'OK\n' if a == sorted(numbers) and not b else 'KO\n'


def disorder(numbers):
    size = len(numbers)
    if size < 2:
        return 0.0
    inversions = sum(numbers[i] > numbers[j] for i in range(size)
                     for j in range(i + 1, size))
    return 100 * inversions / (size * (size - 1) / 2)


def benchmark_issues(stderr, ops, numbers, mode):
    """Match the format used by the previous tester and user's project."""
    problems = []
    totals = re.findall(r'\btotal_ops:\s*(\d+)', stderr)
    if len(totals) != 1:
        problems.append('expected one total_ops field on stderr')
    elif int(totals[0]) != len(ops):
        problems.append('total_ops does not match instruction count')
    pairs = re.findall(r'\b(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr):\s*(\d+)', stderr)
    counters = collections.Counter(name for name, _ in pairs)
    if any(counters[name] != 1 for name in OPERATIONS):
        problems.append('expected exactly one counter for each of 11 operations')
    else:
        actual = collections.Counter(ops)
        differences = [name for name, value in pairs if int(value) != actual[name]]
        if differences:
            problems.append('operation counters mismatch: ' + ', '.join(differences))
        if totals and sum(int(num) for _, num in pairs) != int(totals[0]):
            problems.append('sum of counters differs from total_ops')
    m = re.search(r'\bdisorder:\s*([\d.]+)%', stderr)
    if not m:
        problems.append('disorder percentage missing')
    elif abs(float(m.group(1)) - disorder(numbers)) > 0.04:
        problems.append('disorder percentage mismatch')
    label = re.search(r'\bstrategy:\s*([^\n]+)', stderr, re.IGNORECASE)
    if not label:
        problems.append('strategy label missing')
    else:
        text = label.group(1).lower()
        target = 'adaptive' if mode == 'default' else mode
        if target not in text:
            problems.append('strategy name mismatch')
        if 'o(n' not in text:
            problems.append('complexity label missing')
        if mode in ('default', 'adaptive'):
            expected = ('simple' if disorder(numbers) < 20 else
                        'medium' if disorder(numbers) < 50 else 'complex')
            if expected not in text:
                problems.append('adaptive selected strategy mismatch')
    if any(x.strip() and not x.startswith('[bench]') for x in stderr.splitlines()):
        problems.append('unexpected benchmark stderr format')
    return problems


def generated_cases(seed, quick):
    rng = random.Random(seed)
    cases = [
        ('fixed-empty', []), ('fixed-single', [42]),
        ('fixed', [1, 2]), ('fixed', [2, 1]),
        ('fixed', [1, 2, 3]), ('fixed', [3, 2, 1]),
        ('fixed', [2, 3, 1]), ('fixed', [3, 1, 2]),
        ('fixed', [2, 1, 3]), ('fixed', [1, 3, 2]),
        ('fixed', [1, 2, 3, 4, 5]), ('fixed', [5, 4, 3, 2, 1]),
        ('fixed', [2, 5, 1, 4, 3]), ('fixed', [0, -1, 1]),
        ('fixed', [-2147483648, 0, 2147483647]),
        ('fixed', [2147483647, -2147483648]),
        ('fixed', [-5, -4, -3, -2, -1]),
        ('fixed', [9, 5, 6, 2, 1, 3, 8, 4, 7]),
    ]
    repeats = ({3: 2, 5: 2, 10: 2, 20: 2, 50: 1, 100: 1, 500: 1}
               if quick else
               {3: 12, 5: 12, 10: 8, 20: 6, 50: 4, 100: 4, 500: 3})
    for size, repeat in repeats.items():
        for _ in range(repeat):
            cases.append(('random', rng.sample(range(-1000000, 1000001), size)))
    return cases


class Report:
    def __init__(self, print_limit):
        self.tests = []
        self.print_limit = print_limit
        self.fail_count = 0

    def add(self, component, category, name, ok, note='', **extra):
        entry = {'component': component, 'category': category, 'name': name,
                 'pass': bool(ok), 'note': note, **extra}
        self.tests.append(entry)
        if not ok:
            self.fail_count += 1
            if self.fail_count <= self.print_limit:
                print(f'FAIL [{component}/{category}] {name}: {note[:220]}', flush=True)

    def show(self, elapsed):
        print('\n' + '=' * 76)
        for part in ('mandatory', 'bonus', 'integration'):
            subset = [r for r in self.tests if r['component'] == part]
            passed = sum(r['pass'] for r in subset)
            failed = len(subset) - passed
            print(f'{part.upper():12s}: {passed:4d} passed | {failed:4d} failed | '
                  f'{len(subset):4d} tests')
        passed = sum(r['pass'] for r in self.tests)
        print(f'TOTAL: {passed} passed | {self.fail_count} failed | '
              f'{len(self.tests)} tests | {elapsed:.1f}s')
        print('=' * 76)
        groups = collections.defaultdict(lambda: [0, 0, 0])
        for row in self.tests:
            key = (row['component'], row['category'])
            groups[key][0 if row['pass'] else 1] += 1
            if isinstance(row.get('operations'), int):
                groups[key][2] = max(groups[key][2], row['operations'])
        print(f'{"Component / category":47s} {"Pass":>6s} {"Fail":>6s} {"Max ops":>8s}')
        for (part, category), stats in sorted(groups.items()):
            print(f'{(part + "/" + category)[:47]:47s} '
                  f'{stats[0]:6d} {stats[1]:6d} {stats[2]:8d}')
        if self.fail_count > self.print_limit:
            print(f'Only first {self.print_limit} failures displayed; all saved in JSON.')


def command_failure(result):
    return result['error'] or f"exit={result['code']}, stdout={result['out'][:100]!r}, stderr={result['err'][:100]!r}"


def test_mandatory(report, exe, timeout, modes, cases, checker=None):
    for mode in modes:
        for index, (kind, numbers) in enumerate(cases):
            if not numbers and mode != 'default':
                continue
            command = MODES[mode] + list(map(str, numbers))
            outcome = execute(exe, command, timeout)
            title = f'{mode} #{index} n={len(numbers)} {numbers[:5]}'
            if outcome['error']:
                report.add('mandatory', 'sorting/' + mode, title, False,
                           outcome['error'], input=numbers)
                continue
            ops = outcome['out'].splitlines()
            faults = []
            if numbers:
                if outcome['code'] != 0 or outcome['err']:
                    faults.append(command_failure(outcome))
                if outcome['out'] and not outcome['out'].endswith('\n'):
                    faults.append('instruction output missing final newline')
                try:
                    a, b = simulate(numbers, ops)
                    if a != sorted(numbers) or b:
                        faults.append(f'final A={a[:12]}, B={b[:12]}')
                except ValueError as exc:
                    faults.append(str(exc))
            elif outcome['code'] != 0 or outcome['out'] or outcome['err']:
                faults.append('no-arguments case must exit silently')
            report.add('mandatory', 'sorting/' + mode, title, not faults,
                       '; '.join(faults), input=numbers, operations=len(ops))
            if not numbers or outcome['error']:
                continue
            if len(numbers) in (3, 5) and mode in ('default', 'adaptive'):
                limit = 5 if len(numbers) == 3 else 15
                report.add('mandatory', 'small-operation-limit/' + mode, title,
                           len(ops) <= limit,
                           f'{len(ops)} instructions; limit {limit}',
                           input=numbers, operations=len(ops))
            if ((kind == 'fixed' and len(numbers) >= 2) or
                (kind == 'random' and len(numbers) in (20, 100, 500))):
                bench = execute(exe, MODES[mode] + ['--bench'] +
                                list(map(str, numbers)), timeout)
                errors = [bench['error']] if bench['error'] else []
                if not bench['error']:
                    if bench['code'] != 0:
                        errors.append('benchmark nonzero exit')
                    if bench['out'] != outcome['out']:
                        errors.append('benchmark changed instruction output')
                    errors += benchmark_issues(bench['err'], ops, numbers, mode)
                report.add('mandatory', 'benchmark/' + mode, title, not errors,
                           '; '.join(errors), input=numbers, operations=len(ops))

    bad_inputs = [
        ('duplicate', ['1', '2', '1']),
        ('invalid-token', ['1', 'hello', '2']),
        ('overflow-positive', ['2147483648']),
        ('overflow-negative', ['-2147483649']),
        ('empty-string', ['']),
        ('invalid-flag', ['--unknown', '1', '2']),
        ('duplicate-bench', ['--bench', '--bench', '1', '2']),
        ('conflicting-strategies', ['--simple', '--complex', '3', '2', '1']),
        ('invalid-late', ['1', '2', '3', 'bad']),
        ('huge-integer', ['9' * 100]),
    ]
    for name, words in bad_inputs:
        result = execute(exe, words, timeout)
        ok = (result['error'] is None and result['out'] == '' and
              result['err'] == 'Error\n' and result['code'] != 0)
        report.add('mandatory', 'invalid-arguments', name, ok,
                   '' if ok else command_failure(result), input=words)


def assert_checker(report, checker, timeout, name, numbers, program,
                   expected, category='instructions', argv=None):
    args = list(map(str, numbers)) if argv is None else argv
    result = execute(checker, args, timeout, program)
    if expected == 'Error\n':
        ok = (result['error'] is None and result['out'] == '' and
              result['err'] == 'Error\n')
    else:
        ok = (result['error'] is None and result['code'] == 0 and
              result['out'] == expected and result['err'] == '')
    report.add('bonus', category, name, ok,
               '' if ok else f'expected {expected!r}; {command_failure(result)}',
               input=args, instructions=program, expected=expected)


def test_bonus(report, checker, timeout, cases):
    assert_checker(report, checker, timeout, 'no arguments', [], '', '', 'no-args')
    assert_checker(report, checker, timeout, 'no args with instructions', [],
                   'sa\n', '', 'no-args')
    for ix, (kind, values) in enumerate(cases):
        if not values:
            continue
        args = list(map(str, values))
        for program in ('', 'sa\n', 'pb\n', 'pb\npa\n'):
            instructions = program.splitlines()
            expected = expected_checker(values, instructions)
            assert_checker(report, checker, timeout,
                           f'{kind} #{ix} n={len(values)} {program.strip()!r}',
                           values, program, expected, 'known-results')
    # Each legal operation on nonempty or two-stack configurations.
    for op in OPERATIONS:
        for prefix in ('', 'pb\npb\n'):
            values = [3, 1, 2, 4]
            seq = prefix + op + '\n'
            assert_checker(report, checker, timeout,
                           f'operation {op} after {prefix!r}', values, seq,
                           expected_checker(values, seq.splitlines()), 'all-11-operations')
    # Longer operation streams, including repeated and combined operations.
    rng = random.Random(909)
    for ix in range(12):
        values = rng.sample(range(-2000, 2001), 8)
        ops = rng.choices(OPERATIONS, k=25)
        program = ''.join(op + '\n' for op in ops)
        assert_checker(report, checker, timeout, f'mixed operations #{ix}',
                       values, program, expected_checker(values, ops), 'mixed-operations')
    # Validate quoted input and whitespace only where the mandatory parser accepts it.
    for name, arglist, instructions, expect in [
        ('quoted-unsorted', ['3 2 1'], '', 'KO\n'),
        ('quoted-sorted', ['1 2 3'], '', 'OK\n'),
        ('separate-sorted', ['1', '2', '3'], '', 'OK\n'),
        ('negative-values', ['-2', '-1', '0'], '', 'OK\n'),
        ('one-number', ['42'], '', 'OK\n'),
    ]:
        assert_checker(report, checker, timeout, name, [], instructions, expect,
                       'argument-formats', argv=arglist)
    invalid_args = [
        ('duplicate', ['1', '2', '1']),
        ('duplicate-in-quoted', ['1 2 1']),
        ('invalid-integer', ['1', 'abc', '2']),
        ('overflow-positive', ['2147483648']),
        ('overflow-negative', ['-2147483649']),
        ('invalid-after-valid', ['1', '2', 'bad']),
        ('empty-arg', ['']),
    ]
    for name, args in invalid_args:
        assert_checker(report, checker, timeout, name, [], '', 'Error\n',
                       'invalid-arguments', argv=args)
    malformed = [
        ('unknown', 'hello\n'), ('prefix', 'saa\n'), ('suffix', 'raextra\n'),
        ('blank-line', '\n'), ('space-after', 'sa \n'),
        ('space-before', ' sa\n'), ('uppercase', 'SA\n'),
        ('unfinished-line', 'sa'), ('trailing-empty', 'sa\n\n'),
        ('invalid-after-valid', 'sa\nwhat\n'),
        ('invalid-after-transfer', 'pb\ninvalid\n'),
        ('non-ASCII-instruction', 'é\n'), ('capitalized', 'Pb\n'),
        ('extra-newline-in-middle', 'pb\n\npa\n'),
        ('invalid-rrr', 'rrrr\n'),
    ]
    for name, program in malformed:
        assert_checker(report, checker, timeout, name, [3, 2, 1], program,
                       'Error\n', 'invalid-instructions')
    # Valid no-op instructions must not be treated as malformed.
    for name, values, program in [
        ('swap-single', [1], 'sa\n'),
        ('rotate-single', [1], 'ra\n'),
        ('reverse-rotate-single', [1], 'rra\n'),
        ('pop-empty-B', [1], 'pa\n'),
        ('rotate-empty-B', [1], 'rb\n'),
        ('swap-empty-B', [1], 'sb\n'),
        ('combined-empty-B', [1], 'ss\nrr\nrrr\n'),
        ('empty-A-and-B-nonempty', [1], 'pb\n'),
    ]:
        assert_checker(report, checker, timeout, name, values, program,
                       expected_checker(values, program.splitlines()), 'edge-cases')


def test_integration(report, push_swap, checker, timeout, cases, modes):
    for mode in modes:
        for index, (kind, values) in enumerate(cases):
            if not values:
                continue
            title = f'{mode} #{index} n={len(values)}'
            result = execute(push_swap, MODES[mode] + list(map(str, values)), timeout)
            if result['error'] or result['code'] != 0:
                report.add('integration', 'pipe/' + mode, title, False,
                           command_failure(result), input=values)
                continue
            # Run checker independently, even for a broken sorting algorithm.
            checked = execute(checker, list(map(str, values)), timeout, result['out'])
            try:
                a, b = simulate(values, result['out'].splitlines())
                expected = 'OK\n' if a == sorted(values) and not b else 'KO\n'
            except ValueError:
                expected = 'Error\n'
            ok = (checked['error'] is None and checked['code'] == 0 and
                  checked['out'] == expected and checked['err'] == '')
            report.add('integration', 'pipe/' + mode, title, ok,
                       '' if ok else f'expected checker {expected!r}, {command_failure(checked)}',
                       input=values, instructions_count=len(result['out'].splitlines()),
                       expected=expected)
            # Separate result: did push_swap actually sort correctly?
            report.add('integration', 'sorted-pipeline/' + mode, title,
                       ok and expected == 'OK\n',
                       '' if ok and expected == 'OK\n' else
                       f'sort={expected.strip()!r}, checker={checked["out"].strip()!r}',
                       input=values)


def main():
    parser = argparse.ArgumentParser(description='Test both mandatory push_swap and bonus checker.')
    parser.add_argument('--push-swap', default='./push_swap')
    parser.add_argument('--checker', default='./checker')
    parser.add_argument('--quick', action='store_true', help='shorter randomized suite')
    parser.add_argument('--mode', choices=('all', *MODES), default='all')
    parser.add_argument('--seed', type=int, default=42)
    parser.add_argument('--timeout', type=float, default=6.0)
    parser.add_argument('--report', default='push_swap_bonus_report.json')
    parser.add_argument('--limit-failures', type=int, default=35)
    parser.add_argument('--only', choices=('all', 'mandatory', 'bonus', 'integration'),
                        default='all')
    args = parser.parse_args()
    push_swap = Path(args.push_swap).resolve()
    checker = Path(args.checker).resolve()
    needs_push = args.only in ('all', 'mandatory', 'integration')
    needs_checker = args.only in ('all', 'bonus', 'integration')
    for needed, path, label in ((needs_push, push_swap, 'push_swap'),
                                (needs_checker, checker, 'checker')):
        if needed and not path.is_file():
            print(f'MISSING: {label} executable at {path}', file=sys.stderr)
            print('Build the binaries first: make && make bonus', file=sys.stderr)
            return 2
    report = Report(args.limit_failures)
    modes = tuple(MODES) if args.mode == 'all' else (args.mode,)
    cases = generated_cases(args.seed, args.quick)
    start = time.monotonic()
    if args.only in ('all', 'mandatory'):
        test_mandatory(report, push_swap, args.timeout, modes, cases)
    if args.only in ('all', 'bonus'):
        test_bonus(report, checker, args.timeout, cases)
    if args.only in ('all', 'integration'):
        test_integration(report, push_swap, checker, args.timeout, cases, modes)
    elapsed = time.monotonic() - start
    report.show(elapsed)
    payload = {
        'generated_at': time.strftime('%Y-%m-%dT%H:%M:%S%z'),
        'push_swap': str(push_swap), 'checker': str(checker),
        'seed': args.seed, 'mode': args.mode, 'only': args.only,
        'quick': args.quick, 'elapsed_seconds': round(elapsed, 2),
        'passed': sum(x['pass'] for x in report.tests),
        'failed': report.fail_count, 'tests': report.tests,
        'failures': [x for x in report.tests if not x['pass']],
    }
    try:
        Path(args.report).write_text(json.dumps(payload, indent=2, ensure_ascii=False) + '\n',
                                     encoding='utf-8')
        print('JSON report: ' + str(Path(args.report).resolve()))
    except OSError as exc:
        print('Could not save JSON report: ' + str(exc), file=sys.stderr)
        return 2
    print('NOTE: No memory-safety, Norminette, build, or exact 100/500 grading proof.')
    return 1 if report.fail_count else 0


if __name__ == '__main__':
    sys.exit(main())
