# Strongly Connected Components

**Course:** CSC310 &nbsp;|&nbsp; **Module 11:** Graph Algorithms &nbsp;|&nbsp; **Activity:** debug03
**Language:** Python 3

## Goal

`strongly_connected.py` implements the two-pass algorithm STRONGLY-CONNECTED-COMPONENTS of CLRS
Section 20.5: one depth-first search of `G` to obtain finishing times, construction of the transpose
graph, and a second depth-first search whose trees are exactly the components. The `main` block runs
it on the textbook's eight-vertex example graph and on a small chain of cycles, printing each
component as a sorted set.

## Expected Behavior

```
CLRS example graph: 4 components
  {a, b, e}
  {c, d}
  {f, g}
  {h}
Three-cycle chain: 3 components
  {1, 2, 3}
  {4, 5}
  {6}
```

Components are listed in the order the second search discovers them. For this algorithm that order is
a topological order of the component graph: a component appears before every component it has edges
into.

## How to Run

```bash
python3 strongly_connected.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the two-pass
structure; do not switch to Tarjan's single-pass algorithm.

## Think About

- Why does the algorithm construct the transpose at all? If the second search followed the original
  edges, what would stop it from wandering out of one component and into the next?
- In the first graph, `{c, d}` and `{f, g}` are distinct components, yet the current output merges them.
  Which edges join those two groups, and in which direction do they point?
- The second search takes vertices in an order derived from the first search's finishing times. Think
  about the vertex that finished *last* and the vertex that finished *first*: which of them is
  guaranteed to sit in a component with no edges arriving from components not yet explored? Which
  direction through the finishing order does that suggest, on which graph?
- The second graph comes out with the right components even in the program as given, only listed in a
  different order. What is it about that graph's shape that makes it forgiving?
