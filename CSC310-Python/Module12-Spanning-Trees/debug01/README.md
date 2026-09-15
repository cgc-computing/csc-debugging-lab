# Kruskal's Minimum Spanning Tree

**Course:** CSC310 &nbsp;|&nbsp; **Module 12:** Spanning Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`kruskal.py` computes a minimum spanning tree with Kruskal's algorithm (CLRS Section 21.2): sort the
edges by weight, then accept each edge whose endpoints currently lie in different components, tracking
the components with a disjoint-set forest (union by rank with path compression). The graph is the
textbook's nine-vertex example (`a` through `i`, 14 edges). The `main` block lists the accepted edges,
their count, and their total weight.

## Expected Behavior

```
edges chosen:
  g-h (1)
  c-i (2)
  f-g (2)
  a-b (4)
  c-f (4)
  c-d (7)
  a-h (8)
  d-e (9)
tree edges: 8 (a spanning tree on 9 vertices has 8)
total weight: 37
```

A spanning tree of 9 vertices has exactly 8 edges, and 37 is the minimum total weight for this graph.
Python's sort is stable, so equal weights are considered in the order the edges are listed, and the
corrected program produces exactly this list.

## How to Run

```bash
python3 kruskal.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
disjoint-set forest; do not track components with a dictionary of sets.

## Think About

- In a disjoint-set forest, what does `parent[x]` tell you about `x`, and what does `find(x)` tell
  you? Right after `union(a, b)`, for which vertices are those two things the same and for which are
  they different?
- Process the sorted edges by hand, drawing the forest after each union (union by rank decides which
  root goes under which). When the edge `h-i` is considered, which set is `h` in, which set is `i` in,
  and what two values does the program actually compare?
- What must be true of an edge's two endpoints for adding the edge to be safe, that is, to create no
  cycle? Is "they have different parents" the same statement?
- The program accepts eleven edges. Could this mistake ever make it *reject* an edge it should have
  accepted, or can it only accept edges it should have rejected? Try to argue it either way.
