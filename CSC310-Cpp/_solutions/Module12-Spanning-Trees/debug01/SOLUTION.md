# Solution: Kruskal's Minimum Spanning Tree

**Course/Module/Activity:** CSC310 · Module 12 Spanning Trees · debug01
**Bug type(s):** logic (compares parent pointers instead of set representatives)
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
  b-h (11)
tree edges: 12 (a spanning tree on 9 vertices has 8)
total weight: 73
```

Twelve edges are accepted—four of them (`h-i`, `b-c`, `e-f`, `b-h`) close cycles—and the total is 73 instead of 37.

## The Bug(s)

`kruskal.cpp`, `kruskal`, the acceptance test:

```cpp
if (parent[e.u] != parent[e.v]) {
```

It compares the two endpoints' *parent pointers*. The test must compare their *representatives*, `find(parent, e.u) != find(parent, e.v)`.

## Why the Program Behaved Incorrectly

`parent[x]` is only the next node on the way to the root; two nodes in the same tree usually have different parents. Trace the first six accepted edges (`unite` hangs the first root under the second): `g-h` → `parent[g] = h`; `c-i` → `parent[c] = i`; `f-g` → `parent[f] = h`; `a-b` → `parent[a] = b`; `c-f` → `parent[i] = h`; `c-d` → `find(c)` compresses `parent[c] = h`, then `parent[h] = d`. Now `h-i` arrives: `parent[h] = d` and `parent[i] = h` are different, so the edge is accepted—but both are in the tree rooted at `d`. The same happens for `b-c`, `e-f`, and `b-h`. Each wrongly accepted edge adds weight and a cycle, and `unite` on two nodes already in the same set does nothing, so the damage is silent.

## The Concept This Illustrates

Kruskal's correctness rests on "accept the edge iff its endpoints are in different components", and in a disjoint-set forest *component identity is the root*, reachable only through `find`. The parent pointer of a non-root node is an implementation detail whose value depends on the history of unions and on path compression. Students who used `parent[]` as a "component label" in a simpler labeling scheme carry that mental model into union-find; this bug is the direct cousin of the Module 6 mistake of linking `parent[x] = y` without finding roots.

## The Correction

```cpp
if (find(parent, e.u) != find(parent, e.v)) {
    tree.push_back(e);
    unite(parent, e.u, e.v);
}
```

## Instructor Notes

- Some students "fix" it by making `unite` relabel every node in the merged set to share one root (turning `parent` into a component label). That yields correct output but O(V) per union; ask them to compare with the near-constant amortized cost of union by rank + path compression.
- Others switch the test to `find(...)` but then "simplify" `unite` to `parent[e.u] = e.v` (linking the elements instead of their roots). On this graph that still accepts 12 edges with total 68, because relinking a non-root detaches part of its set. Make them trace one union.
- Ask what the accepted edge list looks like if you *draw* it: the four extra edges each close a cycle, so the program has built a connected graph with cycles, not a tree.
- The comparator breaks weight ties by `(u, v)`, so the expected list is deterministic; students whose tie order differs may get an equally valid MST with the same total 37.
