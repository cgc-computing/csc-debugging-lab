# 0/1 Knapsack With a One-Dimensional Table

**Course:** CSC310 &nbsp;|&nbsp; **Module 9:** Dynamic Programming &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`knapsack_01.py` solves the 0/1 knapsack problem (each item may be taken at most once) with a
dynamic-programming table compressed to a single row `dp[0..W]`, updated in place once per item. A
brute-force checker enumerates all subsets so the DP answer can be verified. The `main` block runs
four small instances.

## Expected Behavior

```
instance A: weights [10, 20, 30], values [60, 100, 120], capacity 50
  dp value = 220   brute force = 220   match = True
instance B: weights [2, 3, 4], values [3, 4, 5], capacity 8
  dp value = 9   brute force = 9   match = True
instance C: weights [1, 3, 4, 5], values [1, 4, 5, 7], capacity 7
  dp value = 9   brute force = 9   match = True
instance D: weights [5, 4, 6, 3], values [10, 40, 30, 50], capacity 10
  dp value = 90   brute force = 90   match = True
```

## How to Run

```bash
python3 knapsack_01.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
one-dimensional table; do not expand it back to a two-dimensional table.

## Think About

- In instance A the program reports 300. Which combination of items is worth 300, and why is it not
  allowed?
- `dp[w]` is updated from `dp[w - wt]`. At the moment `dp[w]` is written, has `dp[w - wt]` already
  been updated *for the current item*, or does it still hold the value from before this item was
  considered? Which of those two should it be?
- In the two-dimensional version, row `i` is computed from row `i-1`. When both rows share one
  array, what determines whether a read sees the "previous row" or the "current row"?
- Instance C comes out right even though the same code runs. What about that instance makes the
  difference invisible?
