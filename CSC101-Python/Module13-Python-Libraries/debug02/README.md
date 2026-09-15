# Birthday Facts

**Course:** CSC101 &nbsp;|&nbsp; **Module 13:** Python Libraries &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

Using the `datetime` module, the program reads a birth year, month, and day, then reports the
weekday the user was born on and how many days old they were on January 1, 2026.

## Expected Behavior

```
Birth year (e.g., 2005): 2005
Birth month (1-12): 3
Birth day (1-31): 25

You were born on a Friday.
On January 1, 2026 you were 7587 days old.
That is about 20.8 years.
```

## How to Run

```bash
python3 birthday_facts.py
```

Type `2005`, `3`, and `25`, pressing Enter after each.

## Your Task

Run the program with the sample birthday and compare with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* Look up the `date` constructor in the `datetime` documentation. In what order does it expect
  its arguments?
* The program asks the user for the values in a sensible order. Does that order have to match the
  order the library wants?
* Try the birthday `2005`, `3`, `7`. The program runs without complaint — is the answer right? Why
  is that case more dangerous than the one that stops the program?
