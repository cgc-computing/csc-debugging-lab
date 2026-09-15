# Solution: 0/1 Knapsack With a One-Dimensional Table

**Course/Module/Activity:** CSC310 · Module 9 Dynamic Programming · debug02
**Bug type(s):** logic (iteration order in an in-place DP update)
**Bug count:** 1

## Observed Behavior

```
instance A: weights [10, 20, 30], values [60, 100, 120], capacity 50
  dp value = 300   brute force = 220   match = False
instance B: weights [2, 3, 4], values [3, 4, 5], capacity 8
  dp value = 12   brute force = 9   match = False
instance C: weights [1, 3, 4, 5], values [1, 4, 5, 7], capacity 7
  dp value = 9   brute force = 9   match = True
instance D: weights [5, 4, 6, 3], values [10, 40, 30, 50], capacity 10
  dp value = 150   brute force = 90   match = False
```

Three of four DP answers exceed the true optimum.

## The Bug(s)

`knapsack_01.py`, function `knapsack`:

```python
for w in range(wt, capacity + 1):
    dp[w] = max(dp[w], dp[w - wt] + val)
```

The capacity loop runs from low to high.

## Why the Program Behaved Incorrectly

With a single row, `dp[w - wt]` must still hold the value *before* the current item was considered
(the "previous row" of the 2-D table). Walking capacities upward means `dp[w - wt]` has already been
rewritten for this item by the time `dp[w]` reads it, so the item can be counted again: 300 in
instance A is five copies of the 10-kg item (60 × 5). Walking downward from `capacity` to `wt`
guarantees every `dp[w - wt]` read is still the old value, because indices below `w` have not yet
been touched in this pass. The ascending loop is exactly the correct algorithm for the *unbounded*
knapsack, where repeats are allowed. Instance C is unaffected only because no repeated item happens
to beat the best single-use combination for capacity 7.

## The Concept This Illustrates

Rolling a 2-D DP table into 1-D is a space optimization that changes nothing mathematically only if
the update order respects the recurrence's dependencies: `dp[i][w]` depends on `dp[i-1][w - wt]`,
and in one row that dependency is preserved only if the smaller index has not been overwritten yet.
The direction of a loop is therefore part of the algorithm, not a stylistic choice. Students holding
this bug understand the recurrence but not what "the previous row" means once the rows are merged.

## The Correction

```python
# before
for w in range(wt, capacity + 1):
# after
for w in range(capacity, wt - 1, -1):
```

## Instructor Notes

- Some students "fix" the bug by copying `dp` at the start of each item (`prev = dp[:]`) and reading
  from `prev`. That is correct and is the honest 2-D version in disguise; ask what it costs in memory
  and why the descending loop avoids the copy.
- Others clamp the answer with a `min` against the brute force result. Point out that the checker
  is Θ(2ⁿ) and exists only to test small cases.
- Ask students to trace instance B by hand for the 2-kg item with both loop directions and watch
  `dp[4]` become 6 (two copies) in the ascending version.
- Follow-up: which loop direction is right for coin change (unbounded) and for the subset-sum
  problem (0/1)? Have them justify each with the dependency argument.
