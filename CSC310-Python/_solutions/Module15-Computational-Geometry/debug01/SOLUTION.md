# Solution: Do Two Segments Intersect?

**Course/Module/Activity:** CSC310 · Module 15 Computational Geometry · debug01
**Bug type(s):** boundary (strict inequalities in the collinear "between" test)
**Bug count:** 1

## Observed Behavior

```
crossing          : (0, 0)-(4, 4) and (0, 4)-(4, 0) -> intersect
T junction        : (0, 0)-(4, 0) and (2, 0)-(2, 3) -> disjoint
shared endpoint   : (0, 0)-(3, 3) and (3, 3)-(6, 0) -> disjoint
collinear overlap : (0, 0)-(4, 0) and (2, 0)-(6, 0) -> disjoint
diagonal overlap  : (0, 0)-(3, 3) and (2, 2)-(5, 5) -> intersect
collinear apart   : (0, 0)-(2, 0) and (3, 0)-(5, 0) -> disjoint
parallel          : (0, 0)-(4, 0) and (0, 1)-(4, 1) -> disjoint
near miss         : (0, 0)-(4, 4) and (5, 0)-(6, 3) -> disjoint
```

The three "touching" configurations — T junction, shared endpoint, horizontal collinear overlap — are
reported disjoint.

## The Bug(s)

`segment_intersection.py`, function `on_segment`:

```python
return (min(pi[0], pj[0]) < pk[0] < max(pi[0], pj[0]) and
        min(pi[1], pj[1]) < pk[1] < max(pi[1], pj[1]))      # should be <= on both lines
```

## Why the Program Behaved Incorrectly

`segments_intersect` correctly detects collinearity (`d == 0`) and hands the point to `on_segment`,
but the strict bounding-box test excludes any point on the *boundary* of the box. For the T junction,
`(2, 0)` lies on `(0, 0)-(4, 0)`: the x-test `0 < 2 < 4` passes, but the y-test `0 < 0 < 0` cannot
pass for any point of a horizontal segment. The shared endpoint `(3, 3)` fails `0 < 3 < 3`. In the
horizontal overlap every candidate endpoint fails the y-test. The diagonal overlap survives only
because `(2, 2)` is strictly inside the box of `(0, 0)-(3, 3)` in both coordinates — a passing test
that proves nothing about the boundary.

## The Concept This Illustrates

The whole reason SEGMENTS-INTERSECT has a collinear branch is to handle *touching* — endpoints on
segments, shared endpoints, overlaps — and those are boundary cases by definition, so ON-SEGMENT's
box test must be inclusive (`min ≤ x ≤ max`). Since the cross product has already established
collinearity, the box test is only asking "is the point within the extent of the segment", and an
endpoint is within it. Axis-parallel segments make the strict version fail even for interior points,
because one coordinate range collapses to a single value.

## The Correction

```python
# before
return (min(pi[0], pj[0]) < pk[0] < max(pi[0], pj[0]) and
        min(pi[1], pj[1]) < pk[1] < max(pi[1], pj[1]))

# after
return (min(pi[0], pj[0]) <= pk[0] <= max(pi[0], pj[0]) and
        min(pi[1], pj[1]) <= pk[1] <= max(pi[1], pj[1]))
```

## Instructor Notes

- Students who make only the x-test inclusive fix the horizontal cases and break for vertical ones.
  Ask them to add a vertical T junction, e.g. `(2, 0)-(2, 4)` with `(0, 2)-(2, 2)`, before declaring
  victory.
- Some will want to replace the box test with a distance or parameter computation in floating point.
  Point out that the integer cross-product method is exact and that CLRS chooses it for that reason.
- "diagonal overlap" passing in the buggy version is a good example of why one green test is not
  evidence about boundary handling.
- Follow-up: why is the proper-crossing test (`d1`, `d2` of opposite strict signs and `d3`, `d4` of
  opposite strict signs) unaffected by this mistake?
