# Solution: Floyd-Warshall All-Pairs Shortest Paths

**Course/Module/Activity:** CSC310 · Module 13 Shortest Paths · debug03
**Bug type(s):** conceptual/design (dynamic-programming stages computed in the wrong order: `k` innermost)
**Bug count:** 1

## Observed Behavior

```
shortest-path weights D:
     0    3    8    2   -4
     3    0   -4    1   -1
     7    4    0    5    3
     2   -1   -5    0   -2
     8    5    1    6    0
sample paths:
  1 to 2: 1 -> 2   (weight 3)
  1 to 3: 1 -> 3   (weight 8)
  5 to 1: 5 -> 4 -> 1   (weight 8)
```

(The weight matrix prints correctly.) Row 1 of `D` keeps the direct edge weights 3 and 8 instead of
the shortest-path weights 1 and −3, and the reconstructed paths for 1 → 2 and 1 → 3 are the direct
edges.

## The Bug(s)

`floyd_warshall.py`, function `floyd_warshall`:

```python
for i in range(n):
    for j in range(n):
        for k in range(n):          # k must be the outermost loop
            if d[i][k] + d[k][j] < d[i][j]:
```

## Why the Program Behaved Incorrectly

With `k` innermost, `d[0][1]` is examined for all five intermediate vertices *before any other entry
has been improved*, then never again. The path 1 → 5 → 4 → 3 → 2 needs `d[4][1]` (vertex 5 to vertex 2)
to be known when `k` = vertex 5 is tried, but row 5 has not been processed yet and `d[4][1]` is still
infinite; likewise `d[0][3]` is still infinite when `k` = vertex 4 is tried for `d[0][1]`. Row 1 is
therefore stuck with whatever can be built from raw edge weights alone. Later rows happen to find their
paths because the entries they need lie in rows or columns that were already improved or are direct
edges — which is luck, not correctness.

## The Concept This Illustrates

Floyd-Warshall is a dynamic program whose stage `k` depends on *all pairs* of stage `k − 1`. The
single in-place matrix is legitimate only because row `k` and column `k` do not change during stage
`k` (a path through `k` cannot shorten a path that ends or starts at `k`), and that argument requires
the whole matrix to move from stage `k − 1` to stage `k` together — i.e. `k` outermost. With `k`
innermost each `d[i][j]` is finalized after a single visit, reading neighbors that are at arbitrary,
mostly unimproved stages, so the values are not `d⁽ᵏ⁾` of anything. The same dependency-order lesson
as LCS and knapsack in Module 9, in three dimensions.

## The Correction

```python
# before
for i in range(n):
    for j in range(n):
        for k in range(n):

# after
for k in range(n):
    for i in range(n):
        for j in range(n):
```

## Instructor Notes

- Once `k` is outermost, the order of `i` and `j` does not matter; have students verify that
  `k, j, i` also produces the expected matrix and explain why.
- Some students propose repeating the wrong triple loop `n` times until nothing changes. On this input
  it converges to the right matrix, but it is Θ(n⁴) and offers no argument for *why* it stops at the
  right answer; contrast with the clean stage argument.
- The predecessor matrix makes the failure visible as paths, not just numbers. Ask what `pred[i][j] =
  pred[k][j]` assumes about the stage of `pred[k][j]`.
- Rows 2–5 being correct is a trap: a test that checked only a few pairs would pass. Ask which pairs
  a good test should include (pairs whose shortest paths need three or more intermediate vertices).
