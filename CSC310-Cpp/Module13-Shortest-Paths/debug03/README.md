# Floyd-Warshall All-Pairs Shortest Paths

**Course:** CSC310 &nbsp;|&nbsp; **Module 13:** Shortest Paths &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

`floydWarshall` computes shortest-path weights between every pair of vertices (CLRS 23.2) by dynamic programming: `d[i][j]` is improved by allowing one more vertex `k` to serve as an intermediate point, for `k` from 0 to `n - 1`. The graph is the textbook's five-vertex example (negative edges, no negative cycles). The driver prints the weight matrix and the final distance matrix.

## Expected Behavior

```
weight matrix W:
    0    3    8  inf   -4
  inf    0  inf    1    7
  inf    4    0  inf  inf
    2  inf   -5    0  inf
  inf  inf  inf    6    0
shortest-path weights D:
    0    1   -3    2   -4
    3    0   -4    1   -1
    7    4    0    5    3
    2   -1   -5    0   -2
    8    5    1    6    0
```

## How to Run

```bash
g++ -std=c++17 -Wall -o floyd_warshall floyd_warshall.cpp
./floyd_warshall
```

(on Windows: `floyd_warshall.exe` or `.\floyd_warshall.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the three nested loops and the in-place matrix.

## Think About

- The recurrence defines "shortest `i` to `j` using intermediates from `{0..k}`" in terms of "shortest `i` to `k`" and "shortest `k` to `j`" using intermediates from `{0..k-1}`. For those two sub-answers to be ready when they are needed, in what order must the table be filled?
- Entry `(0, 1)` should be 1, via the path `0 -> 4 -> 3 -> 2 -> 1`. Which intermediate vertices does that path use, and in the buggy loop order, have the entries `d[4][3]`, `d[3][2]`, `d[2][1]` been improved yet when `d[0][1]` is computed?
- Which entries of the buggy result are still correct, and what do their shortest paths have in common?
