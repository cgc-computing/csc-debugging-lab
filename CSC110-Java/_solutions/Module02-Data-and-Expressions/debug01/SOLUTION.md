# Solution: Test Score Average

**Course/Module/Activity:** CSC110 · Module 2 Data and Expressions · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

The total is correct but the average has lost its fractional part:

```
Total points: 274
Average score: 91.0
```

## The Bug(s)

`TestAverage.java`, in `main`:

```java
double average = total / 3;
```

Both operands are `int`, so `/` performs integer division (274 / 3 = 91). The truncated result is then widened to a `double` and stored as 91.0.

## Why the Program Behaved Incorrectly

Java chooses the kind of division from the operand types, not from the variable receiving the result. `total` is an `int` and `3` is an `int` literal, so the quotient is the `int` 91. Assigning it to `double average` converts 91 to 91.0 after the fraction is already gone.

## The Concept This Illustrates

Integer division and the order in which type conversion happens. The declared type of the destination variable does not "reach into" the expression; conversions happen when a value is actually assigned or when operands are mixed.

## The Correction

```java
// before
double average = total / 3;

// after
double average = total / 3.0;          // or: (double) total / 3
```

## Instructor Notes

- Students frequently try `(double) (total / 3)`; ask them to predict its output before running it. The cast applies after the division has already truncated.
- Another correct fix is to declare `total` as a `double`. Ask what happens to the `Total points:` line in that case (it prints `274.0`) and whether that is acceptable.
- Ask why the sample uses 88, 91, 95: with 90, 90, 90 the bug is invisible. This is a good introduction to choosing test data that can expose a problem.
