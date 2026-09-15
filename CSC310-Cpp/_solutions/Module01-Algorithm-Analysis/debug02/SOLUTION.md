# Solution: Counting Distinct Values in Linear Time

**Course/Module/Activity:** CSC310 · Module 1 Algorithm Analysis · debug02
**Bug type(s):** conceptual/design (performance)
**Bug count:** 2 related (two hidden linear-time operations inside a loop claimed to be linear overall)

## Observed Behavior

The counts are correct but the timings grow quadratically; the last size takes seconds:

```
n = 20000  distinct = 12654  time = 38.688 ms
n = 40000  distinct = 25310  time = 169.475 ms  (ratio to previous n: 4.38055)
n = 80000  distinct = 50692  time = 676.639 ms  (ratio to previous n: 3.99256)
n = 160000  distinct = 101140  time = 2726.68 ms  (ratio to previous n: 4.02974)
A linear-time routine should show a ratio near 2 each time n doubles.
```

## The Bug(s)

`distinct_count.cpp`, function `countDistinct`:

```cpp
std::vector<int> seen;
while (!work.empty()) {
    int x = work.front();
    work.erase(work.begin());                              // O(n) shift
    if (std::find(seen.begin(), seen.end(), x) == seen.end()) {   // O(k) scan
        seen.push_back(x);
    }
}
```

Both `erase(begin())` and `std::find` on a vector are linear in the container's size, so the "single pass" costs Θ(n²).

## Why the Program Behaved Incorrectly

Erasing the first element of a `std::vector` moves every remaining element down one slot, so the n erasures cost n + (n−1) + ... = Θ(n²) element moves. Independently, `std::find` scans the whole `seen` vector, which grows to roughly 0.63n distinct values, giving another Θ(n²) comparisons. Doubling n multiplies both costs by about 4, which is what the measured ratios (≈ 4) show once n is large enough for the constant factors to stop dominating.

## The Concept This Illustrates

Asymptotic analysis must account for the cost of *every* operation in the loop body, not just the loop count. Library calls that read like O(1) ("remove the front", "is x in seen?") have costs that depend on the container: `vector::erase(begin())` is Θ(n) while `deque::pop_front` is O(1); `std::find` on a vector is Θ(k) while `unordered_set::find` is expected O(1). The empirical doubling test (ratio ≈ 2 for linear, ≈ 4 for quadratic) is a practical way to check a claimed bound.

## The Correction

```cpp
std::size_t countDistinct(const std::vector<int>& work) {
    std::unordered_set<int> seen;
    for (std::size_t i = 0; i < work.size(); ++i) {
        seen.insert(work[i]);
    }
    return seen.size();
}
```

With `#include <unordered_set>`. Iterating by index removes the erase; the hash set makes membership expected O(1). Both changes are needed to reach Θ(n): fixing only one leaves a Θ(n²) term, which students can verify by the ratios.

## Instructor Notes

- Students who only replace `vector` with `std::deque` (so `pop_front` is O(1)) will still see ratios near 4 because of `std::find`; ask them which term is now dominating and how they could tell from the numbers.
- `std::set` gives O(n log n) overall; the ratios will be slightly above 2. Good discussion: is that "linear"?
- The seed is fixed, so distinct counts are reproducible; absolute times are not. Have students run several times and talk about noise versus trend.
- Point out that sorting first and counting runs is Θ(n log n) and needs no hashing: another legitimate design with a different bound.
