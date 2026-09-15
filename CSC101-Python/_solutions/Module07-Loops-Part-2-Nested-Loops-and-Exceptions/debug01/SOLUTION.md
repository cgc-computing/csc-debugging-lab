# Solution: Multiplication Table

**Course/Module/Activity:** CSC101 · Module 7 Loops Part 2: Nested Loops and Exceptions · debug01  
**Bug type(s):** logic (inner loop variable unused)  
**Bug count:** 1

## Observed Behavior

```
       1   2   3   4
    ----------------
 1 |   1   1   1   1
 2 |   4   4   4   4
 3 |   9   9   9   9
 4 |  16  16  16  16
```

Each row repeats one square number; the header is fine.

## The Bug(s)

`times_table.py`, line 17: `print(f"{row * row:4}", end="")` multiplies the outer variable by
itself. The inner loop variable `col` drives the loop but is never used in the computation.

## Why the Program Behaved Incorrectly

For each `row`, the inner loop runs `size` times, but since the expression only involves `row`,
the same value `row * row` is printed on every pass. The loop structure is right; the body ignores
the inner variable.

## The Concept This Illustrates

In a nested loop, the inner variable is what varies *within* a row and the outer variable is
what varies *between* rows. A cell's value usually depends on both. Also: the header loop above
uses `col` correctly, so students can compare the two loops.

## The Correction

```python
# before
        print(f"{row * row:4}", end="")
# after
        print(f"{row * col:4}", end="")
```

## Instructor Notes

* Ask students to point to the code that produced the `4` in row 2 and to say what `col` was at
  that moment. Realizing `col` is unused is the whole lesson.
* Some students rename the inner variable or change the inner `range`; neither changes the
  output. Have them predict before re-running.
* Extension: ask what the table would look like with `col * col` instead, and why every row would
  then be identical.
