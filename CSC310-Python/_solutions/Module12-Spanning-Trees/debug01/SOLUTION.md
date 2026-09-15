# Solution: Kruskal's Minimum Spanning Tree

**Course/Module/Activity:** CSC310 · Module 12 Spanning Trees · debug01
**Bug type(s):** conceptual/design (comparing parent pointers instead of set representatives)
**Bug count:** 1

## Observed Behavior

```
edges chosen:
  g-h (1)
  c-i (2)
  f-g (2)
  a-b (4)
  c-f (4)
  c-d (7)
  h-i (7)
  a-h (8)
  b-c (8)
  d-e (9)
  e-f (10)
tree edges: 11 (a spanning tree on 9 vertices has 8)
total weight: 62
```

Three extra edges (`h-i`, `b-c`, `e-f`) are accepted, each of which closes a cycle.

## The Bug(s)

`kruskal.py`, function `kruskal`:

```python
if ds.parent[u] != ds.parent[v]:      # should compare ds.find(u) and ds.find(v)
```

The test reads the raw parent pointers instead of asking the disjoint-set structure for the two
representatives.

## Why the Program Behaved Incorrectly

After the first five accepted edges the forest has root `c` with children `i` and `g`, and `g` has
children `h` and `f` (union by rank put `g` under `c` when the two ranks tied). So `parent[h]` is `g`
while `parent[i]` is `c`: both vertices are in `c`'s set, but their parent pointers differ, and the edge
`h-i` is accepted, closing the cycle `h-g-c-i-h`. The same thing happens for `b-c` (`parent[b]` is `a`,
which by then hangs under `c`) and `e-f`. The `union` calls themselves are correct, so the sets are
right; only the membership test is wrong. Note that the mistake can only *add* bad edges: if two
vertices have the same parent they certainly have the same root, so no good edge is ever rejected.

## The Concept This Illustrates

In a disjoint-set forest the identity of a set is its *root*, reached by `find`; parent pointers are
an implementation detail that union by rank and path compression deliberately leave un-normalized
(that is what makes the operations fast). Students who compare `parent[u]` with `parent[v]` are
treating the structure like the naive "label per element" representation, in which every member
stores the set's name directly. Kruskal's correctness rests on the safe-edge test "endpoints in
different trees of the forest", and that test is exactly `FIND-SET(u) ≠ FIND-SET(v)`.

## The Correction

```python
# before
if ds.parent[u] != ds.parent[v]:

# after
if ds.find(u) != ds.find(v):
```

## Instructor Notes

- Some students will "fix" the problem by making `union` relabel every member of the absorbed set
  (a loop over all vertices). The output becomes correct, but ask what path compression and union by
  rank are for if `find` is never called.
- Others will call `find` once for every vertex *before* the loop and cache the roots. Roots change
  after every union, so that fails on the same edges; it is a good chance to discuss when a cached
  value is invalidated.
- The extra-edge count is the giveaway: any group that notices "a tree on 9 vertices cannot have 11
  edges" has the right instinct even before reading the code.
- Follow-up: compare with Prim's tree in debug02. Both weigh 37, but Kruskal picks `a-h (8)` while Prim
  picks `b-c (8)`. Why are both minimum spanning trees, and when is the MST unique?
