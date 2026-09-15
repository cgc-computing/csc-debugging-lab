# Router Hop Counts

**Course:** CSC205 &nbsp;|&nbsp; **Module 14:** Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

Six routers form an undirected network. The program uses breadth-first search from router 0 to compute the fewest hops needed to reach every other router (or reports it as unreachable), and counts how many times a router was pushed onto the BFS queue.

```
0 - 1    0 - 2    1 - 2    1 - 3    2 - 3    3 - 4        (router 5 has no links)
```

## Expected Behavior

```
Hops from router 0:
  router 0: 0
  router 1: 1
  router 2: 1
  router 3: 2
  router 4: 3
  router 5: unreachable
Queue pushes: 5
```

In a correct BFS each reachable router is pushed exactly once, so the push count equals the number of reachable routers.

## How to Run

```bash
g++ -std=c++17 -Wall -o bfs_distances bfs_distances.cpp
./bfs_distances
```
(on Windows: `bfs_distances.exe` or `.\bfs_distances.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The `Graph` class is correct; the problem is in `bfsDistances`.

## Think About

- Router 2 is directly linked to router 0, yet its distance comes out as 2. Which assignment produced that value, and what was on the queue at that moment?
- At what moment should BFS mark a vertex so that it can never be put on the queue a second time?
- Why is the number of pushes larger than the number of reachable routers? Trace the queue's contents step by step for the first few iterations.
