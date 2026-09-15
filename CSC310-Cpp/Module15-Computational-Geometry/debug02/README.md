# Convex Hull by Graham's Scan

**Course:** CSC310 &nbsp;|&nbsp; **Module 15:** Computational Geometry &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`convexHull` implements Graham's scan (CLRS 33.3): pick the lowest point (leftmost on ties) as the anchor, sort the remaining points by polar angle around it, then sweep with a stack, popping whenever the top of the stack would not make a left turn. The result is the hull's corner points in counter-clockwise order starting at the anchor; points lying on a hull edge but not at a corner are not included. The driver runs three point sets (two of which contain points in the middle of hull edges) and prints twice the polygon area as a check.

## Expected Behavior

```
square with edge points: 4 hull vertices: (0,0) (4,0) (4,4) (0,4)   twice the area = 32
triangle with edge points: 3 hull vertices: (0,0) (6,0) (3,3)   twice the area = 18
pentagon: 5 hull vertices: (1,0) (4,1) (5,4) (2,6) (0,3)   twice the area = 37
```

## How to Run

```bash
g++ -std=c++17 -Wall -o convex_hull convex_hull.cpp
./convex_hull
```

(on Windows: `convex_hull.exe` or `.\convex_hull.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep Graham's scan; do not switch to a different hull algorithm.

## Think About

- Several input points lie on the same ray from the anchor (for example `(2,0)` and `(4,0)`). Does the order in which the scan meets them matter? Trace the bottom edge of the square by hand in both orders and watch what the turn test does.
- The buggy square hull has 6 "vertices", yet one true corner is missing while three edge-interior points are present. Which corner was lost, and at which step was it popped?
- The pentagon comes out right. What is different about its input?
