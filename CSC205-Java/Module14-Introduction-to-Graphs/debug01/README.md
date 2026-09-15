# Campus Shuttle Map with BFS

**Course:** CSC205 &nbsp;|&nbsp; **Module 14:** Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`Graph` stores an **undirected** graph as adjacency lists and offers `bfsOrder`, which returns the vertices in the order breadth-first search first reaches them. `Main` builds a five-stop shuttle map with the edges 0–1, 0–2, 1–3, 2–3, 3–4, prints the adjacency lists, and runs BFS from stops 0, 4, and 2.

```
    0
   / \
  1   2
   \ /
    3
    |
    4
```

## Expected Behavior

Every stop is reachable from every other stop, so each BFS lists all five vertices:

```
0: [1, 2]
1: [0, 3]
2: [0, 3]
3: [1, 2, 4]
4: [3]
BFS from 0: [0, 1, 2, 3, 4]
BFS from 4: [4, 3, 1, 2, 0]
BFS from 2: [2, 0, 3, 1, 4]
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The BFS loop itself is correct.

## Think About

- Compare the printed adjacency lists with the picture. Vertex 3 has three neighbors in the picture; how many does the program record?
- In an undirected graph, if 1 is a neighbor of 0, what must also be true? Where in the code is that relationship supposed to be established?
- Why does BFS from 0 give the right answer while BFS from 4 finds nothing beyond itself? What is special about the order in which `Main` added the edges?
- If the same `Graph` class were meant to represent a *directed* graph (one-way streets), would the output be correct?
