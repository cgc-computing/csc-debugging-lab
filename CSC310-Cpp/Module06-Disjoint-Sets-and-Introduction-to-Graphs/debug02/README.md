# Undirected Graph with Adjacency Lists

**Course:** CSC310 &nbsp;|&nbsp; **Module 6:** Disjoint Sets and Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`Graph` stores an undirected graph as a vector of adjacency lists. The driver builds a five-vertex graph from six edges, prints every vertex's degree and neighbor list, reports the number of edges (using the handshaking lemma), and checks whether the graph is connected with a depth-first walk from vertex 0.

## Expected Behavior

The graph has edges 0–1, 1–2, 2–0, 3–1, 4–3 and 4–2, so degrees are 2, 3, 3, 2, 2, there are 6 edges, and every vertex is reachable from vertex 0.

```
vertex 0: degree 2, neighbors 1 2
vertex 1: degree 3, neighbors 0 2 3
vertex 2: degree 3, neighbors 1 0 4
vertex 3: degree 2, neighbors 1 4
vertex 4: degree 2, neighbors 3 2
edges: 6
connected: yes
```

## How to Run

```bash
g++ -std=c++17 -Wall -o undirected_graph undirected_graph.cpp
./undirected_graph
```

(on Windows: `undirected_graph.exe` or `.\undirected_graph.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the adjacency-list representation.

## Think About

- In an undirected graph, if 1 appears in vertex 0's neighbor list, what must appear in vertex 1's list?
- The handshaking lemma relates the sum of all degrees to the number of edges. What exactly is that relationship, and does the program's `edgeCount` respect it?
- The buggy program prints the right edge count. Why is that a coincidence rather than evidence that the code is correct?
