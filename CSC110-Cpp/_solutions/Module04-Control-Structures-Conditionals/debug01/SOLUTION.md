# Solution: Letter Grade Converter

**Course/Module/Activity:** CSC110 · Module 4 Control Structures: Conditionals · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

Every passing score becomes a D:

```
Enter a score from 0 to 100: 85
Score: 85
Letter grade: D
```

`93`, `71`, and `64` all print `D`; only `42` correctly prints `F`.

## The Bug(s)

`letter_grade.cpp`, `main`: the `if / else if` chain tests the cutoffs in ascending order
(`>= 60`, then `>= 70`, `>= 80`, `>= 90`). Because each test is a one-sided `>=`, the first
branch captures every score of 60 or more.

## Why the Program Behaved Incorrectly

An `if / else if / else` chain executes the *first* branch whose condition is true and skips the
rest. For `85`, `score >= 60` is true, so `grade = 'D'` runs and the `>= 70`, `>= 80`, `>= 90`
tests are never evaluated. Those later branches are unreachable for any input.

## The Concept This Illustrates

Mutually exclusive branches with overlapping one-sided conditions must be ordered from most
restrictive to least restrictive (highest cutoff first). Students often think of each `else if` as
an independent test rather than as "only if everything above me was false."

## The Correction

```cpp
// before
if (score >= 60)      grade = 'D';
else if (score >= 70) grade = 'C';
else if (score >= 80) grade = 'B';
else if (score >= 90) grade = 'A';
else                  grade = 'F';

// after
if (score >= 90)      grade = 'A';
else if (score >= 80) grade = 'B';
else if (score >= 70) grade = 'C';
else if (score >= 60) grade = 'D';
else                  grade = 'F';
```

## Instructor Notes

- An alternative fix that keeps the ascending order is to use two-sided ranges
  (`score >= 60 && score < 70`). It works; ask which version is easier to read and maintain.
- Some students swap only the letters (`'A'` on the first branch) without reordering the
  cutoffs, producing A for everything above 60. Ask them to test `64`.
- Good follow-up: what does the program do with `score = 105` or `-3`? Should it?
