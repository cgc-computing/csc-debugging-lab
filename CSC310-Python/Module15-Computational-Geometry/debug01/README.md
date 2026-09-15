# Do Two Segments Intersect?

**Course:** CSC310 &nbsp;|&nbsp; **Module 15:** Computational Geometry &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`segment_intersection.py` decides whether two line segments share at least one point (CLRS Section
33.1) using only cross products: no division and no floating point. Two segments intersect if they
cross properly, if an endpoint of one lies on the other (a "T"), if they share an endpoint, or if they
overlap along the same line. The `main` block tests eight configurations.

## Expected Behavior

```
crossing          : (0, 0)-(4, 4) and (0, 4)-(4, 0) -> intersect
T junction        : (0, 0)-(4, 0) and (2, 0)-(2, 3) -> intersect
shared endpoint   : (0, 0)-(3, 3) and (3, 3)-(6, 0) -> intersect
collinear overlap : (0, 0)-(4, 0) and (2, 0)-(6, 0) -> intersect
diagonal overlap  : (0, 0)-(3, 3) and (2, 2)-(5, 5) -> intersect
collinear apart   : (0, 0)-(2, 0) and (3, 0)-(5, 0) -> disjoint
parallel          : (0, 0)-(4, 0) and (0, 1)-(4, 1) -> disjoint
near miss         : (0, 0)-(4, 4) and (5, 0)-(6, 3) -> disjoint
```

## How to Run

```bash
python3 segment_intersection.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
cross-product approach; do not introduce slopes or floating-point arithmetic.

## Think About

- For the "T junction" case, compute the four cross products `d1` through `d4` by hand. Which of them
  are zero, and what does a zero mean geometrically?
- When a cross product is zero the code asks whether a point lies *between* the other segment's
  endpoints. Say precisely what "between" should mean for a point that coincides with an endpoint, and
  for a horizontal segment whose endpoints share the same y-coordinate.
- "diagonal overlap" is reported correctly while "collinear overlap" is not, although both are pairs of
  overlapping collinear segments. What is different about their coordinates?
- Which of the eight cases are "touching" rather than "crossing"? Check that the incorrect verdicts fall
  exactly on those cases, and explain why the crossing cases are immune.
