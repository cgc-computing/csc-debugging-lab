# Solution: Sum of the First n Numbers

**Course/Module/Activity:** CSC110 · Module 5 Control Structures: Loops · debug01
**Bug type(s):** boundary
**Bug count:** 1

## Observed Behavior

```
Enter a positive whole number: 10
Loop total:    45
Formula total: 55
The two totals do NOT agree.
```

The loop total is always short by exactly *n*.

## The Bug(s)

`SumToN.java`, in `main`:

```java
for (int i = 1; i < n; i++) {
```

The loop condition excludes `n` itself.

## Why the Program Behaved Incorrectly

With `i < n`, the loop runs for `i` = 1, 2, ..., 9 and stops as soon as `i` becomes 10. The final term is never added, so the result is 55 − 10 = 45. The difference between the two totals is exactly the missing last term.

## The Concept This Illustrates

Inclusive versus exclusive loop bounds (the classic off-by-one). `i < n` is the right pattern for 0-based counting (`0` to `n-1`, n iterations); when counting starts at 1 and must include n, the condition must be `i <= n`.

## The Correction

```java
// before
for (int i = 1; i < n; i++) {

// after
for (int i = 1; i <= n; i++) {
```

## Instructor Notes

- Some students will "fix" it with `i < n + 1`. That is correct but less readable; ask them to compare it with `<=`.
- Others may change the initialization to `i = 0` — that changes nothing (adds 0) and does not fix the problem; use this to reinforce tracing rather than guessing.
- Ask: if the loop were written `for (int i = 0; i < n; i++)`, what would it be counting? When is that form the right one?
