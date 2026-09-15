# Solution: Bellman-Ford with Negative Edges

**Course/Module/Activity:** CSC310 · Module 13 Shortest Paths · debug02
**Bug type(s):** boundary (one relaxation pass too few, so the negative-cycle check fires on an unfinished graph)
**Bug count:** 1

## Observed Behavior

```
textbook graph: distances from 0: 0=0 1=2 2=4 3=7 4=-2
chain: negative-weight cycle reachable from the source
bad loop: negative-weight cycle reachable from the source
```

The chain — a plain path with positive weights — is reported as containing a negative-weight cycle.

## The Bug(s)

`bellman_ford.py`, function `bellman_ford`:

```python
for _ in range(1, n - 1):        # |V| - 2 passes; CLRS's "for i = 1 to |V| - 1" is |V| - 1 passes
    for u, v, w in edges:
        ...
```

`range(1, n - 1)` produces `n − 2` values, one pass short.

## Why the Program Behaved Incorrectly

The chain's edges are listed `(3,4), (2,3), (1,2), (0,1)`. In pass 1 only `0 -> 1` can relax (every
other tail is still at infinity); pass 2 relaxes `1 -> 2`, pass 3 relaxes `2 -> 3`. With five vertices
the program performs only three passes, so `dist[4]` is still infinite when the check runs, `3 -> 4`
is found relaxable, and a negative cycle is reported. The textbook graph escapes because its edges are
listed source-first and it converges in three passes anyway; the genuinely bad graph is reported
correctly for the wrong reason (it would be reported by any number of passes).

## The Concept This Illustrates

The path-relaxation property (CLRS Chapter 22, properties of shortest paths): if the edges of a
shortest path are relaxed in order, one per pass, the path is correct after as many passes as it has
edges. A shortest path has at most |V| − 1 edges, so |V| − 1 passes are needed in the worst case, and
*only after all of them* does "an edge can still be relaxed" mean "negative cycle". An adversarial edge
order — exactly what the chain provides — needs every one of those passes. The secondary lesson is the
translation of an inclusive pseudocode bound (`to |V| − 1`) into Python's exclusive `range`.

## The Correction

```python
# before
for _ in range(1, n - 1):

# after
for _ in range(1, n):            # or range(n - 1): |V| - 1 passes
```

## Instructor Notes

- Students often propose `range(n)` (|V| passes). The output is correct and the extra pass is harmless
  but wasted; ask them to justify the exact count from the path-relaxation property rather than by
  "adding one until it works".
- A common optimization is to stop early when a pass changes nothing. Ask how many passes the chain
  takes under that rule (four, plus the check) and whether early exit can ever be wrong (no).
- Have a group reorder the chain's edges source-first and watch the buggy program "work". That is the
  point: correctness may not depend on edge order, and a test set should include an adversarial order.
- The check pass is itself the |V|-th pass; some students find it clearer to write |V| passes and
  treat a change in the last one as the signal. That is also correct — the classic error is stopping
  one pass early and treating a change in the (|V| − 1)-th pass as the signal.
