# Solution: Randomized Select

**Course/Module/Activity:** CSC310 · Module 3 Sorting Lower Bounds and Order Statistics · debug02
**Bug type(s):** boundary (off-by-one in a count)
**Bug count:** 1

## Observed Behavior

With the fixed seed, every answer is one rank too high (some values repeat because two requests
land on the same element):

```
   1-th smallest:   3   expected   1   MISMATCH
   2-th smallest:   4   expected   3   MISMATCH
   3-th smallest:   8   expected   4   MISMATCH
   4-th smallest:   8   expected   5   MISMATCH
   5-th smallest:  12   expected   7   MISMATCH
   6-th smallest:  12   expected   8   MISMATCH
   7-th smallest:  19   expected  12   MISMATCH
   8-th smallest:  19   expected  15   MISMATCH
   9-th smallest:  26   expected  19   MISMATCH
  10-th smallest:  26   expected  26   ok

all order statistics correct: False
median (i = (n+1)//2): 15
```

With other seeds or inputs the same bug can also produce `ValueError: empty range for randrange()`
when the overshooting rank drives the recursion into an empty sub-list.

## The Bug(s)

`randomized_select.py`, function `randomized_select`:

```python
k = q - p                    # number of elements in the low side plus pivot
```

The number of elements in `A[p..q]` (inclusive) is `q - p + 1`, so `k` is one too small.

## Why the Program Behaved Incorrectly

`k` is supposed to be the rank of the pivot within the current sub-list. With `k` one too small,
the test `i == k` fires when the pivot is actually the (i+1)-th smallest, so the function returns the
element one rank above the one requested. When the algorithm recurses to the right it subtracts the
too-small `k`, so the requested rank in the right side is one too large as well. The error is
consistent in direction, which is why every printed answer is the *next* order statistic. The 10th
request happens to be correct only because the overshoot lands on the maximum from a position where
nothing larger exists.

## The Concept This Illustrates

Inclusive index ranges have `hi - lo + 1` elements, and the recursion in RANDOMIZED-SELECT depends
on translating between a *position* (`q`) and a *rank* (`k`) precisely. The same care is needed in
binary search, quickselect, and median-of-medians. The consistent "one rank too high" pattern in the
output is the classic fingerprint of an off-by-one, and students should learn to read it as such.

## The Correction

```python
# before
k = q - p
# after
k = q - p + 1
```

## Instructor Notes

- Some students instead change `if i == k` to `if i == k + 1` or `i - 1 == k`, leaving the
  right-recursion `i - k` inconsistent. Ask them to trace a request that goes right (e.g., the 9th
  smallest).
- Others change the base case to `if p >= r` to make crashes go away on other inputs; point out that
  this hides an invalid range instead of preventing it.
- Have students change the seed to 9 and observe the `ValueError`; ask them to explain how a rank
  error turns into an empty range.
- Nice follow-up: ask why the expected running time is linear even though each partition is
  O(n), and what the worst case is.
