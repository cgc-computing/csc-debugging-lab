# Prim's Minimum Spanning Tree

**Course:** CSC310 &nbsp;|&nbsp; **Module 12:** Spanning Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`prim.py` grows a minimum spanning tree from vertex `a` with Prim's algorithm (CLRS Section 21.2),
using `heapq` as the min-priority queue with lazy deletion (an outdated heap entry is skipped when it
comes out). For every vertex `v` not yet in the tree, `key[v]` is the weight of the lightest edge that
connects `v` to the tree built so far; the vertex with the smallest key joins next. The graph is the
textbook's nine-vertex example. The `main` block prints each tree edge as parent–child with its
weight, then the total weight.

## Expected Behavior

```
tree edges (parent-child):
  a-b (4)
  b-c (8)
  c-d (7)
  d-e (9)
  c-f (4)
  f-g (2)
  g-h (1)
  c-i (2)
total weight: 37
```

Every printed weight is the weight of a real edge of the graph, and 37 is the minimum total for this
graph. Ties between equal keys are broken by vertex name, so the corrected program produces exactly
these edges.

## How to Run

```bash
python3 prim.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
heap-based design; do not rewrite it with a linear scan for the minimum key.

## Think About

- What is `key[v]` supposed to measure: a property of one edge, or of a whole route back to the root?
  Read the Goal again, then read the update inside the loop and say in words what value it stores.
- The current output prints `b-c (12)`. Is there an edge of weight 12 between `b` and `c`? Where does 12
  come from?
- Prim's greedy step adds the light edge crossing the cut between the tree and the rest of the graph.
  Which value in the program's state is meant to hold, for each `v` outside the tree, the weight of the
  lightest edge crossing to `v`? Does the program as given ever store that value?
- The tree the program builds is not random: it is the tree of cheapest routes from `a`. Sketch a three-vertex
  graph in which "cheapest route from the root" and "cheapest edge into the tree" pick different edges.
