# Solution: Convex Hull by Graham's Scan

**Course/Module/Activity:** CSC310 · Module 15 Computational Geometry · debug02
**Bug type(s):** boundary (collinear case: the pop condition ignores `cross == 0`), logic
**Bug count:** 1

## Observed Behavior

```
square with edge points: 7 hull vertices: (0,0) (2,0) (4,0) (4,2) (4,4) (2,4) (0,4)   twice the area = 32
triangle with edge points: 7 hull vertices: (0,0) (2,0) (4,0) (6,0) (5,1) (4,2) (3,3)   twice the area = 18
pentagon: 5 hull vertices: (1,0) (4,1) (5,4) (2,6) (0,3)   twice the area = 37
```

Points in the middle of hull edges are kept — but not all of them: `(0,2)` on the square's left edge
and `(1,1)`, `(2,2)` on the triangle's left edge are dropped, so the answer is neither "corners only"
nor "all boundary points". The areas are nevertheless correct.

## The Bug(s)

`convex_hull.py`, function `convex_hull`:

```python
while len(hull) > 1 and cross(hull[-2], hull[-1], p) < 0:     # should be <= 0
    hull.pop()
```

## Why the Program Behaved Incorrectly

CLRS's scan pops while the top of the stack makes a "nonleft turn", and a nonleft turn includes going
straight (`cross == 0`). With `< 0`, straight steps are kept, so an edge point that the sort delivers
*before* its corner survives: along the bottom edge the order is anchor, `(2,0)`, `(4,0)`, and
anchor → `(2,0)` → `(4,0)` is straight, so `(2,0)` stays. On the last ray from the anchor the sort
(nearer first) delivers `(0,2)` before `(0,4)`; the step `(2,4)` → `(0,2)` → `(0,4)` is a genuine right
turn, so `(0,2)` is popped, while `(4,4)` → `(2,4)` → `(0,4)` is straight and `(2,4)` stays. Whether an
edge point survives thus depends on where it falls in the sort, which is why the output is
inconsistent. The area is unaffected because a collinear point adds nothing to the shoelace sum.

## The Concept This Illustrates

The cross product's sign classifies a triple as left turn, right turn, or collinear, and the collinear
case must be assigned *deliberately*. For a corners-only hull, a collinear middle point is not a
vertex and must be popped, so the test is `<= 0`. CLRS handles the same issue up front by removing all
but the farthest point among those with equal polar angle; either way, the algorithm's invariant
("the stack holds, in order, the vertices of the convex hull of the points processed so far") is
what dictates the treatment of `cross == 0`.

## The Correction

```python
# before
while len(hull) > 1 and cross(hull[-2], hull[-1], p) < 0:

# after
while len(hull) > 1 and cross(hull[-2], hull[-1], p) <= 0:
```

## Instructor Notes

- Some students argue that edge points *should* be included. That is a legitimate alternative
  definition, but the README defines the answer, and including them correctly is harder than it looks:
  points on the last ray must then be emitted farthest-first, and the buggy program does not do that.
  Ask what the output order for the left edge of the square would have to be.
- Changing the sort's tie-break alone does not repair the program; have groups predict the effect
  before trying it.
- The identical areas are a useful lesson in test design: a check that passes for both the right and
  the wrong answer is not a check.
- The pentagon has no collinear triples, so `cross` is never zero and the two conditions coincide.
  Ask students to add one edge point to the pentagon and predict the output.
