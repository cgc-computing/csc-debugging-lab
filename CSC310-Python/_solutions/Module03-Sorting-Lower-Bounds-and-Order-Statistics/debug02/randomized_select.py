"""Order statistics in expected linear time (CLRS Section 9.2).

randomized_select(A, p, r, i) returns the i-th smallest element of the
sub-list A[p..r] (inclusive), with i counted from 1.  It partitions
around a randomly chosen pivot and recurses into the side that must
contain the answer.  The random generator is seeded so runs repeat.
"""

import random

rng = random.Random(20)


def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def randomized_partition(A, p, r):
    k = rng.randint(p, r)
    A[k], A[r] = A[r], A[k]
    return partition(A, p, r)


def randomized_select(A, p, r, i):
    if p == r:
        return A[p]
    q = randomized_partition(A, p, r)
    k = q - p + 1                # number of elements in the low side plus pivot
    if i == k:
        return A[q]
    elif i < k:
        return randomized_select(A, p, q - 1, i)
    else:
        return randomized_select(A, q + 1, r, i - k)


def select(values, i):
    """i-th smallest of values (1-based) without disturbing the caller's list."""
    A = list(values)
    return randomized_select(A, 0, len(A) - 1, i)


def main():
    data = [12, 3, 5, 7, 4, 19, 26, 1, 8, 15]
    ranked = sorted(data)
    print("data  :", data)
    print("sorted:", ranked)
    print()
    all_ok = True
    for i in range(1, len(data) + 1):
        got = select(data, i)
        ok = got == ranked[i - 1]
        all_ok = all_ok and ok
        print(f"  {i:>2}-th smallest: {got:>3}   expected {ranked[i - 1]:>3}   {'ok' if ok else 'MISMATCH'}")
    print()
    print("all order statistics correct:", all_ok)
    n = len(data)
    print("median (i = (n+1)//2):", select(data, (n + 1) // 2))


if __name__ == "__main__":
    main()
