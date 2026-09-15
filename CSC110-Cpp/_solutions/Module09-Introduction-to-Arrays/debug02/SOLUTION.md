# Solution: Highest Bowling Score

**Course/Module/Activity:** CSC110 · Module 9 Introduction to Arrays · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

The highest score is right, but the game number is always 1:

```
Enter 6 game scores: 142 168 155 201 177 190
Highest score: 201
Bowled in game 1
```

## The Bug(s)

`highest_score.cpp`, `main`, inside the `if` in the search loop: only `maxScore` is updated when
a larger score is found. `maxIndex` is initialized to `0` and never changed.

## Why the Program Behaved Incorrectly

The loop correctly discovers `168`, then `201` as new maxima and stores them in `maxScore`, but
the index of the element that produced each new maximum is not recorded. `maxIndex` keeps its
initial value `0`, so the program reports "game 1" regardless of input. The two variables are
supposed to describe the same element, and the invariant `scores[maxIndex] == maxScore` is broken
as soon as the first larger score appears.

## The Concept This Illustrates

When an algorithm tracks a "best so far", every piece of information about that best element
(here its value *and* its position) must be updated together at the moment it changes. The
value-only version is what students write when they think of `max` as the answer and the index as
an afterthought.

## The Correction

```cpp
// before
if (scores[i] > maxScore) {
    maxScore = scores[i];
}

// after
if (scores[i] > maxScore) {
    maxScore = scores[i];
    maxIndex = i;
}
```

## Instructor Notes

- A cleaner alternative tracks only `maxIndex` and compares `scores[i] > scores[maxIndex]`,
  printing `scores[maxIndex]` at the end. Show it after students have fixed the two-variable
  version; ask which one makes the invariant impossible to break.
- Ask what happens with ties (`>` keeps the first occurrence; `>=` would keep the last). Which
  should a bowling report use?
- Ask why the loop starts at `i = 1` rather than `0`.
