# Solution: Theater Seating Chart

**Course/Module/Activity:** CSC110 · Module 10 More About Arrays · debug01
**Bug type(s):** boundary (wrong loop bound in a 2-D traversal)
**Bug count:** 1

## Observed Behavior

The map is correct but the count is low:

```
Seating map (X = taken, . = open):
X . . X .
. . X X X
X X . . .
Open seats: 5 of 15
```

## The Bug(s)

`seating_chart.cpp`, `main`, the counting loop:

```cpp
for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < ROWS; c++) {
```

The inner (column) loop uses `ROWS` (3) as its bound instead of `COLS` (5).

## Why the Program Behaved Incorrectly

The inner loop visits only columns 0, 1, and 2 of each row, so columns 3 and 4 are never
examined. Open seats in those columns — `(0,4)`, `(2,3)`, `(2,4)` — are not counted: 8 − 3 = 5.
The program does not crash because 3 is *smaller* than the true width; had the bounds been swapped
the other way (rows bounded by `COLS`), the loop would have read past the array.

## The Concept This Illustrates

A 2-D array has two independent dimensions, and each loop must be bounded by the dimension it
walks. Copy-pasting a loop header and changing only the variable name is how this happens. The
printing loop in the same program has the correct bounds, which gives students a template to
compare against.

## The Correction

```cpp
// before
for (int c = 0; c < ROWS; c++) {

// after
for (int c = 0; c < COLS; c++) {
```

## Instructor Notes

- Ask students to predict what would happen if the *outer* loop were bounded by `COLS` instead
  (reads rows 3 and 4, which do not exist — undefined behavior, possibly a plausible-looking
  count). Then let them try it with `-fsanitize=address`.
- Ask: for a square chart (`ROWS == COLS`), would this mistake ever be noticed? What does that say
  about choosing test data?
- Follow-up: rewrite the count using a range-based approach or a helper function taking the array
  and both dimensions.
