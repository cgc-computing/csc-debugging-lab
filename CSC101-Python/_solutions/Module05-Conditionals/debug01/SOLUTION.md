# Solution: Letter Grade Calculator

**Course/Module/Activity:** CSC101 · Module 5 Conditionals · debug01  
**Bug type(s):** logic (branch ordering)  
**Bug count:** 1

## Observed Behavior

```
A score of 85.0 earns a grade of D.
Congratulations on passing!
```

Every score of 60 or more earns a D; only scores below 60 get an F. A, B, and C are never
produced.

## The Bug(s)

`letter_grade.py`, lines 7–14: the `>=` checks are listed from smallest cutoff to largest
(`>= 60`, then `>= 70`, ...). Because `if`/`elif` picks the *first* true condition, `score >= 60`
captures every passing score before the later branches are ever examined.

## Why the Program Behaved Incorrectly

For 85: `85 >= 60` is true, so `grade = "D"` and the rest of the chain is skipped. The
`elif score >= 70/80/90` branches are unreachable for any score that made the first test true —
which is every score they were meant to handle.

## The Concept This Illustrates

`if`/`elif`/`else` is evaluated top to bottom and exactly one branch runs. When conditions
overlap (every A score is also `>= 60`), the order determines the result: with `>=` tests, list the
largest cutoff first; with `<` tests, list the smallest first.

## The Correction

```python
# before
if score >= 60:
    grade = "D"
elif score >= 70:
    grade = "C"
...
# after
if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
elif score >= 60:
    grade = "D"
else:
    grade = "F"
```

## Instructor Notes

* Some students keep the original order and change each test to a range
  (`60 <= score < 70`). That works and is worth discussing: it is correct but longer, and the
  chain no longer relies on order. Ask which version is easier to get right when cutoffs change.
* Others reverse the comparison to `<` but keep `>=` order in their head; have them trace 59.5
  and 60 to check the boundary.
* Follow-up: what grade does exactly 90 earn in the corrected version, and why does `>=` matter?
