# Convex Hull by Graham's Scan

**Course:** CSC310 &nbsp;|&nbsp; **Module 15:** Computational Geometry &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`convex_hull.py` implements Graham's scan (CLRS Section 33.3): pick the lowest point (leftmost on
ties) as the anchor, sort the remaining points by polar angle around the anchor (nearer points first
when angles tie), then sweep through them with a stack, popping whenever the top of the stack would
fail to make a left turn. The result is the hull's corner points in counter-clockwise order starting
at the anchor; a point that lies on a hull edge but is not a corner is not part of the answer. The
`main` block runs three point sets (two of which contain points in the middle of hull edges) and
prints twice the polygon area as a check.

## Expected Behavior

```
square with edge points: 4 hull vertices: (0,0) (4,0) (4,4) (0,4)   twice the area = 32
triangle with edge points: 3 hull vertices: (0,0) (6,0) (3,3)   twice the area = 18
pentagon: 5 hull vertices: (1,0) (4,1) (5,4) (2,6) (0,3)   twice the area = 37
```

## How to Run

```bash
python3 convex_hull.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
sort-then-scan structure; do not pre-filter the points.

## Think About

- The `cross` helper is positive for a left turn and negative for a right turn. What does it return
  when the three points are collinear, and what should the scan do with the *middle* point in that
  case, given the definition of the answer in the Goal?
- The current output for the square keeps `(2,0)`, `(4,2)` and `(2,4)` but drops `(0,2)`. Trace the scan
  along the bottom edge (anchor, `(2,0)`, `(4,0)`) and then along the left edge (`(2,4)`, `(0,2)`,
  `(0,4)`): why is `(0,2)` popped while `(2,0)` is not? What role does the sort order play?
- "Twice the area" is 32 in both the right and the current output. Why is the area insensitive to this
  mistake, and what does that say about using an area check as the only test?
- The pentagon comes out right. What property of that point set makes the mistake invisible?
