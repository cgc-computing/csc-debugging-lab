# Solution: Insertion Sort with Comparison Counting

**Course/Module/Activity:** CSC310 · Module 1 Algorithm Analysis · debug01
**Bug type(s):** boundary
**Bug count:** 1 (the same off-by-one appears in the loop guard and in the comparison tally)

## Observed Behavior

```
input:  5 2 4 6 1 3 
sorted: 5 1 2 3 4 6 
comparisons: 8   (NOT SORTED)

input:  31 41 59 26 41 58 
sorted: 31 26 41 41 58 59 
comparisons: 7   (NOT SORTED)

input:  9 8 7 6 5 4 3 2 1 
sorted: 9 1 2 3 4 5 6 7 8 
comparisons: 28   (NOT SORTED)
...
```

The element originally at index 0 never moves; everything else is sorted after it.

## The Bug(s)

`insertion_sort.cpp`, function `insertionSort`, inner loop:

```cpp
while (i > 0 && a[i] > key) {
```

and the matching tally `if (i > 0) ++comparisons;`. The guard stops one position too early: index 0 is never compared with the key, so `a[0]` is never shifted.

## Why the Program Behaved Incorrectly

For 0-based indexing the sorted prefix is `a[0..j-1]`, and `i` starts at `j-1` and must be allowed to reach 0. With `i > 0`, the loop exits when `i == 0` without checking `a[0] > key`, and `a[i+1] = key` writes the key to index 1 at best. The first element is therefore frozen in place, and each key that belongs before it ends up one slot to its right instead. The comparison count is low for the same reason: the comparison against `a[0]` (which the correct algorithm makes for every key smaller than `a[0]`) never happens, so the reversed array reports 28 = 36 − 8 comparisons.

## The Concept This Illustrates

CLRS writes INSERTION-SORT for 1-based arrays with `while i > 0 and A[i] > key`. Translating to 0-based C++ requires shifting *every* index expression, including the loop's termination condition, to `i >= 0`. Students who translate the body but not the guard produce a program that is "almost" right. The activity also connects the counted comparisons to the analysis: the missing comparisons are exactly n − 1 in the worst case, which does not change the Θ(n²) class but does change the exact count students are trying to reproduce.

## The Correction

```cpp
int i = static_cast<int>(j) - 1;
while (i >= 0 && a[i] > key) {
    ++comparisons;
    a[i + 1] = a[i];
    --i;
}
if (i >= 0) {
    ++comparisons;
}
a[i + 1] = key;
```

## Instructor Notes

- Watch for the "fix" of starting `j` at 0: it does nothing useful and leaves the guard broken.
- Some students change `i` to `std::size_t` and then write `i >= 0`, which is always true and reads `a[SIZE_MAX]`. Use this to discuss why `i` is declared `int` here and why `&&` short-circuit order matters (`i >= 0` must be tested before `a[i]`).
- Ask why the already-sorted input still reports 4 comparisons: every key is compared exactly once with its left neighbor, which is the Θ(n) best case.
