# Solution: Heapsort

**Course/Module/Activity:** CSC310 · Module 2 Heaps, Priority Queues, and Quicksort · debug02
**Bug type(s):** logic, boundary
**Bug count:** 2 related (both concern which part of the array MAX-HEAPIFY is allowed to treat as the heap)

## Observed Behavior

```
input:  4 1 3 2 16 9 10 14 8 7 
output: 16 10 7 9 8 2 3 14 1 4 
NOT SORTED

input:  1 2 3 4 5 6 7 
output: 7 6 5 4 3 1 2 
NOT SORTED
```

Every test is scrambled; large elements swapped to the end are pulled back toward the front.

## The Bug(s)

`heapsort.cpp`:

1. `maxHeapify` ignores its `heapSize` parameter and bounds the children by the whole array:
   ```cpp
   if (l < a.size() && a[l] > a[largest]) ...
   if (r < a.size() && a[r] > a[largest]) ...
   ```
2. `buildMaxHeap` processes internal nodes top-down:
   ```cpp
   for (std::size_t i = 0; i < n / 2; ++i) maxHeapify(a, i, n);
   ```

## Why the Program Behaved Incorrectly

(1) After `heapsort` swaps the maximum into position `i` and decrements `heapSize`, the repair at the root can still compare against, and swap with, elements in the sorted suffix, because `a.size()` never shrinks. The just-placed maximum is immediately pulled back into the heap, so the suffix is never final; for the sorted input `1..7` the result is essentially reversed.

(2) BUILD-MAX-HEAP must run from the last internal node down to the root so that when `maxHeapify(i)` runs, the subtrees below `i` are already heaps. Running `i = 0, 1, 2, ...` fixes the root before its children have been fixed, so the array is not a heap when the sorting phase begins, and the first "maximum" moved to the end need not be the maximum at all.

## The Concept This Illustrates

Heapsort's correctness rests on two invariants: the heap occupies exactly `a[0 .. heapSize-1]`, and MAX-HEAPIFY is only valid when the children's subtrees are already heaps. Bug (1) breaks the first invariant (the heap boundary is a separate quantity from the array length); bug (2) breaks the second (the bottom-up order in BUILD-MAX-HEAP is not an arbitrary choice). Students holding these bugs understand "heapify" as a local fix-up without seeing the preconditions that make the local fix-up globally sufficient.

## The Correction

```cpp
if (l < heapSize && a[l] > a[largest]) largest = l;
if (r < heapSize && a[r] > a[largest]) largest = r;
...
for (std::size_t i = n / 2; i-- > 0;) {
    maxHeapify(a, i, n);
}
```

## Instructor Notes

- Fixing only (1) still leaves three of the four tests unsorted (the duplicate-heavy `3 3 1 2 3 1` happens to come out right); fixing only (2) sorts nothing. Ask students to predict which tests each single fix will rescue before running.
- The `i-- > 0` idiom with `size_t` confuses some students; they may rewrite the loop with `int` — fine, as long as it runs from `n/2 - 1` down to 0.
- Ask why `heapSize` is passed as a parameter rather than derived from `a.size()`: the answer *is* the first bug.
