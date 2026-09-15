# Rod Cutting, Top-Down and Bottom-Up

**Course:** CSC310 &nbsp;|&nbsp; **Module 9:** Dynamic Programming &nbsp;|&nbsp; **Activity:** debug03
**Language:** Python 3

## Goal

`rod_cutting.py` implements both MEMOIZED-CUT-ROD (top-down with a table `r[]`) and
EXTENDED-BOTTOM-UP-CUT-ROD (which also records where to cut) from CLRS Section 14.1. The `main`
block prints, for rods of length 1 to 10 with the textbook prices, the maximum revenue, the number of
recursive calls the top-down version made, and the optimal cuts; then it solves a rod of length 30.

## Expected Behavior

```
 n  revenue  calls  cuts
 1        1      2  [1]
 2        5      4  [2]
 3        8      7  [3]
 4       10     11  [2, 2]
 5       13     16  [2, 3]
 6       17     22  [6]
 7       18     29  [1, 6]
 8       22     37  [2, 6]
 9       25     46  [3, 6]
10       30     56  [10]

rod of length 30: revenue 90, 466 calls, 0.000 s
```

The number of calls for a rod of length n should be 1 + n(n+1)/2, and the last line should appear
essentially instantly (the exact fraction of a second may differ on your machine).

## How to Run

```bash
python3 rod_cutting.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep both
versions; the bottom-up one is not the problem.

## Think About

- Look at the `calls` column in your run and find the pattern. What function of n is it, and what
  does that say about how many times each subproblem is being solved?
- The revenues are all correct. How can an algorithm compute the right answer and still be doing
  something fundamentally wrong?
- Memoization has two halves: *storing* a result and *checking for* a stored result. Where in the
  control flow does each half have to happen for the stored result to save any work?
- Why is a rod of length 30 so much worse than a rod of length 10 for the version you ran, when the
  bottom-up version handles both with ease?
