# Dijkstra's Shortest Paths

**Course:** CSC310 &nbsp;|&nbsp; **Module 13:** Shortest Paths &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`dijkstra` computes single-source shortest paths (CLRS 22.3) on a directed graph with non-negative weights, using `std::priority_queue` as the min-priority queue with lazy deletion (an outdated entry is simply skipped when it comes out). The graph is the textbook's five-vertex example with source `s`. The driver prints each vertex's distance and the shortest path to it.

## Expected Behavior

```
shortest paths from s
  s: dist 0   path s
  t: dist 8   path s -> y -> t
  x: dist 9   path s -> y -> t -> x
  y: dist 5   path s -> y
  z: dist 7   path s -> y -> z
```

## How to Run

```bash
g++ -std=c++17 -Wall -o dijkstra dijkstra.cpp
./dijkstra
```

(on Windows: `dijkstra.exe` or `.\dijkstra.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the lazy-deletion priority-queue design.

## Think About

- In Dijkstra's algorithm, at what moment is a vertex's distance guaranteed final: when the vertex is first reached, or when it is extracted as the current minimum? What is the argument?
- `t` is first reached directly from `s` with weight 10, but a cheaper route through `y` exists. What in the program prevents that cheaper route from ever being recorded?
- With a binary heap and lazy deletion, the same vertex can sit in the queue several times with different distances. When one of those entries is popped, how can the algorithm tell whether it is still meaningful?
