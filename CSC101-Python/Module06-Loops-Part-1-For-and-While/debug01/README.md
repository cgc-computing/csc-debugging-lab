# Staircase Blocks

**Course:** CSC101 &nbsp;|&nbsp; **Module 6:** Loops Part 1: For and While &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

A staircase with `n` steps is built from blocks: step 1 uses 1 block, step 2 uses 2 blocks, and
so on up to step `n`. The program reads `n`, prints one line per step with a running total, and
then reports the total number of blocks.

## Expected Behavior

```
How many steps in the staircase? 5
Step 1 uses 1 block(s). Running total: 1
Step 2 uses 2 block(s). Running total: 3
Step 3 uses 3 block(s). Running total: 6
Step 4 uses 4 block(s). Running total: 10
Step 5 uses 5 block(s). Running total: 15

A staircase with 5 steps needs 15 blocks.
```

## How to Run

```bash
python3 staircase_blocks.py
```

Type `5` and press Enter.

## Your Task

Run the program and compare its output, line by line, with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* How many times should the loop body execute for 5 steps? How many times did it execute?
* In the shell, try `list(range(1, 5))`. Which numbers are included, and which one is not?
* What is the relationship between the second argument to `range` and the last value the loop
  variable takes?
