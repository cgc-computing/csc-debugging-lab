# Curried Adders

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** Higher-Order Functions, Pairs, and Currying &nbsp;|&nbsp; **Activity:** debug02
**Language:** Scheme (R5RS, DrRacket)

## Goal

`add` is a *curried* adder: it takes one number and returns a procedure that adds that number to whatever it is given. `add5` is built from it. `add-to-all` adds a number to every element of a list, and `total-with-bonus` adds a bonus to every score and returns the grand total.

## Expected Behavior

```scheme
> ((add 3) 4)
7
> (add5 10)
15
> (add-to-all 10 '(1 2 3))
(11 12 13)
> (total-with-bonus 5 '(80 90 70))
255
```

## How to Run

Open `curried-adders.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (total-with-bonus 5 '(80 90 70))) (newline)` at the bottom of the file and run

```bash
plt-r5rs curried-adders.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i curried-adders.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine.

## Think About

- How many parameters does `add` have? What does `add` *return*, and how many parameters does that returned value have?
- `add-to-all` works. Look at exactly how it uses `add`. Now compare with how `total-with-bonus` uses it.
- Read the error message: which procedure is complaining, how many arguments did it expect, and how many did it get?
