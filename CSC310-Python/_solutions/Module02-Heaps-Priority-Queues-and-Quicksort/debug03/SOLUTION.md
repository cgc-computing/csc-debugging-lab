# Solution: Quicksort With Lomuto Partition

**Course/Module/Activity:** CSC310 · Module 2 Heaps, Priority Queues, and Quicksort · debug03
**Bug type(s):** boundary (off-by-one in the returned index)
**Bug count:** 1

## Observed Behavior

```
[13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11]
  -> [2, 5, 7, 8, 4, 9, 6, 11, 12, 13, 19, 21]   correct: False
[2, 8, 7, 1, 3, 5, 6, 4]
  -> [1, 2, 3, 4, 5, 7, 6, 8]   correct: False
[10, 80, 30, 90, 40, 50, 70]
  -> [10, 30, 40, 50, 70, 80, 90]   correct: True
[3, 3, 1, 2, 3, 1]
  -> [1, 1, 2, 3, 3, 3]   correct: True

partition of [2, 8, 7, 1, 3, 5, 6, 4] with pivot 4:
  array [2, 1, 3, 4, 7, 5, 6, 8], pivot index 2, A[q] = 3
```

The array after partition is correct, but the reported pivot index is 2 (holding 3) rather than 3.

## The Bug(s)

`quicksort.py`, function `partition`, last line:

```python
A[i + 1], A[r] = A[r], A[i + 1]
return i
```

The pivot is swapped into position `i + 1`, but the function returns `i`.

## Why the Program Behaved Incorrectly

`quicksort` treats the returned index as the pivot's final resting place and excludes it from both
recursive calls. Because the returned index is one too small, the element that is excluded is the
*last element of the <= region*, not the pivot, and the pivot itself is included in the right-hand
recursion. The excluded element is never moved again, so if it is not already in its sorted position
the output is wrong (in the first sample, 4 and 6 are stranded). The right recursion does still
terminate because it contains at least one element (the pivot) that partitions correctly on the
next level. Inputs where every excluded element happens to be in place, such as the third and
fourth samples, sort correctly by luck. If the pivot were the minimum of a subarray, `i` would be
`p - 1` and `quicksort(A, p, r)` would be called again unchanged, giving infinite recursion.

## The Concept This Illustrates

PARTITION's postcondition is what makes quicksort's recursion correct: `A[q]` is the pivot, in its
final position, so the two subproblems are independent and strictly smaller. An off-by-one in `q`
breaks the postcondition while leaving the array itself correctly partitioned, which is why the
printed array "looks right". Students should verify the loop invariant (`A[p..i] <= x`, `A[i+1..j-1]
> x`) and derive the pivot position from it, rather than pattern-matching the pseudocode.

## The Correction

```python
# before
return i
# after
return i + 1
```

## Instructor Notes

- Some students change the recursion to `quicksort(A, p, q)` / `quicksort(A, q + 1, r)` to "include
  the missed element". That includes the pivot's left neighbour and stops excluding anything; it
  terminates only if the pivot is never the maximum of its subarray (otherwise `q == r` and the same
  range recurses forever). Have them try `[10, 80, 30, 90, 40, 50, 70]` with that change.
- Others initialize `i = p` instead of `p - 1`. Ask them to trace the pivot's final position.
- Ask students to construct an input that makes the buggy version recurse infinitely (any subarray
  whose last element is its minimum, e.g., `[5, 3]`).
