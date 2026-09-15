# Solution: Letter Grade Calculator

**Course/Module/Activity:** CSC110 · Module 4 Control Structures: Conditionals · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

Every score of 60 or more earns a D, and the compliment never appears:

```
Enter the final score (0-100): 85
Score 85 earns a grade of D
```

Scores below 60 correctly earn an F.

## The Bug(s)

`LetterGrade.java`, in `main`, the `if / else if` chain tests the thresholds in ascending order:

```java
if (score >= 60) {
    grade = 'D';
} else if (score >= 70) {
    grade = 'C';
} else if (score >= 80) {
    grade = 'B';
} else if (score >= 90) {
    grade = 'A';
} else {
    grade = 'F';
}
```

## Why the Program Behaved Incorrectly

An `if / else if` chain stops at the first condition that is true. Any score of 60 or above satisfies `score >= 60`, so the first branch runs and the rest are skipped. The branches for C, B, and A are unreachable in practice because every score that would satisfy them already satisfied the first test.

## The Concept This Illustrates

Mutually exclusive branches and the significance of ordering when conditions overlap. Because each test is only a *lower* bound, the tests must be arranged from most restrictive (highest threshold) to least restrictive. Students often think of each `else if` as independent rather than as "only if all of the previous were false."

## The Correction

```java
// before                         // after
if (score >= 60) {                if (score >= 90) {
    grade = 'D';                      grade = 'A';
} else if (score >= 70) {         } else if (score >= 80) {
    grade = 'C';                      grade = 'B';
} else if (score >= 80) {         } else if (score >= 70) {
    grade = 'B';                      grade = 'C';
} else if (score >= 90) {         } else if (score >= 60) {
    grade = 'A';                      grade = 'D';
} else {                          } else {
    grade = 'F';                      grade = 'F';
}                                 }
```

## Instructor Notes

- An alternative fix is to keep the order and make each condition a range (`score >= 60 && score < 70`, ...). It works; ask which version is easier to get right and why the original order then becomes irrelevant.
- Ask students to test the boundaries 59, 60, 69, 70, 89, 90 after fixing.
- Some students reorder only the first two branches and stop when 85 works. Have them test 92.
