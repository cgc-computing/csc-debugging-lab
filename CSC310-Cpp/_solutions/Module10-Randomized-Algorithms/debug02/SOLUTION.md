# Solution: Randomized Quicksort

**Course/Module/Activity:** CSC310 · Module 10 Randomized Algorithms · debug02
**Bug type(s):** logic (state: the chosen pivot is never moved into the position PARTITION expects)
**Bug count:** 1

## Observed Behavior

```
input:  2 8 7 1 3 5 6 4
output: 2 1 5 3 6 4 7 8
NOT SORTED  (partition calls: 5)

input:  13 19 9 5 12 8 7 4 21 2 6 11
output: 4 2 11 5 8 7 12 6 13 9 21 19
NOT SORTED  (partition calls: 7)
...
input:  1 2 3 4 5 6 7 8 9 10
output: 1 2 6 4 3 5 10 8 7 9
NOT SORTED  (partition calls: 5)
```

Every array comes out scrambled (exact arrangements depend on the standard library's distribution code). The program never crashes and always terminates.

## The Bug(s)

`randomized_quicksort.cpp`, `randomizedPartition`:

```cpp
int p = pick(rng);
int pivot = a.at(p);
int i = lo - 1;
for (int j = lo; j < hi; ++j) { ... compare with pivot ... }
std::swap(a.at(i + 1), a.at(hi));
return i + 1;
```

The random position `p` is used only to *read* the pivot value. CLRS's RANDOMIZED-PARTITION first exchanges `A[p]` with `A[r]` so that PARTITION's assumption—the pivot is the last element—holds.

## Why the Program Behaved Incorrectly

The Lomuto loop compares every element except `a[hi]` against `pivot`, moving the small ones to the front. That part is fine. But the final `swap(a[i + 1], a[hi])` is supposed to put the *pivot* between the two groups; here `a[hi]` is an arbitrary element (whatever happened to be last), so a possibly large value is placed at index `i + 1` and reported as "in its final position". The actual pivot value, still somewhere in the low group, is also left unsorted relative to its neighbors. The recursion then trusts the returned index, never revisits it, and the misplaced element stays wrong forever. Termination is unaffected because `i + 1` is always within `[lo, hi]` and both recursive calls exclude it.

## The Concept This Illustrates

Randomizing an algorithm means changing *which* choices are made, not skipping the bookkeeping the deterministic version relies on. PARTITION's correctness (and the loop invariant CLRS proves) depends on the pivot occupying `A[r]` during the scan and being swapped into the boundary at the end. Choosing a random pivot *value* without moving the pivot *element* breaks that invariant: the value used for comparisons and the element placed at the boundary are no longer the same object. Students often think of the pivot as a number; PARTITION treats it as a position.

## The Correction

```cpp
int p = pick(rng);
std::swap(a.at(p), a.at(hi));
int pivot = a.at(hi);
```

## Instructor Notes

- Some students "fix" the symptom by swapping `a[p]` into place at the end (`swap(a[i+1], a[p])`). Ask what happens when `p` was moved during the scan—`a[p]` no longer holds the pivot.
- Others switch to `pivot = a.at(hi)` and drop the random choice entirely. That sorts correctly but throws away the randomization; ask them what the already-sorted 10-element input would cost with n = 100 000 and a fixed last-element pivot.
- The duplicate-heavy input (`5 5 5 1 5 2`) is a good place to discuss why Lomuto uses `<=` and why equal keys still sort correctly.
- The partition-call counts differ between the buggy and fixed versions even with the same seed, because the swap changes which element the next random draw lands on. That is a nice illustration that "same seed" does not mean "same behavior" once the algorithm differs.
