# Solution: Rod Cutting, Top-Down and Bottom-Up

**Course/Module/Activity:** CSC310 · Module 9 Dynamic Programming · debug03
**Bug type(s):** conceptual/design (memo consulted after the work is done; exponential time)
**Bug count:** 1

## Observed Behavior

The table prints with correct revenues and cuts, but the call counts double at every step, and the
program never finishes the rod of length 30 (it must be interrupted with Ctrl-C):

```
 n  revenue  calls  cuts
 1        1      2  [1]
 2        5      4  [2]
 3        8      8  [3]
 4       10     16  [2, 2]
 5       13     32  [2, 3]
 6       17     64  [6]
 7       18    128  [1, 6]
 8       22    256  [2, 6]
 9       25    512  [3, 6]
10       30   1024  [10]
```

(hangs here: 2³⁰ ≈ 10⁹ calls would be needed)

## The Bug(s)

`rod_cutting.py`, function `_cut_rod_aux`. The memo table is checked *after* the recursive loop
instead of before it:

```python
calls += 1
if n == 0:
    q = 0
else:
    q = float("-inf")
    for i in range(1, n + 1):
        q = max(q, p[i] + _cut_rod_aux(p, n - i, r))
if r[n] >= 0:          # too late: all the work has already been done
    return r[n]
r[n] = q
return q
```

## Why the Program Behaved Incorrectly

The check `if r[n] >= 0: return r[n]` is reached only after every recursive call for this `n` has
already been made. The stored value is therefore never used to *avoid* work; every call to
`_cut_rod_aux(n)` recomputes the full recursion tree, which has 2ⁿ⁻¹ leaves (the recursion-tree count in CLRS Section 14.1).
That is why the `calls` column is exactly 2ⁿ. The results are still correct because the recurrence
itself is right; only the running time is broken, and for n = 30 the ~10⁹ calls take far longer than
anyone will wait. With the check at the top, each subproblem is solved once and the number of calls
is 1 + Σ_{k=1..n} k = 1 + n(n+1)/2.

## The Concept This Illustrates

Dynamic programming pays off because of *overlapping subproblems*: the memo must be consulted before
recursing so that a repeated subproblem costs O(1) instead of a full recursion. Storing results is
necessary but not sufficient. Students holding this bug tend to view the memo as a cache of "the
answer" (which it is) rather than as the mechanism that prunes the recursion tree; the correct
revenues reinforce the illusion that the algorithm works. Counting calls is the honest way to see the
difference between Θ(2ⁿ) and Θ(n²).

## The Correction

```python
# before
calls += 1
if n == 0:
    ...recursion...
if r[n] >= 0:
    return r[n]
r[n] = q

# after
calls += 1
if r[n] >= 0:
    return r[n]
if n == 0:
    ...recursion...
r[n] = q
```

## Instructor Notes

- Students who see the 2ⁿ pattern quickly still need to explain *why* moving three lines changes
  the complexity; make them draw the recursion tree for n = 4 with and without pruning.
- Some students initialize `r` to zeros and use `if r[n] > 0`. It works here only because every
  price is positive; ask what happens with a price list containing zeros and why CLRS uses −∞ as the
  "not yet computed" sentinel.
- Others convert the top-down version into the bottom-up one. Legitimate, but the exercise is about
  understanding memoization; ask them to keep both and make the counts match.
- Follow-up: the corrected top-down version makes 466 calls for n = 30 while the bottom-up loop does
  Θ(n²) work with no calls at all; when is top-down still preferable? (When only a few of the
  subproblems are actually needed.)
