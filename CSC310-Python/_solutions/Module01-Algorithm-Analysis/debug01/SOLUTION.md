# Solution: Insertion Sort With a Comparison Counter

**Course/Module/Activity:** CSC310 · Module 1 Algorithm Analysis · debug01
**Bug type(s):** boundary
**Bug count:** 1

## Observed Behavior

Every sample comes out with the first element stuck in place and the rest sorted behind it:

```
[5, 2, 4, 6, 1, 3] -> [5, 1, 2, 3, 4, 6]
   sorted correctly: False   comparisons: 10
[31, 41, 59, 26, 41, 58] -> [31, 26, 41, 41, 58, 59]
   sorted correctly: False   comparisons: 9
[3, 1, 2] -> [3, 1, 2]
   sorted correctly: False   comparisons: 2
[9, 8, 7, 6, 5, 4, 3, 2, 1] -> [9, 1, 2, 3, 4, 5, 6, 7, 8]
   sorted correctly: False   comparisons: 36
```

The n = 8 comparison counts happen to match the predicted values, which can mislead students into
thinking the analysis "checks out".

## The Bug(s)

`insertion_sort.py`, function `insertion_sort`, inner loop condition:

```python
while i > 0 and A[i] > key:
```

CLRS's 1-based `while i > 0 and A[i] > key` was copied literally. With 0-based indexing the
sorted prefix begins at index 0, so the loop must be allowed to run while `i >= 0`.

## Why the Program Behaved Incorrectly

The inner loop stops as soon as `i` reaches 0, so `A[0]` is never compared with `key` and never
shifted right. The key is written to `A[i + 1] = A[1]` at best. The element originally at index 0
therefore keeps its position forever, and every other element is sorted into positions 1..n-1. On
`[3, 1, 2]` the key 1 is compared only against nothing (i starts at 0, loop condition fails
immediately), so the list is unchanged.

## The Concept This Illustrates

Translating pseudocode between index bases is a boundary-condition exercise: every occurrence of
`1` as "first index" becomes `0`, and every `> 0` guard that meant "still inside the array" becomes
`>= 0`. Reasoning with the loop invariant (before iteration j, `A[0..j-1]` is sorted and contains the
original first j elements) exposes the error: the invariant is not maintained when `key` is smaller
than `A[0]`.

## The Correction

```python
# before
while i > 0 and A[i] > key:
# after
while i >= 0 and A[i] > key:
```

## Instructor Notes

- Common wrong fix: starting the outer loop at `j = 0` or changing `i = j - 1` to `i = j`. Ask
  students to trace `[3, 1, 2]` with their change; the second one indexes past the end.
- Some students will change the loop to `while i > -1`, which is correct but worth a comment about
  readability.
- Ask why the comparison counts for the n = 8 cases matched the theory even though the sort was
  wrong. (Sorted input never enters the inner loop; reverse input shifts everything except `A[0]`
  and the counter still reaches 28 because the after-loop `if i >= 0` branch counts the stop.)
- Follow-up: once fixed, have students confirm that the counts for the six-element sample match a
  hand trace.
