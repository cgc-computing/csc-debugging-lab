# Solution: Tallest Student

**Course/Module/Activity:** CSC110 · Module 9 Introduction to Arrays · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

The heights print correctly, but the tallest student is always the first one:

```
Tallest student: Jordan at 66 inches
```

## The Bug(s)

`TallestStudent.java`, in `main`, inside the search loop:

```java
if (heights[i] > tallestHeight) {
    tallestHeight = heights[i];
}
```

`tallestIndex` is never updated when a new maximum is found.

## Why the Program Behaved Incorrectly

The loop does correctly track the largest *value* in `tallestHeight` (74 at the end). But the final output uses `tallestIndex`, which was initialized to 0 and never changed, so it prints `names[0]` and `heights[0]`. The variable that the output depends on is not the variable the loop maintains.

## The Concept This Illustrates

Finding the *position* of an extreme value, not just the value — the essential pattern for parallel arrays, where the index is the link between related arrays. Students often track the value because it is what they "see" and forget that the position is the actual answer. The invariant `tallestHeight == heights[tallestIndex]` must hold after every iteration.

## The Correction

```java
// before
if (heights[i] > tallestHeight) {
    tallestHeight = heights[i];
}

// after
if (heights[i] > tallestHeight) {
    tallestHeight = heights[i];
    tallestIndex = i;
}
```

## Instructor Notes

- An equivalent fix drops `tallestHeight` entirely and compares `heights[i] > heights[tallestIndex]`. Ask students which version is cleaner and whether both variables are needed.
- Ask what happens if two students tie for tallest. With `>` the first one wins; with `>=` the last one does. Which is "correct" is a good discussion about specifications.
- Students who change the output to print `tallestHeight` will get "74 inches" with the wrong name; use this to show that the name is the whole point.
