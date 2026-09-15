# Solution: Merge Sort

**Course/Module/Activity:** CSC205 · Module 11 Sorting · debug03
**Bug type(s):** logic, boundary
**Bug count:** 1

## Observed Behavior

```
Before: [38, 27, 43, 3, 9, 82, 10]
After:  [3, 9, 0, 0, 27, 38, 43]
Pair:   [1, 2]
Halves: [1, 0, 0, 5, 0, 0]
```

Values go missing, zeros appear, and the result is not sorted.

## The Bug(s)

`MergeSort.java`, `merge`: after the main `while (i <= mid && j <= hi)` loop, only the leftovers of the *left* half are copied into `temp`:

```java
while (i <= mid) {
    temp[k++] = a[i++];
}
// nothing copies a[j..hi] when the right half is the one with leftovers
```

## Why the Program Behaved Incorrectly

The main loop stops as soon as *either* half is exhausted. If the left half runs out first, the remaining right-half elements (`a[j..hi]`) are never written to `temp`, so `temp[k..hi]` keeps whatever it held before — zeros from `new int[n]` the first time that region is used, or stale values from an earlier merge. The copy-back loop then overwrites the correct right-half values in `a` with that junk.

Trace `Halves = [5, 6, 7, 1, 2, 3]`:

- Left half `[5, 6, 7]` is built from `[5]` and `[6, 7]`. Merging `[7]` with `[6]`: the loop takes 6, the *right* half is exhausted, the left-leftover loop copies 7 → `[6, 7]`, correct. Merging `[5]` with `[6, 7]`: the loop takes 5, now the *left* half is exhausted; 6 and 7 are never copied, `temp[1..2]` stays `0, 0`, and the left half becomes `[5, 0, 0]`.
- Right half `[1, 2, 3]` suffers the same fate and becomes `[1, 0, 0]`.
- Final merge of `[5, 0, 0]` with `[1, 0, 0]` yields `[1, 0, 0, 5, 0, 0]`.

`Pair = [2, 1]` sorts correctly because merging `[2]` with `[1]` exhausts the *right* half first, and draining the left half is the one path the code does handle.

## The Concept This Illustrates

The merge step's post-condition is "every element of both halves has been copied exactly once." The main loop guarantees that for the interleaved prefix; the *two* drain loops guarantee it for whichever half is left over. Students who copy the left-half drain and forget its mirror image have internalized "the left half is the one that runs long," which is true only for some inputs. The bug is invisible on inputs where the right half always empties first — which includes many small hand-made test cases.

## The Correction

```java
// before
while (i <= mid) {
    temp[k++] = a[i++];
}
// after
while (i <= mid) {
    temp[k++] = a[i++];
}
while (j <= hi) {
    temp[k++] = a[j++];
}
```

## Instructor Notes

- Ask students where the zeros came from before they fix anything; that question forces them to see that `temp` was never written in those positions.
- Some students notice that copying the right leftovers is technically unnecessary *if* the merge copied back only `temp[lo..k-1]` and left the tail of `a` alone (the right leftovers are already in place). That is a legitimate optimization used in some textbooks — accept it only if the student can explain why the right-half leftovers are already where they belong and the left-half leftovers are not.
- Alternative wrong fix: `while (j < hi)` — drops the last element. Have them re-run; `Halves` will show a stale value in the last slot.
- Follow-up: "Why does `Pair` sort correctly?" is a good entry to the idea that a test passing tells you little unless the test exercises the branch in question.
