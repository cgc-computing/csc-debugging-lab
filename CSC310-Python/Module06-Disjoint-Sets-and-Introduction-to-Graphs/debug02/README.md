# Undirected Graph as Adjacency Lists

**Course:** CSC310 &nbsp;|&nbsp; **Module 6:** Disjoint Sets and Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`undirected_graph.py` stores an undirected graph as adjacency lists (CLRS Section 20.1) and offers
degree, edge count, edge test, conversion to an adjacency matrix, and a symmetry check. The `main`
block builds the five-vertex, seven-edge example graph of CLRS Section 20.1 and prints all of those views.

## Expected Behavior

```
adjacency lists:
  1: [2, 5]
  2: [1, 5, 4, 3]
  3: [2, 4]
  4: [2, 3, 5]
  5: [1, 2, 4]

degrees        : [2, 4, 2, 3, 3]
sum of degrees : 14
edge count     : 7
has_edge(2, 5) : True
has_edge(5, 2) : True
has_edge(1, 3) : False

adjacency matrix:
  0 1 0 0 1
  1 0 1 1 1
  0 1 0 1 0
  0 1 1 0 1
  1 1 0 1 0
symmetric      : True
```

## How to Run

```bash
python3 undirected_graph.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
adjacency-list representation.

## Think About

- In an undirected graph, how many adjacency lists should the edge {2, 5} appear in? Count how many
  it appears in here.
- The handshake lemma says the degrees of all vertices sum to twice the number of edges. Check the
  program's `sum of degrees` and `edge count` against each other; are they consistent with that lemma?
- The edge count is printed correctly even though the degrees are not. Once you make the degrees
  right, what happens to the edge count, and why?
- What does it mean for the adjacency matrix of an undirected graph to be symmetric, and how does
  that relate to the way edges are stored in the lists?
