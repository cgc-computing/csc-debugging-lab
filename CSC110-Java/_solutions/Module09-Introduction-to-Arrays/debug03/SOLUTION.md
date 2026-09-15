# Solution: Reverse an Array in Place

**Course/Module/Activity:** CSC110 · Module 9 Introduction to Arrays · debug03
**Bug type(s):** logic, boundary
**Bug count:** 1

## Observed Behavior

The "reversed" array is identical to the original:

```
Original: 3, 8, 12, 5, 21, 7
Reversed: 3, 8, 12, 5, 21, 7
```

## The Bug(s)

`ReverseArray.java`, in `reverse`:

```java
for (int i = 0; i < arr.length; i++) {
```

The loop walks the entire array instead of stopping at the midpoint.

## Why the Program Behaved Incorrectly

Each iteration swaps `arr[i]` with `arr[length - 1 - i]`. For i = 0, 1, 2 the array becomes fully reversed: `7, 21, 5, 12, 8, 3`. But the loop continues with i = 3, 4, 5, which swap the *same three pairs again* in reverse order (index 3 with 2, 4 with 1, 5 with 0), undoing every swap. Six swaps of three pairs put everything back where it started.

## The Concept This Illustrates

Two-index (front/back) algorithms only need to process half the array; each iteration handles two positions. The bug is a symmetry error rather than a simple off-by-one, and hand-tracing after each iteration exposes it immediately. It also shows that a loop running "too long" can silently produce the *original* data rather than a crash.

## The Correction

```java
// before
for (int i = 0; i < arr.length; i++) {

// after
for (int i = 0; i < arr.length / 2; i++) {
```

## Instructor Notes

- Ask students to test with an odd-length array such as `{1, 2, 3, 4, 5}` after fixing. `length / 2` is 2, so the middle element is never touched — is that correct? (Yes; it swaps with itself in the original version.)
- Some students propose `i < arr.length - 1 - i` as the condition; it works, and comparing it with `length / 2` is a good exercise.
- A wrong "fix" some students try is to copy into a new array — correct output, but it violates the in-place requirement in the README; ask why the requirement exists (memory).
- Students may be surprised that printing "Reversed" shows the original. Use this to emphasize that a wrong result can *look* like "nothing happened."
