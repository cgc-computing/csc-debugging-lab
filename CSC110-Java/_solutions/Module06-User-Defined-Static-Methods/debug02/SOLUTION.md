# Solution: Exam Score Curve

**Course/Module/Activity:** CSC110 · Module 6 User-Defined Static Methods · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

The curve has no effect:

```
Raw exam score: 82
Raw score:    82
Curved score: 82
```

## The Bug(s)

`ScoreCurve.java`: `applyCurve` is a `void` method that modifies its own parameter and returns nothing; `main` calls `applyCurve(score);` expecting its `score` variable to change.

```java
applyCurve(score);
...
public static void applyCurve(int score) {
    score = score + CURVE_POINTS;
    ...
}
```

## Why the Program Behaved Incorrectly

Java passes arguments by value. When `main` calls `applyCurve(score)`, the method's parameter `score` is a brand-new variable initialized with a copy of 82. The method adds 5 to *its* copy (87), caps it, and then returns; the copy is destroyed. `main`'s `score` was never involved and still holds 82.

## The Concept This Illustrates

Pass-by-value for primitive types. A method cannot reach back and change the caller's `int` variable, no matter what the parameter is named. The only way for a method to hand back a new primitive value is to `return` it, and the caller must store it (compare debug01 in this module).

## The Correction

```java
// before
applyCurve(score);
...
public static void applyCurve(int score) {
    score = score + CURVE_POINTS;
    if (score > MAX_SCORE) {
        score = MAX_SCORE;
    }
}

// after
score = applyCurve(score);
...
public static int applyCurve(int score) {
    score = score + CURVE_POINTS;
    if (score > MAX_SCORE) {
        score = MAX_SCORE;
    }
    return score;
}
```

## Instructor Notes

- Students frequently believe that giving the parameter the *same name* as the caller's variable links them. Have them rename the parameter to `raw` and observe that nothing changes.
- A wrong "fix" is to make `score` a `static` field of the class so the method can modify it directly. It works but defeats the purpose of parameters; discuss why that is a poor design as programs grow.
- Ask students to test the cap with 98 after the fix (should print 100).
- Later in the course (Module 7+) they will see that object references *do* let a method modify the caller's object; plant the seed now that primitives and objects behave differently here.
