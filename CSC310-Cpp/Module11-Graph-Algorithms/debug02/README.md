# Topological Sort by Depth-First Search

**Course:** CSC310 &nbsp;|&nbsp; **Module 11:** Graph Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`topologicalSort` orders the vertices of a directed acyclic graph so that every edge `u -> v` has `u` before `v`, using the DFS method from CLRS 20.4. The example is the textbook's getting-dressed graph (an edge means "put this on first"). After producing an order the driver checks every edge and reports any that point backwards.

## Expected Behavior

Many valid orders exist; the one produced by DFS in vertex-index order with the given adjacency lists is:

```
order: watch socks shirt tie undershorts pants shoes belt jacket
valid topological order
```

## How to Run

```bash
g++ -std=c++17 -Wall -o topological_sort topological_sort.cpp
./topological_sort
```

(on Windows: `topological_sort.exe` or `.\topological_sort.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the DFS approach.

## Think About

- In a depth-first search, at what moment do you know that *everything reachable* from a vertex has already been dealt with: when the vertex is first visited, or when its recursive call returns?
- The list is reversed at the end. Why does the correct algorithm need that reversal, and what does the reversal produce if vertices were recorded at the wrong moment?
- Look at the violated edge `undershorts -> pants` in the buggy output. In which order did DFS *visit* those two vertices, and in which order did their calls *finish*?
