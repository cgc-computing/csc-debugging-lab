"""Reservoir sampling (Algorithm R).

reservoir_sample(stream, k) reads the stream once and returns k items
such that every k-subset of the stream is equally likely.  The first k
items fill the reservoir; each later item (the t-th item seen, counting
from 1) replaces a uniformly chosen reservoir slot with probability k/t.
The main block draws samples many times with a fixed seed and tallies
how often each stream item is selected.
"""

import random

rng = random.Random(7)


def reservoir_sample(stream, k):
    reservoir = []
    for t, item in enumerate(stream, start=1):
        if t <= k:
            reservoir.append(item)
        else:
            j = rng.randrange(t - 1)
            if j < k:
                reservoir[j] = item
    return reservoir


def tally(stream, k, trials):
    counts = {item: 0 for item in stream}
    for _ in range(trials):
        for item in reservoir_sample(stream, k):
            counts[item] += 1
    return counts


def report(stream, k, trials):
    counts = tally(stream, k, trials)
    expected = trials * k / len(stream)
    print(f"sample {k} of {len(stream)} items, {trials} trials, "
          f"expected about {expected:.0f} selections each")
    for item in stream:
        c = counts[item]
        print(f"  item {item:>2}: {c:>6}   ({100 * c / (trials * k):5.2f}%)")
    worst = max(abs(counts[item] - expected) for item in stream)
    print(f"  largest deviation from expected: {worst:.0f} "
          f"({100 * worst / expected:.1f}%)")
    print()


def main():
    report(list(range(1, 5)), 1, 40_000)
    report(list(range(1, 11)), 3, 40_000)


if __name__ == "__main__":
    main()
