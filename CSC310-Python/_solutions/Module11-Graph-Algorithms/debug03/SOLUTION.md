# Solution: Strongly Connected Components

**Course/Module/Activity:** CSC310 · Module 11 Graph Algorithms · debug03
**Bug type(s):** conceptual/design (second pass searches the wrong graph and takes vertices in the wrong order)
**Bug count:** 2 (related: together they are "the second pass is not the one the theorem is about")

## Observed Behavior

```
CLRS example graph: 3 components
  {h}
  {c, d, f, g}
  {a, b, e}
Three-cycle chain: 3 components
  {6}
  {4, 5}
  {1, 2, 3}
```

`{c, d}` and `{f, g}` are merged into one component. The chain graph happens to come out right apart
from the order in which the components are listed.

## The Bug(s)

`strongly_connected.py`, function `strongly_connected_components`. The transpose is built and then
ignored, and the finishing order is traversed forwards:

```python
def collect(u, comp):
    assigned.add(u)
    comp.append(u)
    for v in adj[u]:              # should follow graph_t[u]
        if v not in assigned:
            collect(v, comp)

for u in finish_order:            # should be reversed(finish_order)
    ...
```

## Why the Program Behaved Incorrectly

The first DFS on the textbook graph finishes vertices in the order `h d f g c e b a`. The buggy second
pass starts from `h` (fine: `{h}` is a sink component), then from `d`, and follows the *original*
edges: `d -> c -> g -> f`, then `g -> h` is already assigned. Nothing stops the search at the boundary
of `{c, d}`, because the edge `c -> g` leaves that component in `G`. The correct algorithm avoids this
in two ways at once. Searching `Gᵀ` reverses every edge, so an edge that *leaves* a component in `G`
*enters* it in `Gᵀ` and the search cannot escape along it. Starting from the vertex with the
*largest* finishing time means starting in a component that has no incoming edges from unexplored
components (the CLRS lemma on finishing times of components: if there is an edge from component C to
component C′, the largest finishing time in C exceeds that in C′). Taking vertices in *increasing*
finishing order sorts components by their *earliest* finish, which has no such property: `d` finishes
second overall even though its component `{c, d}` has an edge into `{f, g}`, whose vertices finish
later. The chain graph is forgiving because its increasing finish order happens to visit sink
components first, so each search on `G` can only spill into already-assigned vertices.

## The Concept This Illustrates

The component graph is a DAG, and decreasing finishing time from the first DFS is a topological order
of it. The second DFS must run on the transpose so that, starting from the source component of that
order, it is confined to a single component: everything reachable in `Gᵀ` from the start vertex is
either in the same component or in a component that was already emptied. Students who search `G`, or
who go through the finishing order the wrong way, have memorized "two DFS passes" without the
argument that makes the second pass stop at component boundaries.

## The Correction

```python
# before
for v in adj[u]:
...
for u in finish_order:

# after
for v in graph_t[u]:
...
for u in reversed(finish_order):
```

## Instructor Notes

- Each fix alone produces a single component containing all eight vertices: reversing the order but
  searching `G` starts from `a`, which reaches everything; searching `Gᵀ` in increasing order starts
  from `h`, from which every vertex is reachable in `Gᵀ`. Have the groups predict both before running.
- Ask students to draw the component graph, label each component with its largest finishing time, and
  check the ordering claim by hand.
- The `sorted(comp)` is only for display; components are sets.
- The Cpp tree's debug03 uses the blueprint's other option (DFS cycle detection with vertex colors).
  Both activities test the same idea — the meaning of gray/black and finishing times — from different
  angles.
