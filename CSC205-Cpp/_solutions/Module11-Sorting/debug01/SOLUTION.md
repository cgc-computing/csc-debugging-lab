# Solution: Quiz Score Selection Sort

**Course/Module/Activity:** CSC205 · Module 11 Sorting · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
Before: 72 45 91 60 88 45 30
After:  30 45 60 45 88 72 91
Swaps:  15
NOT sorted!
```

## The Bug(s)

`selection_sort.cpp`, function `selectionSort`: the swap is performed *inside* the inner loop, every time a new minimum candidate is found:

```cpp
for (int j = i + 1; j < n; j++) {
    if (a[j] < a[minIndex]) {
        minIndex = j;
        swap(a[i], a[minIndex]);
        swaps++;
    }
}
```

The swap belongs after the inner loop, once per pass.

## Why the Program Behaved Incorrectly

Selection sort's inner loop is supposed to only *look*: it scans the unsorted part and remembers the index of the smallest value. Here, as soon as a smaller value is spotted at `j`, it is swapped into position `i` — and the value that was at `i` moves to position `j`, which is `minIndex`. From then on `a[minIndex]` no longer holds the smallest value seen; it holds whatever got displaced. Later comparisons `a[j] < a[minIndex]` are therefore made against the wrong value, so genuinely smaller elements can be skipped and larger ones can be swapped forward. In the first pass on `72 45 91 60 88 45 30`, the swaps shuffle 72 progressively to the right and leave `45 60` out of order behind them; later passes never revisit the sorted prefix, so the damage sticks. The swap counter reveals the same thing: 15 swaps is far more than the 6 an n = 7 selection sort can perform.

## The Concept This Illustrates

Selection sort separates *finding* from *moving*: a full scan establishes the minimum, and exactly one exchange per pass places it. Merging the two steps breaks the invariant that `a[minIndex]` is the smallest value examined so far, and it also destroys the algorithm's signature property — O(n) swaps regardless of input. A student who makes this mistake usually understands "put the smallest thing first" but has not internalized that the scan must complete before anything is moved.

## The Correction

```cpp
// before
for (int j = i + 1; j < n; j++) {
    if (a[j] < a[minIndex]) {
        minIndex = j;
        swap(a[i], a[minIndex]);
        swaps++;
    }
}

// after
for (int j = i + 1; j < n; j++) {
    if (a[j] < a[minIndex]) {
        minIndex = j;
    }
}
if (minIndex != i) {
    swap(a[i], a[minIndex]);
    swaps++;
}
```

## Instructor Notes

- A tempting "fix" is to change the swap to `swap(a[i], a[j])` and keep it inside the loop. That actually produces a sorted array (it is an exchange sort), but the swap count stays high — around 9 here. Use the README's "at most 6 swaps" statement to push back: is it still selection sort?
- The `if (minIndex != i)` guard is optional; without it the count for this data is 5 (one pass finds the minimum already in place). Either is acceptable as long as students can explain the count they get.
- Ask students to compare the swap count with insertion sort or bubble sort on the same data — a concrete way to talk about why selection sort is preferred when writes are expensive.
- Have them also verify the output for an already-sorted input and an all-equal input.
