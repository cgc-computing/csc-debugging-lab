"""Uniform random permutation in place (RANDOMIZE-IN-PLACE, CLRS 5.3).

A correct shuffle must make every one of the n! permutations equally
likely, which implies that each element is equally likely to end up in
each position.  The main block shuffles the list ['A', 'B', 'C'] many
times with a fixed seed and tallies where 'A' lands and how often each
of the six permutations appears, so the distribution can be inspected.
"""

import random

rng = random.Random(2024)


def shuffle(items):
    n = len(items)
    for i in range(n):
        j = rng.randint(0, n - 1)
        items[i], items[j] = items[j], items[i]


def main():
    trials = 100_000
    base = ["A", "B", "C"]
    position_of_a = [0, 0, 0]
    permutations = {}
    for _ in range(trials):
        items = base[:]
        shuffle(items)
        position_of_a[items.index("A")] += 1
        key = "".join(items)
        permutations[key] = permutations.get(key, 0) + 1

    expected = trials / 3
    print(f"{trials} shuffles of {base}")
    print("where 'A' ends up:")
    for pos, count in enumerate(position_of_a):
        print(f"  position {pos}: {count:>6}   ({100 * count / trials:5.2f}%)")
    print(f"  expected about {expected:.0f} each; largest deviation "
          f"{max(abs(c - expected) for c in position_of_a):.0f}")
    print()
    print("permutation frequencies (expected about "
          f"{trials / 6:.0f} each):")
    for key in sorted(permutations):
        print(f"  {key}: {permutations[key]:>6}")
    spread = max(permutations.values()) - min(permutations.values())
    print(f"  spread between most and least common: {spread}")
    print(f"  uniform within 3%: {spread < 0.03 * trials / 6}")


if __name__ == "__main__":
    main()
