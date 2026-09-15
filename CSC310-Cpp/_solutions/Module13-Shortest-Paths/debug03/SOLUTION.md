# Solution: Floyd-Warshall All-Pairs Shortest Paths

**Course/Module/Activity:** CSC310 · Module 13 Shortest Paths · debug03
**Bug type(s):** conceptual/design (dynamic-programming subproblem order: `k` must be the outermost loop)
**Bug count:** 1

## Observed Behavior

```
shortest-path weights D:
    0    3    8    2   -4
    3    0   -4    1   -1
    7    4    0    5    3
    2   -1   -5    0   -2
    8    5    1    6    0
```

Two entries are wrong: `D[0][1] = 3` (should be 1) and `D[0][2] = 8` (should be -3). Everything else matches.

## The Bug(s)

`floyd_warshall.cpp`, `floydWarshall`, loop nesting:

```cpp
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
            if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
```

The intermediate-vertex loop `k` is innermost. It must be outermost.

## Why the Program Behaved Incorrectly

Floyd-Warshall's stage `k` assumes that `d[i][k]` and `d[k][j]` already hold shortest paths that use intermediates only from `{0..k-1}`—that is what the previous stages computed. With `k` innermost, `d[0][1]` is finalized in the very first iteration of the outer loops, at which point `d[4][3]`, `d[3][2]`, `d[2][1]` are still raw edge weights and `d[0][3]` is still `inf`. The best available through any single `k` is the direct edge 3, so `D[0][1]` stays 3, and `D[0][2]` (which should go `0 -> 4 -> 3 -> 2`) stays at the direct 8. Rows computed later benefit from earlier rows having been improved, which is why most entries happen to be right—but that is luck of the vertex numbering, not correctness.

## The Concept This Illustrates

The order of loops in a dynamic program is the order of *subproblems*, and it must respect their dependencies. In Floyd-Warshall the subproblem is "all pairs, intermediates ≤ k"; every `(i, j)` at stage `k` depends on other pairs at stage `k - 1`, so a whole stage must complete before the next begins—hence `k` outermost. Students who see three interchangeable loops (as in matrix multiplication, where any order works) assume the same here. A quick sanity check: with `k` innermost, `d[i][j]` is written once and never revisited, so it cannot pick up improvements discovered later.

## The Correction

```cpp
for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
```

## Instructor Notes

- Ask students to relabel the vertices (e.g., renumber vertex 0 as vertex 4) and rerun the buggy code: different entries go wrong. Correct code is invariant under relabeling; this is a nice way to show the bug is about order, not about the graph.
- Some students argue the buggy code is "almost right, only two cells". Ask what "almost right" means for a shortest-path algorithm used inside a routing table.
- The `i`/`j` inner order does not matter (any order within a stage works) while `k`'s position does; ask them to explain why this asymmetry exists. (Within a stage the updates only read row `k` and column `k`, which do not change during stage `k`.)
- The `INF` guard prevents `inf + inf` overflow; ask why it is not needed for correctness once the sum is guarded, and what would happen with `INT_MAX` and no guard.
