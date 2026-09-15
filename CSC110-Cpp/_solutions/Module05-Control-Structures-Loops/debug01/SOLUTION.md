# Solution: Sum From 1 to N

**Course/Module/Activity:** CSC110 · Module 5 Control Structures: Loops · debug01
**Bug type(s):** boundary (off-by-one)
**Bug count:** 1

## Observed Behavior

With input `5`:

```
After adding 1, the sum is 1
After adding 2, the sum is 3
After adding 3, the sum is 6
After adding 4, the sum is 10
The sum of 1 through 5 is 10
```

The loop stops one short; `5` is never added.

## The Bug(s)

`sum_to_n.cpp`, `main`, the loop header:

```cpp
for (int i = 1; i < n; i++)
```

The continuation condition excludes `n` itself.

## Why the Program Behaved Incorrectly

The loop runs while `i < n`. When `i` becomes `5`, `5 < 5` is false and the loop exits before the
body executes for `i = 5`. The body runs for `i = 1, 2, 3, 4` — four times, not five. The final
message still reports "1 through 5" because it prints `n`, not the last value added.

## The Concept This Illustrates

Loop boundaries: `<` versus `<=` decides whether the upper limit is included. Students who have
practiced zero-based counting (`for (i = 0; i < n; ...)` runs `n` times) often carry `<` into a
loop that starts at 1 and must include `n`.

## The Correction

```cpp
// before
for (int i = 1; i < n; i++)

// after
for (int i = 1; i <= n; i++)
```

## Instructor Notes

- Some students change the start to `i = 0` or the limit to `n + 1`; both give the right sum.
  Ask them to check the trace lines: with `i = 0` the first line reads "After adding 0", which
  does not match the Expected Behavior.
- Ask: for what value of `n` does the original program give the correct total? (Only `n = 0`,
  where both versions print 0. Also ask what happens with `n = 1`.)
- Follow-up: how would you count the iterations of `for (int i = a; i <= b; i++)` in general?
