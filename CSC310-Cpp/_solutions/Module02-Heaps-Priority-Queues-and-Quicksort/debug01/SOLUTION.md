# Solution: Max-Priority Queue on a Binary Heap

**Course/Module/Activity:** CSC310 · Module 2 Heaps, Priority Queues, and Quicksort · debug01
**Bug type(s):** logic (index arithmetic)
**Bug count:** 1 (child-index formulas; `left` and `right` are both off)

## Observed Behavior

```
...
insert 24  (max is now 31)
extract order: 31 24 27 15 20 12 8 5 3
```

The inserts look fine, but the extraction order is not decreasing: 24 comes out before 27 and 15 before 20.

## The Bug(s)

`max_heap_pq.cpp`, `MaxHeapPQ::left` and `MaxHeapPQ::right`:

```cpp
static std::size_t parent(std::size_t i) { return (i - 1) / 2; }
static std::size_t left(std::size_t i)   { return 2 * i; }
static std::size_t right(std::size_t i)  { return 2 * i + 1; }
```

`parent` uses the 0-based formula but `left`/`right` use the 1-based CLRS formulas (LEFT = 2i, RIGHT = 2i + 1).

## Why the Program Behaved Incorrectly

`insert` only uses `parent`, which is correct, so the heap built by inserts is valid and `maximum` is always right. `extractMax` calls `maxHeapify(0)`, which computes `left(0) = 0` (the node itself) and `right(0) = 1`; index 2 is never treated as a child of the root. When the larger child sits at index 2, the root is not swapped down and the heap property is silently broken. Deeper nodes are also wrong: node 2's children are computed as 4 and 5 instead of 5 and 6. Each subsequent `extractMax` therefore returns whatever happens to be at the root, which is no longer guaranteed to be the maximum.

## The Concept This Illustrates

The implicit tree layout depends on a consistent indexing convention. CLRS's PARENT(i) = ⌊i/2⌋, LEFT(i) = 2i, RIGHT(i) = 2i + 1 are for 1-based arrays; in a 0-based `std::vector` they become ⌊(i−1)/2⌋, 2i + 1, 2i + 2. Mixing the two conventions produces a structure where "parent of child of i" is not i, so the heap property maintained on the way up is not the one checked on the way down. Students holding this bug typically have not verified the formulas against a drawn tree.

## The Correction

```cpp
static std::size_t left(std::size_t i)  { return 2 * i + 1; }
static std::size_t right(std::size_t i) { return 2 * i + 2; }
```

## Instructor Notes

- Ask students to verify `parent(left(i)) == i` and `parent(right(i)) == i` for i = 0, 1, 2 with both sets of formulas; the mismatch is immediate.
- Some students will "fix" `parent` to `i / 2` instead, making everything 1-based while the root lives at index 0. Have them trace `insert` for the second key: `parent(1) = 0` still works by luck, but `parent(2) = 1` is wrong.
- Extension: why do all nine inserts still report the correct maximum even though `maxHeapify` is broken? (It is never called until an extraction.)
