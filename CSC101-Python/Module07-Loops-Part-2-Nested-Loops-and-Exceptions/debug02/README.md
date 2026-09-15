# Quiz Scores with Input Checking

**Course:** CSC101 &nbsp;|&nbsp; **Module 7:** Loops Part 2: Nested Loops and Exceptions &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

The program collects exactly three quiz scores. If the user types something that is not a whole
number, the program prints a short message and asks for that score again. Once three valid scores
have been entered it prints how many were entered and their average.

## Expected Behavior

```
Enter quiz score 1: 90
Enter quiz score 2: abc
That is not a whole number. Try again.
Enter quiz score 2: 80
Enter quiz score 3: 70

Scores entered: 3
Average: 80.0
```

## How to Run

```bash
python3 quiz_scores.py
```

Type `90`, then `abc`, then `80`, then `70`, pressing Enter after each.

## Your Task

Run the program with the sample input and compare with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* When an exception is raised inside a `try` block, where does Python continue running after the
  matching `except` block finishes?
* The program is supposed to recover from a bad entry and keep looping. For that to happen, what
  has to be *inside* the loop?
* How many scores did the original program actually collect before it printed the average?
