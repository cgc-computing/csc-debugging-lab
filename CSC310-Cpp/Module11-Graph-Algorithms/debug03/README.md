# Detecting a Cycle in a Directed Graph

**Course:** CSC310 &nbsp;|&nbsp; **Module 11:** Graph Algorithms &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

`Detector` uses depth-first search (CLRS 20.3) to decide whether a directed graph contains a cycle: a graph is cyclic exactly when DFS finds a *back edge*—an edge to a vertex that is still on the recursion stack. When a cycle exists the program prints it by reading the current DFS path. The driver tests two acyclic graphs and two cyclic ones.

## Expected Behavior

```
diamond: no cycle (graph is a DAG)
prerequisites: no cycle (graph is a DAG)
ring road: cycle found: 1 2 3 1
self loop: cycle found: 1 1
```

## How to Run

```bash
g++ -std=c++17 -Wall -o cycle_detection cycle_detection.cpp
./cycle_detection
```

(on Windows: `cycle_detection.exe` or `.\cycle_detection.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the recursive DFS and the path-based cycle printing.

## Think About

- During a DFS, a vertex is in one of three situations: never seen, currently on the recursion stack, or completely finished. An edge to a vertex in which of those situations closes a cycle?
- In the diamond graph (`0 -> 1`, `0 -> 2`, `1 -> 3`, `2 -> 3`), when the search at `2` examines the edge `2 -> 3`, what has already happened to `3`? Is there any path from `3` back to `2`?
- The buggy program's "cycle" for the diamond is a single vertex. What does that say about the path it tried to reconstruct, and how does it relate to your answer above?
