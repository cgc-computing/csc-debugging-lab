# Solution: Shopping Total with Tax

**Course/Module/Activity:** CSC101 · Module 6 Loops Part 1: For and While · debug03  
**Bug type(s):** logic (accumulator reset inside loop)  
**Bug count:** 1

## Observed Behavior

```
Subtotal: $10.00
Tax:      $0.80
Total:    $10.80
```

The subtotal equals the *last* price entered rather than the sum of all three.

## The Bug(s)

`shopping_total.py`, line 9: `total = 0.0` sits inside the `for` loop body. Every iteration
wipes the running sum back to zero before adding the current price, so `total` only ever holds the
most recent price.

## Why the Program Behaved Incorrectly

Iteration 1: total = 0 → 4.50. Iteration 2: total = 0 → 2.25. Iteration 3: total = 0 → 10.00.
After the loop, `total` is 10.00 and the tax and grand total are computed from that.

## The Concept This Illustrates

The accumulator pattern: initialize *once* before the loop, update on every iteration, use after
the loop. Indentation determines what is "inside" the loop, so a single misplaced line changes how
many times it runs.

## The Correction

```python
# before
for item in range(1, count + 1):
    total = 0.0
    price = float(input(f"Price of item {item}: $"))
    total = total + price
# after
total = 0.0
for item in range(1, count + 1):
    price = float(input(f"Price of item {item}: $"))
    total = total + price
```

## Instructor Notes

* Ask students what the corrected program prints if `count` is 0. (Subtotal $0.00 — and note that
  the *original* program would crash with NameError there because `total` is never created. Good
  illustration that the initialization also has to exist at all.)
* Some students move `total = 0.0` above the loop but also leave a copy inside; make sure the
  inner one is gone.
* Connect to `staircase_blocks.py` (debug01): same accumulator idea, different mistake.
