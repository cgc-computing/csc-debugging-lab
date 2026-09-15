"""Rod cutting (CLRS Section 14.1).

memoized_cut_rod is the top-down algorithm MEMOIZED-CUT-ROD; it records
each subproblem's answer in r[] so that no rod length is solved twice.
extended_bottom_up_cut_rod is the bottom-up version that also records
the first piece of an optimal cut so the cuts can be printed.  A call
counter shows how much work the top-down version does.
"""

import time

calls = 0


def memoized_cut_rod(p, n):
    r = [float("-inf")] * (n + 1)
    return _cut_rod_aux(p, n, r)


def _cut_rod_aux(p, n, r):
    global calls
    calls += 1
    if n == 0:
        q = 0
    else:
        q = float("-inf")
        for i in range(1, n + 1):
            q = max(q, p[i] + _cut_rod_aux(p, n - i, r))
    if r[n] >= 0:
        return r[n]
    r[n] = q
    return q


def extended_bottom_up_cut_rod(p, n):
    r = [0] * (n + 1)
    s = [0] * (n + 1)
    for j in range(1, n + 1):
        q = float("-inf")
        for i in range(1, j + 1):
            if q < p[i] + r[j - i]:
                q = p[i] + r[j - i]
                s[j] = i
        r[j] = q
    return r, s


def cuts(s, n):
    pieces = []
    while n > 0:
        pieces.append(s[n])
        n -= s[n]
    return pieces


def main():
    global calls
    # CLRS Section 14.1 price table for lengths 1..10, extended linearly beyond.
    p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
    p += [30 + 3 * (i - 10) for i in range(11, 31)]

    r, s = extended_bottom_up_cut_rod(p, 10)
    print(" n  revenue  calls  cuts")
    for n in range(1, 11):
        calls = 0
        rev = memoized_cut_rod(p, n)
        print(f"{n:>2}  {rev:>7}  {calls:>5}  {cuts(s, n)}")

    calls = 0
    start = time.perf_counter()
    rev = memoized_cut_rod(p, 30)
    elapsed = time.perf_counter() - start
    print()
    print(f"rod of length 30: revenue {rev}, {calls} calls, {elapsed:.3f} s")


if __name__ == "__main__":
    main()
