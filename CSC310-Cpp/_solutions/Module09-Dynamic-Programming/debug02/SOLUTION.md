# Solution: 0/1 Knapsack with a One-Dimensional Table

**Course/Module/Activity:** CSC310 · Module 9 Dynamic Programming · debug02
**Bug type(s):** conceptual/design (reads the current row where the previous row is required)
**Bug count:** 1

## Observed Behavior

```
small items, capacity 5 (table shows best value for capacity 0..5)
  after pen: 0 2 4 6 8 10
  after book: 0 2 4 6 8 10
  after lamp: 0 2 4 6 8 10
  after radio: 0 2 4 6 8 10
best value: 10
small items, capacity 7
best value: 14
classic items, capacity 50
best value: 300
```

After the pen alone the table claims value 10 at capacity 5—five pens. Every answer is too large.

## The Bug(s)

`knapsack.cpp`, `knapsack`, inner loop direction:

```cpp
for (int w = it.weight; w <= capacity; ++w) {
    best[w] = std::max(best[w], best[w - it.weight] + it.value);
}
```

Capacities are processed in **ascending** order. In the one-dimensional 0/1 knapsack the loop must run **descending**.

## Why the Program Behaved Incorrectly

The two-dimensional recurrence is `best[i][w] = max(best[i-1][w], best[i-1][w - wt] + val)`—both terms come from the *previous* row (items 1..i-1). Folding the table into one row works only if `best[w - wt]` still holds the previous row's value when `best[w]` is computed. Going upward, `best[w - wt]` has *already* been overwritten with the current row's value, which may already include this item. So the item can be counted again and again: `best[1] = 2`, then `best[2] = best[1] + 2 = 4`, `best[3] = best[2] + 2 = 6`, and so on—five pens in capacity 5. That is exactly the recurrence for the **unbounded** knapsack, which is why the results are consistent, just for the wrong problem.

## The Concept This Illustrates

Space optimization in dynamic programming depends on the *order of evaluation*: you may overwrite a table entry only after every entry that depends on its old value has been computed. For 0/1 knapsack, `best[w]` depends on smaller capacities from the previous row, so larger capacities must be finalized first (descending `w`). For unbounded knapsack, `best[w]` may legitimately depend on the current row, so ascending order is correct there. Students who memorize the compact loop without the dependency argument flip the direction and silently solve a different problem.

## The Correction

```cpp
for (int w = capacity; w >= it.weight; --w) {
    best[w] = std::max(best[w], best[w - it.weight] + it.value);
}
```

## Instructor Notes

- Ask students to draw the two-dimensional table for the small instance and mark which cells the one-dimensional loop reads and writes at each step; the dependency arrow makes the direction obvious.
- Some students "fix" it by copying `best` into a temporary before the inner loop and reading from the copy. That is correct and uses O(2W) space—a good moment to ask why the descending loop achieves the same thing with no copy.
- Follow-up: change the problem to "each item may be taken any number of times" and ask which loop direction is now correct (ascending). The same code, one character apart, solves two different problems.
- The trace rows after the fix (`0 2 2 2 2 2`, then `0 2 3 5 5 5`, …) are worth reading aloud: each row is "best value using the first k items".
