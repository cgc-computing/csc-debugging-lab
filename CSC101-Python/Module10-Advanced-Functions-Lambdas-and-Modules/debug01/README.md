# Top Scorers

**Course:** CSC101 &nbsp;|&nbsp; **Module 10:** Advanced Functions, Lambdas, and Modules &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program holds a list of `(name, score)` tuples, sorts the students by score using
`sorted()` with a `lambda` key, and prints the three highest scorers from first place to third.

## Expected Behavior

```
Top 3 scorers
-------------
1. Fatima    99
2. Ben       95
3. Dev       91
```

## How to Run

```bash
python3 top_scorers.py
```

No input is required.

## Your Task

Run the program and compare the three names with the Expected Behavior. This program contains one
or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why*
the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

* What does the `key` function tell `sorted()` to do, and what does it *not* control?
* In what order does `sorted()` arrange values by default? Which end of the sorted list holds the
  highest score?
* Look up the keyword arguments that `sorted()` accepts. Which one changes the direction of the
  result?
