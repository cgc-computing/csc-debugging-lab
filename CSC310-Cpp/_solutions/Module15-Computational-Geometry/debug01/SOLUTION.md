# Solution: Do Two Segments Intersect?

**Course/Module/Activity:** CSC310 · Module 15 Computational Geometry · debug01
**Bug type(s):** boundary / conceptual (the collinear case `cross = 0` is treated as "cannot intersect")
**Bug count:** 1

## Observed Behavior

```
crossing        : (0,0)-(4,4) and (0,4)-(4,0) -> intersect
T junction      : (0,0)-(4,0) and (2,0)-(2,3) -> disjoint
shared endpoint : (0,0)-(3,3) and (3,3)-(6,0) -> disjoint
collinear overlap: (0,0)-(4,0) and (2,0)-(6,0) -> disjoint
collinear apart : (0,0)-(2,0) and (3,0)-(5,0) -> disjoint
parallel        : (0,0)-(4,0) and (0,1)-(4,1) -> disjoint
near miss       : (0,0)-(4,4) and (5,0)-(6,3) -> disjoint
```

Only a proper crossing is recognized. Every touching or overlapping configuration is reported disjoint.

## The Bug(s)

`segment_intersection.cpp`, `intersects`:

```cpp
bool s1Straddles = (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0);
bool s2Straddles = (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0);
return s1Straddles && s2Straddles;
```

The function tests only the strict straddle condition. CLRS's SEGMENTS-INTERSECT continues with four `else if (d_i == 0 and ON-SEGMENT(...))` cases; the program has none of them.

## Why the Program Behaved Incorrectly

`direction(a, b, c)` is zero exactly when `c` lies on the line through `a` and `b`. In the T junction, `d3 = direction((0,0),(4,0),(2,0)) = 0` because `(2,0)` is on the first segment's line; the strict test requires opposite signs, so zero counts as "not straddling" and the segments are declared disjoint. For the shared endpoint, two of the four values are zero; for collinear overlap all four are zero. In every one of those cases the correct answer requires a second question—*is the collinear point within the segment's bounding box?*—which the program never asks. "Collinear apart" is disjoint for the right reason only by accident (the bounding-box check would also say no).

## The Concept This Illustrates

Geometric predicates have degenerate cases, and the degenerate case of the orientation test (`cross = 0`) is not "no information"—it is the *most* informative case, telling you the points are collinear and forcing a different test (ON-SEGMENT). Robust geometric code treats sign zero as a first-class outcome with its own branch. Students who write the straddle test as "signs differ" are answering the question "do the segments *cross*?" rather than "do they *intersect*?", and the two differ exactly at endpoints and along shared lines—the cases that show up constantly in practice (polygon vertices, grid-aligned segments).

## The Correction

```cpp
bool onSegment(Point a, Point b, Point c) {
    return std::min(a.x, b.x) <= c.x && c.x <= std::max(a.x, b.x) &&
           std::min(a.y, b.y) <= c.y && c.y <= std::max(a.y, b.y);
}
...
if (s1Straddles && s2Straddles) return true;
if (d1 == 0 && onSegment(s2.p, s2.q, s1.p)) return true;
if (d2 == 0 && onSegment(s2.p, s2.q, s1.q)) return true;
if (d3 == 0 && onSegment(s1.p, s1.q, s2.p)) return true;
if (d4 == 0 && onSegment(s1.p, s1.q, s2.q)) return true;
return false;
```

## Instructor Notes

- A tempting "fix" is to loosen the straddle test to `d1 * d2 <= 0 && d3 * d4 <= 0`. Run "collinear apart": all four values are zero, the products are zero, and the segments are wrongly reported as intersecting. The zero case needs the bounding-box question, not a looser sign test.
- Ask why `onSegment` may assume collinearity (it is only called when the corresponding `d` is zero) and what it would wrongly accept without that assumption.
- Ask what the multiplication `d1 * d2` could do with large coordinates (overflow) and why comparing signs separately is safer.
- Follow-up: which of the seven cases would change if the segments were considered *open* (endpoints excluded)?
