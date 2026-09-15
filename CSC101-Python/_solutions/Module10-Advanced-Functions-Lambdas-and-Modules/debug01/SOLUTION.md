# Solution: Top Scorers

**Course/Module/Activity:** CSC101 · Module 10 Advanced Functions, Lambdas, and Modules · debug01  
**Bug type(s):** logic (sort direction)  
**Bug count:** 1

## Observed Behavior

```
Top 3 scorers
-------------
1. Chloe     72
2. Eli       84
3. Ana       88
```

The program prints the three *lowest* scores.

## The Bug(s)

`top_scorers.py`, line 13: `sorted(students, key=lambda student: student[1])` sorts by score in
ascending order (the default). The first three elements are therefore the smallest scores. The
call is missing `reverse=True`.

## Why the Program Behaved Incorrectly

The `key` lambda correctly tells `sorted()` *which* value to compare — the score at index 1 — but
says nothing about direction. `sorted()` always produces ascending order unless `reverse=True` is
given. `ranked[0]` is Chloe (72), not Fatima (99).

## The Concept This Illustrates

Separating the sort key (what to compare) from the sort order (which way). A `lambda` passed as
`key=` extracts a comparison value; it is not a comparison function. Also reinforces reading
library documentation for keyword arguments.

## The Correction

```python
# before
ranked = sorted(students, key=lambda student: student[1])
# after
ranked = sorted(students, key=lambda student: student[1], reverse=True)
```

## Instructor Notes

* A slick alternative is `key=lambda student: -student[1]`; it works for numeric keys and is a
  good discussion point (why would it fail for names?).
* Some students will index from the end (`ranked[-1]`, `ranked[-2]`, ...). It works but reverses
  the reader's expectation of "sorted highest first"; ask which is clearer.
* Others change `student[1]` to `student[0]` and sort by name; ask them to check the output.
* Quick check: `sorted([3, 1, 2])` in the shell — what order comes out?
