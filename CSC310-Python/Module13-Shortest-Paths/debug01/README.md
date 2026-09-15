# Dijkstra's Shortest Paths

**Course:** CSC310 &nbsp;|&nbsp; **Module 13:** Shortest Paths &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`dijkstra.py` computes single-source shortest paths (CLRS Section 22.3) on a directed graph with
non-negative edge weights, using `heapq` as the min-priority queue. Because `heapq` has no
decrease-key operation, a vertex is pushed again whenever a shorter path to it is found, so the heap
may hold several entries for the same vertex. The `main` block runs the algorithm on the textbook's
five-vertex example from source `s`, prints each vertex's distance and shortest path, and reports how
many times a vertex was taken off the queue.

## Expected Behavior

```
shortest paths from s
  s: dist 0   path s
  t: dist 8   path s -> y -> t
  x: dist 9   path s -> y -> t -> x
  y: dist 5   path s -> y
  z: dist 7   path s -> y -> z
vertices removed from the queue: 5 (vertices: 5)
```

These are the distances CLRS shows for this graph. Each vertex should be processed exactly once, so
the number of removals equals the number of vertices.

## How to Run

```bash
python3 dijkstra.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
`heapq`-based design with repeated pushes; do not implement decrease-key.

## Think About

- The path printed for `t` is `s -> y -> t`, whose edges weigh 5 and 3. What is its total, what does
  the program print for `dist[t]`, and where can the printed number have come from?
- List every `(distance, vertex)` pair that is pushed onto the heap during the run, in order. Which
  vertices appear more than once? When the *second*, larger entry for such a vertex comes out of the
  heap, what should happen to it?
- In Dijkstra's algorithm, at what moment does a vertex's distance become final? Is there any later
  moment at which the code is allowed to change it?
- The program reports 8 removals for 5 vertices. Do the extra removals merely waste time, or do they
  change the answer? Why?
