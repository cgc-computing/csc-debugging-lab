# Router Hop Counts with BFS

**Course:** CSC205 &nbsp;|&nbsp; **Module 14:** Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`Graph.bfsDistances` runs breadth-first search from a source router and returns, for every router, the number of hops (edges) on a shortest path from the source. It also records every vertex in the order it is taken off the queue. `Main` builds a seven-link network of five routers and reports hop counts from router 0.

```
      1 ------ 3
     /|       /|
    / |      / |
   0  |     /  |
    \ |    /   |
     \|   /    |
      2 -------4
```

Edges: 0–1, 0–2, 1–2, 1–3, 2–3, 2–4, 3–4.

## Expected Behavior

Each vertex is dequeued exactly once, in BFS order, and the distances are the true shortest-path lengths:

```
dequeue order: [0, 1, 2, 3, 4]
vertices dequeued: 5
hops to 0: 0
hops to 1: 1
hops to 2: 1
hops to 3: 2
hops to 4: 2
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The graph is built correctly; the problem is in the search.

## Think About

- In BFS, at what moment should a vertex be marked so that it can never be added to the queue again: when it is *discovered* or when it is *processed*? What can happen in between?
- Vertex 2 is a direct neighbor of 0, yet it is reported two hops away. Trace the first few iterations of the loop and find where `dist[2]` gets overwritten.
- Why are eleven items dequeued from a graph with five vertices?
- BFS guarantees shortest paths because of the order in which vertices are discovered. Which line's placement breaks that guarantee here?
