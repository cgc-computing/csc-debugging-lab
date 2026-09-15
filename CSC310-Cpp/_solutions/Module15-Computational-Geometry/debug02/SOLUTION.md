# Solution: Convex Hull by Graham's Scan

**Course/Module/Activity:** CSC310 · Module 15 Computational Geometry · debug02
**Bug type(s):** logic (tie order among collinear points is inconsistent with the scan's pop rule)
**Bug count:** 1

## Observed Behavior

```
square with edge points: 6 hull vertices: (0,0) (2,0) (4,2) (4,4) (0,4) (0,2)   twice the area = 28
triangle with edge points: 5 hull vertices: (0,0) (3,0) (4,2) (3,3) (1,1)   twice the area = 12
pentagon: 5 hull vertices: (1,0) (4,1) (5,4) (2,6) (0,3)   twice the area = 37
```

The square loses the corner `(4,0)` and gains three edge-interior points; its area is wrong. The triangle loses `(6,0)` and gains interior-edge points; its area is wrong too. The pentagon, which has no collinear points, is correct.

## The Bug(s)

`convex_hull.cpp`, `convexHull`, the sort comparator's tie-break:

```cpp
if (c != 0) return c > 0;
return distSquared(anchor, a) > distSquared(anchor, b);   // farther point first
```

Points at the same polar angle are ordered **farthest first**. The scan's pop rule (`cross <= 0`, i.e. pop on a non-left turn) is only correct when collinear points are met **nearest first**.

## Why the Program Behaved Incorrectly

Anchor `(0,0)`; angle 0 holds `(4,0)` and `(2,0)`. With farthest-first order the stack is `[(0,0), (4,0)]` when `(2,0)` arrives. The turn `(0,0) -> (4,0) -> (2,0)` is collinear (`cross = 0`), so the rule pops `(4,0)`—the real corner—and pushes `(2,0)`. From then on the scan proceeds from an edge-interior point: `(3,1)` and `(4,2)` look like left turns relative to `(2,0)`, and the same mistake repeats on the 45° ray (`(4,4)` before `(2,2)`, `(1,1)`) and on the 90° ray (`(0,4)` before `(0,2)`, where `(0,2)` is pushed last and can never be popped because no later point arrives). The result is a polygon that is not convex and not the hull.

With nearest-first order the stack is `[(0,0), (2,0)]` when `(4,0)` arrives; the collinear turn pops `(2,0)` and keeps `(4,0)`, which is what "only the farthest survives" requires.

## The Concept This Illustrates

Graham's scan is correct because the sorted sequence visits hull vertices in counter-clockwise order and every non-hull point is eventually popped by a later point that "sees past" it. Collinear points with the anchor break the total order on angles, and CLRS explicitly resolves the tie by keeping only the farthest (Step 2: "if two or more points have the same polar angle, remove all but the one farthest from p0"). Doing that implicitly through the scan works only if the scan meets the nearer points first, so that the farther point pops them. Meeting the farther point first inverts the roles and the pop rule removes the corner. The general lesson: a sort-then-scan algorithm's correctness depends on the *complete* ordering, including how ties are broken, and the tie-break must agree with the scan's invariant.

## The Correction

```cpp
if (c != 0) return c > 0;
return distSquared(anchor, a) < distSquared(anchor, b);   // nearest point first
```

## Instructor Notes

- Students frequently "fix" it by changing the pop test to `cross < 0` (pop only on right turns). With farthest-first order that yields `7 hull vertices: (0,0) (4,0) (4,2) (4,4) (2,4) (0,4) (0,2)`—all corners present, area correct, but every edge-interior point is kept. Ask whether that output satisfies "only corner points" and why the area check passes anyway.
- With the *correct* order and `cross < 0` the output is `(0,0) (2,0) (4,0) (4,2) (4,4) (2,4) (0,4)`—again correct area, wrong vertex set, and note that `(0,2)` *is* removed because it is on the last ray where the farthest point arrives second. Inconsistent handling of collinear points is the tell.
- A subtle correct alternative: keep farthest-first *only on the last ray* (so the hull closes properly) and nearest-first elsewhere—this is what some implementations do when they want to keep collinear edge points. Not needed here, but worth mentioning if a student asks.
- Ask why the anchor choice (min `y`, then min `x`) guarantees all other points have polar angles in `[0, 180°)`, which is what makes the cross-product comparator a strict weak ordering (a requirement of `std::sort`).
