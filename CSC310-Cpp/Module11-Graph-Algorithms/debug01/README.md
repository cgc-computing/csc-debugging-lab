# Breadth-First Search Distances

**Course:** CSC310 &nbsp;|&nbsp; **Module 11:** Graph Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`bfs` runs breadth-first search (CLRS 20.2) from a source vertex on an undirected graph. For every vertex it computes the distance in edges from the source and the parent in the BFS tree, and it counts how many times any vertex was placed in the queue. The graph is the textbook's eight-vertex example (vertices `r s t u v w x y`), with source `s`.

## Expected Behavior

Each vertex is enqueued exactly once, so the count equals the number of reachable vertices.

```
BFS from s
  r: dist 1, parent s
  s: dist 0, parent -
  t: dist 2, parent w
  u: dist 3, parent t
  v: dist 2, parent r
  w: dist 1, parent s
  x: dist 2, parent w
  y: dist 3, parent x
vertices enqueued: 8
```

## How to Run

```bash
g++ -std=c++17 -Wall -o bfs_distances bfs_distances.cpp
./bfs_distances
```

(on Windows: `bfs_distances.exe` or `.\bfs_distances.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the queue-based structure.

## Think About

- When should a vertex be marked as discovered: when it is placed in the queue, or when it is removed from the queue? What can happen to that vertex in between?
- Vertex `x` is adjacent to both `w` and `t`. Which of those two is dequeued first, and which one should be recorded as `x`'s parent?
- A BFS on 8 vertices should enqueue 8 times. Where do the extra enqueues in the buggy run come from, and how does each one affect the recorded distance?
