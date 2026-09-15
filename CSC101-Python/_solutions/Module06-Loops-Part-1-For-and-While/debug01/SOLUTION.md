# Solution: Staircase Blocks

**Course/Module/Activity:** CSC101 · Module 6 Loops Part 1: For and While · debug01  
**Bug type(s):** boundary (off-by-one in `range`)  
**Bug count:** 1

## Observed Behavior

```
Step 1 uses 1 block(s). Running total: 1
Step 2 uses 2 block(s). Running total: 3
Step 3 uses 3 block(s). Running total: 6
Step 4 uses 4 block(s). Running total: 10

A staircase with 5 steps needs 10 blocks.
```

Only four step lines print and the total is 10 instead of 15.

## The Bug(s)

`staircase_blocks.py`, line 8: `for step in range(1, steps):`. `range(1, 5)` produces 1, 2, 3,
4 — the stop value is excluded — so step 5 is never processed.

## Why the Program Behaved Incorrectly

`range(start, stop)` yields values from `start` up to but not including `stop`. The programmer
read `steps` as "the last step" rather than "one past the last step." The loop body ran four
times and the accumulator stopped at 10.

## The Concept This Illustrates

The half-open interval convention of `range` (the same rule as string slicing in Module 3). To
include `n` itself, the stop argument must be `n + 1`.

## The Correction

```python
# before
for step in range(1, steps):
# after
for step in range(1, steps + 1):
```

## Instructor Notes

* Some students change the loop to `range(0, steps)`; that runs five times but prints "Step 0"
  and totals 10. Ask them to compare the first printed line with the expected output.
* Others "fix" only the final message (adding `+ steps` to the total). Point them back at the
  per-step lines.
* Ask what `range(steps)` alone would give, and when starting at 0 is the natural choice.
