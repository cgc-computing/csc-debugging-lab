# Solution: Quarterly Rainfall Table

**Course/Module/Activity:** CSC110 · Module 10 More About Arrays · debug01
**Bug type(s):** logic, boundary
**Bug count:** 1

## Observed Behavior

The Q4 column is missing and every total is too small:

```
Year    Q1    Q2    Q3    Q4   Total
2022   3.2   4.1   2.8     10.1
2023   2.9   3.7   3.3      9.9
2024   4.0   3.9   2.5     10.4

Three-year total: 30.4 inches
```

## The Bug(s)

`RainfallTable.java`, in `main`, the inner loop's bound:

```java
for (int col = 0; col < rainfall.length; col++) {
```

`rainfall.length` is the number of *rows* (3), not the number of columns (4).

## Why the Program Behaved Incorrectly

A Java 2-D array is an array of row arrays. `rainfall.length` counts rows; the length of a row is `rainfall[row].length`. Because the table is 3 x 4, using the row count as the column bound stops the inner loop after three columns, so Q4 is never printed or added. If the array had been square the bug would be invisible.

## The Concept This Illustrates

The structure of 2-D arrays in Java ("arrays of arrays") and the distinct meanings of `a.length` and `a[i].length`. Students frequently reuse the outer bound for the inner loop, which works only for square tables.

## The Correction

```java
// before
for (int col = 0; col < rainfall.length; col++) {

// after
for (int col = 0; col < rainfall[row].length; col++) {
```

## Instructor Notes

- `rainfall[0].length` also works here but assumes every row is the same length; `rainfall[row].length` is the general form and handles ragged arrays. Discuss the difference.
- Some students hard-code `col < 4`. It fixes the output but ask what happens if a fifth column (annual adjustment) is added.
- A useful exercise: have students swap the loops to print totals by quarter instead of by year. It forces them to keep the two lengths straight.
- Ask why the header row still shows Q4 — it is a literal string, not generated from the data, which is why the mismatch was noticeable.
