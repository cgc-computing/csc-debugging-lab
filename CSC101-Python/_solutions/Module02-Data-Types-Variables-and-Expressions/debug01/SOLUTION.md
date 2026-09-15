# Solution: Quiz Average Calculator

**Course/Module/Activity:** CSC101 · Module 2 Data Types, Variables, and Expressions · debug01  
**Bug type(s):** conceptual/design (data types)  
**Bug count:** 1 (the same misconception on three lines)

## Observed Behavior

```
Total points: 858892
Average score: 286297.33
```

No crash; the numbers are just absurd.

## The Bug(s)

`quiz_average.py`, lines 7–9: the three `input()` results are stored as strings and never
converted. Line 11 then "adds" them with `+`, which for strings means concatenation:
`"85" + "88" + "92"` is `"858892"`. Line 12 converts that *string* to the integer 858892 and
divides by 3.

## Why the Program Behaved Incorrectly

`input()` always returns a `str`. The `+` operator is defined for strings as concatenation, so
no error occurs, and the conversion on line 12 happily turns the six-digit string into a number.
The conversion happened, but *after* the arithmetic that needed numbers.

## The Concept This Illustrates

Values have types; the same operator means different things for different types; and type
conversion has to happen *before* the operation that depends on it. "It didn't crash" is not the
same as "it is right."

## The Correction

```python
# before
score1 = input("Enter the first quiz score: ")
...
average = int(total) / 3
# after
score1 = int(input("Enter the first quiz score: "))
score2 = int(input("Enter the second quiz score: "))
score3 = int(input("Enter the third quiz score: "))
...
average = total / 3
```

## Instructor Notes

* Some students convert only inside the `average` line (`int(score1) + int(score2) + ...`) and
  leave `total` as the concatenated string. The average is then right but "Total points" still
  prints `858892`. Ask them to check *both* output lines.
* Others use `float()`; that is fine, but "Total points" prints `265.0`. Discuss why `int` fits
  whole-number quiz scores.
* Good follow-up: what would happen if a user typed `85.5`? (`int()` raises ValueError.)
