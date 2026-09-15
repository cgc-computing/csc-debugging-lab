# Floyd-Warshall All-Pairs Shortest Paths

**Course:** CSC310 &nbsp;|&nbsp; **Module 13:** Shortest Paths &nbsp;|&nbsp; **Activity:** debug03
**Language:** Python 3

## Goal

`floyd_warshall.py` computes shortest-path weights between every pair of vertices (CLRS Section 23.2)
by dynamic programming: `d[i][j]` is improved by allowing one more vertex `k` to serve as an
intermediate vertex on the path from `i` to `j`, for `k` running over all vertices. A predecessor
matrix is maintained alongside so that paths can be reconstructed. The graph is the textbook's
five-vertex example (negative edges, no negative cycles). The `main` block prints the weight matrix,
the final distance matrix, and three reconstructed paths.

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
sample paths:
  1 to 2: 1 -> 5 -> 4 -> 3 -> 2   (weight 1)
  1 to 3: 1 -> 5 -> 4 -> 3   (weight -3)
  5 to 1: 5 -> 4 -> 1   (weight 8)
```

`D` is the final matrix CLRS computes for this graph. Vertices are numbered 1–5 in the output (stored
as 0–4 in the code).

## How to Run

```bash
python3 floyd_warshall.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the single
in-place matrix; do not allocate one matrix per stage.

## Think About

- Write out the recurrence: d⁽ᵏ⁾[i][j] = min(d⁽ᵏ⁻¹⁾[i][j], d⁽ᵏ⁻¹⁾[i][k] + d⁽ᵏ⁻¹⁾[k][j]). Every term
  on the right belongs to stage k − 1. In the code, at the moment `d[i][k] + d[k][j]` is read, which
  intermediate vertices has each of those two entries already been allowed to use?
- The true shortest path from 1 to 2 is 1 → 5 → 4 → 3 → 2. For `d[1][2]` to drop to 1, which other
  entries must already hold their final values, and at what point in the run does the program compute
  them? Is `d[1][2]` ever revisited after that point?
- Rows 2–5 of the printed `D` are correct; only row 1 is off. What is special about row 1 in terms of
  *when* its entries are computed?
- In a matrix multiplication the three nested loops can be arranged in any order without changing the
  result. Does that argument carry over to this triple loop? What would have to be true of the values
  read inside the loop for it to carry over?
