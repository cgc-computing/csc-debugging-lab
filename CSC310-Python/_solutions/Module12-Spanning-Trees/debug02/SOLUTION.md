# Solution: Prim's Minimum Spanning Tree

**Course/Module/Activity:** CSC310 · Module 12 Spanning Trees · debug02
**Bug type(s):** conceptual/design (key updated with a path weight instead of an edge weight)
**Bug count:** 1

## Observed Behavior

```
tree edges (parent-child):
  a-b (4)
  b-c (12)
  c-d (19)
  f-e (21)
  g-f (11)
  h-g (9)
  a-h (8)
  c-i (14)
total weight: 98
```

The printed "weights" are not edge weights (there is no edge of weight 12, 19 or 21), the tree is a
different tree (`a-h`, `h-g`, `g-f`, `f-e` instead of `c-f`, `f-g`, `g-h`, `d-e`), and the total is 98.

## The Bug(s)

`prim.py`, function `prim`, the relaxation step:

```python
if not in_tree[v] and key[u] + w < key[v]:
    key[v] = key[u] + w
```

The key is being accumulated along the path from the root, so `key[v]` becomes the distance from `a`
to `v` rather than the weight of the edge that would attach `v` to the tree.

## Why the Program Behaved Incorrectly

With `key[v] = key[u] + w`, the vertex extracted next is the one *closest to `a` along some path*, and
its parent is the previous vertex on that path. That is a shortest-path tree rooted at `a`, not a
minimum spanning tree: `c` is attached through `b` because the route `a-b-c` (4 + 8 = 12) is shorter
than any other route to `c`, even though the edge `c-f (4)` would attach `c` far more cheaply once `f`
is in the tree. The actual weight of the tree the program built is 42; the printed 98 is the sum of the
route lengths, so the output is wrong in two different ways at once.

## The Concept This Illustrates

Prim's algorithm is greedy on the *cut*: at each step it adds the lightest edge with exactly one
endpoint in the tree, and `key[v]` is the weight of the lightest such edge for `v`. How far `v` ends up
from the root is irrelevant. The code skeleton is nearly identical to Dijkstra's algorithm (which
students meet in Module 13), and the two differ in exactly this one term of the relaxation. A student
who writes `key[u] + w` has the shortest-path picture in mind and has not internalized that a spanning
tree minimizes total edge weight, not distances.

## The Correction

```python
# before
if not in_tree[v] and key[u] + w < key[v]:
    key[v] = key[u] + w

# after
if not in_tree[v] and w < key[v]:
    key[v] = w
```

## Instructor Notes

- The buggy program is a correct single-source shortest-path algorithm. Tell students they have
  "written Dijkstra by accident" and come back to it in Module 13; it is a memorable contrast.
- Ask them to compute the real weight of the wrong tree (42) and compare with the printed total (98):
  two different numbers, both wrong for different reasons.
- Keep the `not in_tree[v]` test. Without it, a vertex already in the tree can have its key and parent
  rewritten later (for example `c`'s key drops to 2 when `i` joins), and the printed total becomes 28
  for a "tree" that is no longer one. This is a good extension question: why does CLRS's condition
  include `v ∈ Q`?
- The heap holds `(key, vertex)` tuples, so ties are broken alphabetically; that is why `c` is chosen
  before `h` when both have key 8.
