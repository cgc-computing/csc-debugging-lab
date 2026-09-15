# Do Two Segments Intersect?

**Course:** CSC310 &nbsp;|&nbsp; **Module 15:** Computational Geometry &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`intersects` decides whether two line segments share at least one point (CLRS 33.1) using only cross products—no division, no floating point. Two segments intersect if they cross, if an endpoint of one lies on the other (a "T"), if they share an endpoint, or if they overlap along the same line. The driver tests seven configurations.

## Expected Behavior

```
crossing        : (0,0)-(4,4) and (0,4)-(4,0) -> intersect
T junction      : (0,0)-(4,0) and (2,0)-(2,3) -> intersect
shared endpoint : (0,0)-(3,3) and (3,3)-(6,0) -> intersect
collinear overlap: (0,0)-(4,0) and (2,0)-(6,0) -> intersect
collinear apart : (0,0)-(2,0) and (3,0)-(5,0) -> disjoint
parallel        : (0,0)-(4,0) and (0,1)-(4,1) -> disjoint
near miss       : (0,0)-(4,4) and (5,0)-(6,3) -> disjoint
```

## How to Run

```bash
g++ -std=c++17 -Wall -o segment_intersection segment_intersection.cpp
./segment_intersection
```

(on Windows: `segment_intersection.exe` or `.\segment_intersection.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the cross-product approach; you may add helper functions.

## Think About

- `direction` returns a positive, negative, or zero value. What geometric situation does zero describe, and how does the program currently treat that situation?
- For the T junction, compute the four direction values by hand. Which one is zero, and what *additional* question would you need to answer to decide whether that point really touches the other segment?
- Two segments that share an endpoint obviously intersect. Which of the four values are zero there, and why is "straddling" the wrong word for that situation?
