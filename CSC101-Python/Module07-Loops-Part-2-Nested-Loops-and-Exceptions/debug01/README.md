# Multiplication Table

**Course:** CSC101 &nbsp;|&nbsp; **Module 7:** Loops Part 2: Nested Loops and Exceptions &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program reads a table size `n` and prints an `n × n` multiplication table with a header row.
The entry in row `r`, column `c` must be `r × c`.

## Expected Behavior

```
Table size (1-12): 4
       1   2   3   4
    ----------------
 1 |   1   2   3   4
 2 |   2   4   6   8
 3 |   3   6   9  12
 4 |   4   8  12  16
```

## How to Run

```bash
python3 times_table.py
```

Type `4` and press Enter.

## Your Task

Run the program and compare every row with the Expected Behavior. This program contains one or
more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why*
the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

* In a nested loop, which variable changes on every trip through the *inner* loop, and which one
  stays the same until the inner loop finishes?
* Look at the second row of the output. What single product is being printed four times, and
  which two variables would have to be multiplied to get that value?
* What value should the entry in row 3, column 4 have, and which variables hold 3 and 4 at that
  moment?
