# Bellman-Ford with Negative Edges

**Course:** CSC310 &nbsp;|&nbsp; **Module 13:** Shortest Paths &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`bellman_ford.py` computes single-source shortest paths on a directed graph whose edge weights may be
negative (CLRS Section 22.1). It makes repeated passes over the edge list, relaxing every edge, then
performs one more check: if any edge can still be relaxed, a negative-weight cycle is reachable from
the source and no shortest paths exist. The `main` block runs it on the textbook's five-vertex
example, on a simple chain whose edges happen to be listed from the far end back toward the source,
and on a graph that genuinely contains a negative-weight cycle.

## Expected Behavior

```
textbook graph: distances from 0: 0=0 1=2 2=4 3=7 4=-2
chain: distances from 0: 0=0 1=1 2=2 3=3 4=4
bad loop: negative-weight cycle reachable from the source
```

The textbook distances are those CLRS shows for this graph. The chain is a plain path with unit
weights, so vertex `k` is at distance `k`.

## How to Run

```bash
python3 bellman_ford.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not reorder
the edge lists in `main`; the algorithm must work for any edge order.

## Think About

- After the first full pass over the chain's edge list, which vertices have a finite distance? After
  the second? How many passes does vertex 4 need, given the order in which the chain's edges are
  listed?
- The path-relaxation property says that after `i` passes, every vertex whose shortest path has at
  most `i` edges holds its correct distance. What is the largest number of edges a shortest path can
  have in a graph with `|V|` vertices, and how many passes does that require?
- Why does the textbook graph come out right while the chain does not, when the same code runs on
  both? What is different about the *order* of their edge lists relative to their shortest paths?
- When the final check finds a relaxable edge, the program concludes there is a negative cycle. What
  assumption about the passes that came before makes that conclusion valid?
