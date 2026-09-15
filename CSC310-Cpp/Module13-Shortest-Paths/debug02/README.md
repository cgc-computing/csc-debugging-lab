# Bellman-Ford with Negative Edges

**Course:** CSC310 &nbsp;|&nbsp; **Module 13:** Shortest Paths &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`bellmanFord` computes single-source shortest paths on a directed graph that may contain negative edge weights (CLRS 22.1). It performs repeated passes that relax every edge, then makes one more check to see whether any edge can still be relaxed—if so, a negative-weight cycle is reachable from the source and no shortest paths exist. The driver runs it on the textbook example, on a simple chain whose edges happen to be listed from the far end back toward the source, and on a graph that really does contain a negative cycle.

## Expected Behavior

```
textbook graph: distances from 0: 0=0 1=2 2=4 3=7 4=-2
chain: distances from 0: 0=0 1=1 2=2 3=3 4=4
bad loop: negative-weight cycle reachable from the source
```

## How to Run

```bash
g++ -std=c++17 -Wall -o bellman_ford bellman_ford.cpp
./bellman_ford
```

(on Windows: `bellman_ford.exe` or `.\bellman_ford.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the pass-then-check structure.

## Think About

- A shortest path in a graph with `n` vertices uses at most how many edges? How many full passes over the edge list guarantee that every such path has been fully relaxed, *no matter the order in which edges are listed*?
- In the chain graph the edges are listed from the far end toward the source. After one pass, which distances are known? After two? How many passes does the last vertex need?
- The negative-cycle check asks whether *any* edge can still be relaxed after the main passes. What does a "yes" prove—and what assumption about the main passes does that proof depend on?
