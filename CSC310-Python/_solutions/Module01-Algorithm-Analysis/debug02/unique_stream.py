"""Remove duplicates from a stream of readings in a single pass.

unique_in_order(items) consumes the items front to back like a queue and
keeps the first occurrence of each value.  Every item is examined exactly
once, so the function is designed to run in O(n) time.  The main block
times the function on n = 10000 and n = 20000 readings; doubling n should
roughly double the running time.
"""

import random
import time
from collections import deque


def unique_in_order(items):
    """Return the distinct values of items, in order of first appearance."""
    pending = deque(items)       # work queue with O(1) removal from the front
    seen = set()                 # values already emitted; O(1) membership test
    result = []
    while pending:
        x = pending.popleft()    # take the next reading from the front
        if x not in seen:
            seen.add(x)
            result.append(x)
    return result


def make_readings(n, seed):
    """n sensor readings drawn from a large range; only a few repeat."""
    rng = random.Random(seed)
    readings = [rng.randrange(10 ** 9) for _ in range(n - 5)]
    readings += readings[:5]     # guarantee a handful of duplicates
    return readings


def timed_run(n):
    data = make_readings(n, seed=310)
    start = time.perf_counter()
    out = unique_in_order(data)
    elapsed = time.perf_counter() - start
    return len(out), elapsed


def main():
    small = [4, 7, 4, 1, 7, 9, 1, 4]
    print("unique_in_order([4, 7, 4, 1, 7, 9, 1, 4]) =", unique_in_order(small))
    print()

    n1, n2 = 10000, 20000
    u1, t1 = timed_run(n1)
    u2, t2 = timed_run(n2)
    print(f"n = {n1:>6}: {u1} unique readings, {t1:.3f} s")
    print(f"n = {n2:>6}: {u2} unique readings, {t2:.3f} s")
    print(f"time ratio (n doubled): {t2 / t1:.1f}x")


if __name__ == "__main__":
    main()
