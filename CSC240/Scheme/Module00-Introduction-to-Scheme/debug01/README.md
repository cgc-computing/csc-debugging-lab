# Geometry Helpers

**Course:** CSC240 &nbsp;|&nbsp; **Module 0:** Introduction to Scheme &nbsp;|&nbsp; **Activity:** debug01
**Language:** Scheme (R5RS, DrRacket)

## Goal

The file defines five small numeric procedures: `square`, `average`, `fahrenheit->celsius`, `hypotenuse` (the long side of a right triangle from its two short sides), and `distance` (how far apart two numbers are). It is the kind of warm-up file you write on the first day with a new language.

## Expected Behavior

After clicking **Run**, typing each call in the Interactions window gives the result shown:

```scheme
> (square 5)
25
> (average 6 10)
8
> (average 7 10)
17/2
> (fahrenheit->celsius 212)
100
> (hypotenuse 3 4)
5
> (distance 3 10)
7
```

(`17/2` is not a mistake: Scheme keeps exact fractions unless you ask for decimals.)

## How to Run

Open `geometry-helpers.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (hypotenuse 3 4)) (newline)` at the bottom of the file and run

```bash
plt-r5rs geometry-helpers.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i geometry-helpers.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine.

## Think About

- In Scheme, what does a pair of parentheses *mean*? What does the evaluator do with the first thing inside them?
- Read the error message word by word. What was Scheme trying to do, and with what value?
- Java lets you write `(a)` around a variable just for grouping. Why is that not harmless in Scheme?
