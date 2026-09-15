# Solution: Reservoir Sampling From a Stream

**Course/Module/Activity:** CSC310 · Module 10 Randomized Algorithms · debug02
**Bug type(s):** boundary (off-by-one in the range of a random draw), conceptual/design
**Bug count:** 1

## Observed Behavior

```
sample 1 of 4 items, 40000 trials, expected about 10000 selections each
  item  1:      0   ( 0.00%)
  item  2:  13365   (33.41%)
  item  3:  13327   (33.32%)
  item  4:  13308   (33.27%)
  largest deviation from expected: 10000 (100.0%)

sample 3 of 10 items, 40000 trials, expected about 12000 selections each
  item  1:   8984   ( 7.49%)
  item  2:   8833   ( 7.36%)
  item  3:   8820   ( 7.35%)
  item  4:  13206   (11.01%)
  ...
  item 10:  13396   (11.16%)
  largest deviation from expected: 3180 (26.5%)
```

Item 1 is never chosen with k = 1; with k = 3 the first three items are chosen about 7.4% of the time
and the rest about 11.1%.

## The Bug(s)

`reservoir_sampling.py`, function `reservoir_sample`:

```python
j = rng.randrange(t - 1)
if j < k:
    reservoir[j] = item
```

`randrange(t - 1)` yields `t - 1` equally likely values (0 .. t-2) instead of `t` values (0 .. t-1).

## Why the Program Behaved Incorrectly

The replacement probability is `P(j < k) = k / (number of values j can take)`. With `t - 1` values
the probability is k/(t−1) instead of k/t. For k = 1, the second item (t = 2) draws from
`randrange(1)`, which is always 0, so it replaces item 1 with certainty; item 1 can never survive.
In general each later item is slightly too likely to enter the reservoir and to evict what is there,
so the early items (which must survive every later step) are under-represented. Algorithm R's proof
is an induction: after t items, each has probability k/t of being in the reservoir; the inductive
step needs the new item to enter with probability exactly k/t and each old occupant to be evicted with
probability exactly (k/t)(1/k) = 1/t. With k/(t−1) the product telescopes to the wrong value.

## The Concept This Illustrates

Randomized algorithms are correct only if the probabilities match the analysis exactly, and those
probabilities are implemented through the *size of the range* of a random draw. Python's
`randrange(n)` covers `0..n-1` and `randint(a, b)` covers `a..b` inclusive; mixing up which bound
is exclusive is an off-by-one that produces no error message, only a skewed distribution. Empirical
tallies with a fixed seed are the debugging tool for this class of bug.

## The Correction

```python
# before
j = rng.randrange(t - 1)
# after
j = rng.randrange(t)          # uniform over 0 .. t-1, so P(j < k) = k/t
```

## Instructor Notes

- Some students change `enumerate(stream, start=1)` to start at 0 and keep `randrange(t - 1)`; that
  makes the draw `randrange(-1)` fail or the fill phase off by one. Ask them to write down, for each
  `t`, how many items have been seen and what the range should be.
- Others switch to `rng.random() < k / t` and then pick a slot with `randrange(k)`. That is correct
  (two draws instead of one); ask them to show the two versions have identical probabilities.
- Have students compute P(item 1 survives) for n = 4, k = 1: correct rule (1/2)(2/3)(3/4) = 1/4;
  program's rule (0)(...) = 0.
- Follow-up: the algorithm is Θ(n) random draws. Mention Algorithm L (skip counts) as the way to
  reduce draws when k ≪ n.
