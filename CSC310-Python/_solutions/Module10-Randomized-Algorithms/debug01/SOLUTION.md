# Solution: In-Place Random Shuffle With a Tally

**Course/Module/Activity:** CSC310 · Module 10 Randomized Algorithms · debug01
**Bug type(s):** conceptual/design (biased random choice; loop invariant violated)
**Bug count:** 1

## Observed Behavior

```
where 'A' ends up:
  position 0:  33473   (33.47%)
  position 1:  33193   (33.19%)
  position 2:  33334   (33.33%)
  expected about 33333 each; largest deviation 140

permutation frequencies (expected about 16667 each):
  ABC:  15009
  ACB:  18464
  BAC:  18470
  BCA:  18567
  CAB:  14723
  CBA:  14767
  spread between most and least common: 3844
  uniform within 3%: False
```

Positions look uniform, but three permutations occur about 18 500 times and three about 14 900
times: a bias far too large to be noise at this sample size.

## The Bug(s)

`shuffle_tally.py`, function `shuffle`:

```python
for i in range(n):
    j = rng.randint(0, n - 1)
    items[i], items[j] = items[j], items[i]
```

Every iteration swaps position `i` with a position chosen from the *whole* list, `0..n-1`, rather
than from the unfinished suffix `i..n-1`.

## Why the Program Behaved Incorrectly

The loop makes n independent choices among n values, so it has nⁿ equally likely execution paths:
27 for n = 3. There are 3! = 6 permutations, and 27 is not divisible by 6, so the paths cannot be
distributed evenly; enumerating them gives 4, 5, 5, 5, 4, 4 paths for ABC, ACB, BAC, BCA, CAB, CBA,
i.e. probabilities 4/27 ≈ 14.8% and 5/27 ≈ 18.5%, exactly the pattern in the tally. The invariant of
RANDOMIZE-IN-PLACE (before iteration i, `A[0..i-1]` is a uniformly random i-permutation) breaks
because a later swap can pull an already-placed element back out of the prefix. The per-position
marginals happen to be uniform for n = 3, which is why the first tally looks fine.

## The Concept This Illustrates

A uniform random permutation requires n! equally likely outcomes, which is achieved by choosing the
i-th element uniformly from the n − i elements not yet placed (n · (n−1) · … · 1 paths). Choosing
from all n positions every time is the classic "naive shuffle" (the CLRS Section 5.3 exercise on PERMUTE-WITH-ALL is exactly this
PERMUTE-WITH-ALL procedure and asks students to show it is not uniform). The activity also shows why
empirical testing of randomized algorithms must look at the *joint* distribution, not just marginals.

## The Correction

```python
# before
j = rng.randint(0, n - 1)
# after
j = rng.randint(i, n - 1)
```

## Instructor Notes

- Some students change the loop to run more times ("shuffle it twice"). Ask whether 3⁶ = 729 is
  divisible by 6 (it is not) and have them rerun the tally.
- Others propose `j = rng.randint(0, i)` (swap with an earlier or same position). That is a valid
  variant (the "inside-out"/Durstenfeld direction) and the tally will pass; ask them to prove the
  invariant for it.
- The 4/5/5/5/4/4 count is a good ten-minute board exercise: list the 27 triples (j0, j1, j2) and
  apply the swaps.
- Follow-up: why does the CLRS proof that RANDOMIZE-IN-PLACE is uniform (Section 5.3) need the fact that the chosen `j` is uniform
  over `i..n-1` specifically, and what breaks if `randint(i, n - 1)` is replaced by
  `randint(i + 1, n - 1)`? (No element could stay in place.)
