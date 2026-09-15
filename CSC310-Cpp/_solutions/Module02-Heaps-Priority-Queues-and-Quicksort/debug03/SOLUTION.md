# Solution: Quicksort with Lomuto Partition

**Course/Module/Activity:** CSC310 · Module 2 Heaps, Priority Queues, and Quicksort · debug03
**Bug type(s):** boundary, runtime
**Bug count:** 2 related (both misplace the pivot's index by one)

## Observed Behavior

```
input:  2 8 7 1 3 5 6 4 
output: 1 2 4 3 5 7 6 8 
NOT SORTED  (partition calls: 5)

input:  13 19 9 5 12 8 7 4 21 2 6 11 
libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
```

The first test comes out mis-ordered; the second aborts with an `out_of_range` exception (the program uses `.at()`, so the bad index is reported rather than silently reading past the end). Exit status 134.

## The Bug(s)

`quicksort.cpp`, function `partition`:

```cpp
for (int j = p; j <= r; ++j) {        // should stop before r
    if (a.at(j) <= pivot) { ++i; std::swap(a.at(i), a.at(j)); }
}
std::swap(a.at(i + 1), a.at(r));
return i;                             // should be i + 1
```

## Why the Program Behaved Incorrectly

The loop is supposed to scan `a[p..r-1]` and leave the pivot at `a[r]` untouched until the final swap. Including `j == r` compares the pivot with itself (`pivot <= pivot` is true), increments `i`, and swaps the pivot into position `i`. The final `swap(a[i+1], a[r])` then moves some other element to a spot that is no longer the pivot's, and when every element is ≤ the pivot, `i + 1 == r + 1` is past the end, which is the `out_of_range` seen on the second test.

Returning `i` instead of `i + 1` reports the wrong pivot position: the recursion `quicksort(p, q-1)` and `quicksort(q+1, r)` then leaves the element at `q` (which is not the pivot) unsorted and includes the pivot in the right-hand recursion. That is why the first test terminates but produces `... 4 3 ... 7 6 ...`.

## The Concept This Illustrates

Lomuto partition maintains the loop invariant of CLRS §7.1: `a[p..i]` ≤ pivot, `a[i+1..j-1]` > pivot, `a[r]` is the pivot. Both bugs violate the third clause—one by disturbing the pivot during the scan, one by mis-reporting where it finally lands. Quicksort's correctness argument depends on the returned index `q` being exactly the pivot's position so the recursion can exclude it; students who see `return i` as "just returning the boundary" have not connected the invariant to the recursive structure.

## The Correction

```cpp
for (int j = p; j < r; ++j) {
    if (a.at(j) <= pivot) {
        ++i;
        std::swap(a.at(i), a.at(j));
    }
}
std::swap(a.at(i + 1), a.at(r));
return i + 1;
```

## Instructor Notes

- Fixing only `j < r` still leaves the first test wrong (pivot included in the recursion); fixing only `return i + 1` still throws on the second test. Ask students to predict which symptom each partial fix removes.
- Some students "fix" the exception by clamping the index or by recursing on `quicksort(q, r)`. The latter recurses forever when `q == p` (stack overflow); discuss why the pivot must be excluded for the recursion to shrink.
- Good follow-up: the all-equal test `5 5 5 1 5 2`—what partition sizes does Lomuto produce when many keys equal the pivot, and what does that do to the running time?
