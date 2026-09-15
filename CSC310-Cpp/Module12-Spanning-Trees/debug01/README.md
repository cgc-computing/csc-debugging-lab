# Kruskal's Minimum Spanning Tree

**Course:** CSC310 &nbsp;|&nbsp; **Module 12:** Spanning Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`kruskal` computes a minimum spanning tree (CLRS 21.2): sort the edges by weight, then accept each edge whose endpoints are currently in different components, using a disjoint-set forest with path compression to track components. The graph is the textbook's nine-vertex example (`a` through `i`, 14 edges). The driver lists the accepted edges, their count, and the total weight.

## Expected Behavior

A spanning tree of 9 vertices has exactly 8 edges; the minimum total weight for this graph is 37. (Ties are broken by vertex order, so this is the exact list.)

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

## How to Run

```bash
g++ -std=c++17 -Wall -o kruskal kruskal.cpp
./kruskal
```

(on Windows: `kruskal.exe` or `.\kruskal.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the disjoint-set forest; do not replace it with a different component-tracking scheme.

## Think About

- In a disjoint-set forest, what does `parent[x]` tell you about the set `x` belongs to—and what does it *not* tell you?
- Two vertices can be in the same component and still have different `parent` entries. Draw the forest after the first six accepted edges and find such a pair among the endpoints of the next edge the program accepts.
- A spanning tree on 9 vertices has 8 edges; the program accepts 12. What must be true about the extra four, and what would happen if you drew the accepted edges?
