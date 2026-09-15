# Campus Walkway Graph

**Course:** CSC205 &nbsp;|&nbsp; **Module 14:** Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

Seven campus buildings are vertices in an **undirected** graph; each walkway between two buildings is an edge. The graph is stored as an adjacency list. The driver runs breadth-first search from three different buildings and lists every building reachable from each, in BFS order.

```
Library - Science      Science - Gym      Gym - Dorms
Library - Union        Union - Gym        Annex - Garage
```

## Expected Behavior

```
From Library (5 reachable): Library Science Union Gym Dorms
From Dorms (5 reachable): Dorms Gym Science Union Library
From Annex (2 reachable): Annex Garage
```

## How to Run

```bash
g++ -std=c++17 -Wall -o campus_graph campus_graph.cpp
./campus_graph
```
(on Windows: `campus_graph.exe` or `.\campus_graph.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The `bfs` function is correct; look at how the graph is built.

## Think About

- In an undirected graph, if there is a walkway from Library to Science, what must also be true about Science? How is that fact represented in an adjacency list?
- Write out the seven adjacency lists as they exist after the six `addEdge` calls. Which lists are empty? Should any of them be?
- Why does the search from Library produce the right answer while the search from Dorms does not?
