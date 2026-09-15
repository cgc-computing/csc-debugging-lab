# Solution: Max-Heap in a Python List

**Course/Module/Activity:** CSC310 · Module 2 Heaps, Priority Queues, and Quicksort · debug01
**Bug type(s):** boundary (index arithmetic)
**Bug count:** 1 (one misconception expressed in two helper functions)

## Observed Behavior

```
bottom-up build   : [16, 14, 9, 10, 8, 11, 4, 2, 3, 7, 1]
extract order     : [16, 14, 10, 9, 11, 8, 7, 4, 3, 2, 1]
descending order? : False

built by insertion: [16, 14, 10, 8, 11, 3, 9, 1, 4, 2, 7]
extract order     : [16, 14, 10, 11, 8, 9, 7, 4, 3, 2, 1]
descending order? : False
```

Both extraction sequences are out of order; 11 comes out after 10 (and after 9 in the first run).

## The Bug(s)

`max_heap.py`, helper functions `left` and `right`:

```python
def left(i):
    return 2 * i

def right(i):
    return 2 * i + 1
```

These are CLRS's 1-based formulas. `parent` was written correctly for 0-based indexing,
`(i - 1) // 2`, so the two directions of tree navigation disagree.

## Why the Program Behaved Incorrectly

With `left(0) == 0`, the root is its own left child, and node `i`'s children are `2i` and `2i+1`
instead of `2i+1` and `2i+2`. `max_heapify` therefore compares each node with the wrong pair of
positions, so "sifting down" leaves the real children unchecked. In the bottom-up build, the loop
`range(n // 2 - 1, -1, -1)` only visits indices 0..4, but under the wrong formulas index 5 has a child
(index 10, holding 1) that is never heapified. In the insertion run, `heap_insert` bubbles keys up
along the correct parent chain, so the list *is* a valid heap; `extract_all` then sifts down along
the wrong child chain and destroys the order (11 is compared against the wrong nodes and left behind).

## The Concept This Illustrates

A heap's shape is entirely implicit in index arithmetic. The three navigation functions must be
mutually consistent (`parent(left(i)) == parent(right(i)) == i`) and consistent with the array's
base index. Translating CLRS's 1-based formulas to 0-based lists requires shifting *all* of them:
`left = 2i + 1`, `right = 2i + 2`, `parent = (i - 1) // 2`. Students who "fix" only one function
trade one inconsistency for another.

## The Correction

```python
# before
def left(i):  return 2 * i
def right(i): return 2 * i + 1
# after
def left(i):  return 2 * i + 1
def right(i): return 2 * i + 2
```

## Instructor Notes

- A tempting alternative is to change `parent` to `i // 2` so it matches the children. That makes the
  three functions self-consistent (index 0 with a single child at index 1), and the program will
  actually produce correct extraction order! Ask those students what shape the tree has, whether
  BUILD-MAX-HEAP's loop bound `n // 2 - 1` is still right for that shape, and whether the heap is
  still "nearly complete". Then have them test with 12 keys.
- Another partial fix changes only `left`; extraction is still wrong because `right(i)` then
  collides with `left(i)`.
- Good follow-up: ask students to write a `check_heap(A)` that does not reuse `left`/`right`.
