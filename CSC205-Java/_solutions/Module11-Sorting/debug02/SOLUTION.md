# Solution: Insertion Sort of Daily Temperatures

**Course/Module/Activity:** CSC205 · Module 11 Sorting · debug02
**Bug type(s):** boundary, runtime
**Bug count:** 1

## Observed Behavior

```
Before: [72, 65, 80, 71, 68]
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index -1 out of bounds for length 5
	at InsertionSort.sort(InsertionSort.java:9)
	at InsertionSort.main(InsertionSort.java:31)
```

## The Bug(s)

`InsertionSort.java`, `sort`, the inner `while` condition:

```java
while (a[j] > key && j >= 0) {
```

The array access is evaluated *before* the bounds check.

## Why the Program Behaved Incorrectly

`i = 1`, `key = 65`, `j = 0`: `a[0] = 72 > 65` → shift, `j = -1`. The loop re-tests its condition: `a[-1]` is evaluated first and throws `ArrayIndexOutOfBoundsException` before `j >= 0` is ever consulted. Because `&&` short-circuits left to right, the guard only protects what comes *after* it. Any time the key must slide all the way to the front, `j` reaches `-1` and the program crashes.

## The Concept This Illustrates

Boundary conditions in insertion sort: the inner loop must stop either when it finds a value not larger than the key *or* when it runs off the front of the array — and the second test has to be checked first, because the first test cannot be asked safely once `j` is out of range. This is the canonical example of why short-circuit evaluation order is part of correctness, not just efficiency.

## The Correction

```java
// before
while (a[j] > key && j >= 0) {
// after
while (j >= 0 && a[j] > key) {
```

## Instructor Notes

- Some students "fix" this by starting `j` at `i - 1` and adding `if (j < 0) break;` inside the loop body. It works but it is clumsy; ask them why the condition itself cannot simply be reordered.
- Others change the loop to `while (j > 0 && a[j] > key)`. That never examines `a[0]`, so a key smaller than the first element is inserted at position 1. Run it on the second array: the 44 will land in the wrong place. Good discussion of the difference between `> 0` and `>= 0`.
- Ask: "Would this bug show up on `[58, 61, 49, 55, 44, 60]` alone?" (Yes — 49 slides past 58 to the front.) "On `[1, 2, 3]`?" (No — nothing ever slides to `j = -1`.) This is a good moment to talk about why sorted input is a weak test case.
- In C++ the same expression is undefined behavior that usually reads garbage silently; Java's exception is a gift.
