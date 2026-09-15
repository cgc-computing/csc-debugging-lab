# Exam Score Curve

**Course:** CSC110 &nbsp;|&nbsp; **Module 6:** User-Defined Static Methods &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

The program reads a raw exam score and applies a curve: every score goes up by 5 points, but no score may exceed 100. It prints the raw score and the curved score. The curving is done by a helper method `applyCurve`.

## Expected Behavior

```
Raw exam score: 82
Raw score:    82
Curved score: 87
```

A raw score of `98` should give a curved score of `100`.

## How to Run

```bash
javac ScoreCurve.java
java ScoreCurve
```

Type a whole number and press Enter. Use `82` to reproduce the sample run, then try `98`.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. You may change the method's signature if you need to.

## Think About

- Inside `applyCurve`, the parameter `score` is changed. Which variable does that change affect: the one in `applyCurve`, the one in `main`, or both?
- When `main` calls `applyCurve(score)`, what exactly is handed to the method: the variable itself or its value?
- If a method computes something the caller needs, how should the method deliver it?
