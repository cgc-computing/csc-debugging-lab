# Solution: Quiz Scores with Input Checking

**Course/Module/Activity:** CSC101 · Module 7 Loops Part 2: Nested Loops and Exceptions · debug02  
**Bug type(s):** conceptual/design (exception-handler placement) / logic  
**Bug count:** 1

## Observed Behavior

```
Enter quiz score 1: 90
Enter quiz score 2: abc
That is not a whole number. Try again.

Scores entered: 1
Average: 90.0
```

The message prints, but the program never asks again; it reports an "average" of one score.

## The Bug(s)

`quiz_scores.py`, lines 9–15: the `try` wraps the *entire* `while` loop. When `int("abc")`
raises `ValueError`, control leaves the `try` block — and therefore leaves the loop — jumps to the
`except` clause, prints the message, and then continues with the code *after* the whole
`try/except`.

## Why the Program Behaved Incorrectly

An exception unwinds out of the `try` block to the nearest matching handler. Because the loop
lives inside that block, the loop is abandoned along with it. Nothing brings execution back to
the `while` condition, so the remaining prompts never occur and `count` stays at 1.

## The Concept This Illustrates

Where you place `try/except` determines what gets skipped when something goes wrong. To recover
and repeat, the handler must be *inside* the loop so that the loop condition is re-evaluated after
the message. This is the standard "validated input" pattern.

## The Correction

```python
# before
try:
    while count < scores_needed:
        entry = input(...)
        score = int(entry)
        ...
except ValueError:
    print("That is not a whole number. Try again.")
# after
while count < scores_needed:
    entry = input(...)
    try:
        score = int(entry)
        total = total + score
        count = count + 1
    except ValueError:
        print("That is not a whole number. Try again.")
```

## Instructor Notes

* Ask what would happen if the *first* entry were `abc` in the original program
  (`ZeroDivisionError` on the average line). It demonstrates why the count matters.
* Some students wrap only `score = int(entry)` in the `try` and leave the two accumulation lines
  after the `try/except`; then a bad entry still adds the *previous* `score` again. Have them trace
  `total` after the `abc` entry.
* Discuss whether a bare `except:` would be acceptable here and what it would hide (for example,
  `Ctrl+C`).
