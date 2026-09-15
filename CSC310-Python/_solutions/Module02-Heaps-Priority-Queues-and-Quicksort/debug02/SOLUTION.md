# Solution: Heapsort and a Max-Priority Queue

**Course/Module/Activity:** CSC310 · Module 2 Heaps, Priority Queues, and Quicksort · debug02
**Bug type(s):** logic, boundary
**Bug count:** 2 (related: both concern which part of the array is "the heap" and when it is one)

## Observed Behavior

```
heapsort: [16, 14, 7, 10, 2, 8, 9, 3, 4, 1]
sorted correctly: False
heapsort: [13, 20, 7, 17, 8, 5, 2, 25, 4]
sorted correctly: False
priority queue drained: [15, 13, 12, 11, 10, 9, 7, 6, 5, 4, 2, 1, 0]
non-increasing: True
```

Heapsort produces garbage (large keys near the front), while the priority queue is correct.

## The Bug(s)

`heapsort_pq.py`:

1. `max_heapify` bounds-checks the children against `len(A)` instead of the `heap_size` parameter:

   ```python
   if l < len(A) and A[l] > A[largest]:
   if r < len(A) and A[r] > A[largest]:
   ```

2. `build_max_heap` visits the internal nodes from the top down:

   ```python
   for i in range(0, n // 2):
   ```

   instead of from the last internal node up to the root.

## Why the Program Behaved Incorrectly

Bug 1: heapsort swaps the maximum into `A[i]` and shrinks `heap_size`, but `max_heapify` still
looks at the whole list, so it happily pulls the just-placed maximum back into the heap region on
the next sift. The "sorted" tail is repeatedly disturbed. The priority queue never has a sorted tail
(`heap_size == len(A)` always, and `pop()` physically removes the last element), so bug 1 is invisible
there.

Bug 2: heapifying node *i* assumes its subtrees are already heaps. Visiting 0 first sifts the root
down through subtrees that have not yet been fixed, so the largest keys deep in the tree never
reach the top. The queue in `main` happens to drain correctly because `increase_key`, `insert` and
successive `extract_max` calls repair the structure enough; a different input set would expose it.

## The Concept This Illustrates

The heap is a *logical* structure on a prefix `A[0..heap_size-1]` of a physical array, and the
bottom-up build works only because MAX-HEAPIFY's precondition ("both children are heaps") is
established by processing nodes in decreasing index order. Both bugs come from treating "the heap"
as synonymous with "the list".

## The Correction

```python
# before
if l < len(A) and A[l] > A[largest]:
if r < len(A) and A[r] > A[largest]:
...
for i in range(0, n // 2):

# after
if l < heap_size and A[l] > A[largest]:
if r < heap_size and A[r] > A[largest]:
...
for i in range(n // 2 - 1, -1, -1):
```

## Instructor Notes

- Fixing only `heap_size` still yields wrong heapsort output (because the initial build is not a
  heap); fixing only the loop still yields wrong output (the tail is disturbed). Students should
  see that each fix alone changes the garbage but does not remove it, which is a good lesson in not
  stopping at "the output changed".
- Some students pass `len(A)` explicitly at every call site and delete the parameter; ask how
  heapsort could then ever work.
- Ask why the queue output was correct despite bug 2, and whether "the tests pass" is the same as
  "the invariant holds". Have them print `pq._A` right after construction and check the heap
  property by hand.
