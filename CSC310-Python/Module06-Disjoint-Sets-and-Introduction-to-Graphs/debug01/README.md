# Connected Components With a Disjoint-Set Forest

**Course:** CSC310 &nbsp;|&nbsp; **Module 6:** Disjoint Sets and Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`disjoint_set.py` implements a disjoint-set forest with union by rank and path compression (CLRS
Section 19.3) and uses it to compute the connected components of an undirected graph from its edge
list (CONNECTED-COMPONENTS, CLRS Section 19.1). The `main` block processes the seven edges of the
example graph in CLRS Section 19.1 on vertices `a`–`j`, prints the resulting components and set count, answers several
`same_set` queries, and finally unions a six-vertex chain end to end.

## Expected Behavior

```
edges processed: [('b', 'd'), ('e', 'g'), ('a', 'c'), ('h', 'i'), ('a', 'b'), ('e', 'g'), ('b', 'c')]
components     : ['abcd', 'eg', 'f', 'hi', 'j']
set count      : 5

same_set(a, d) = True
same_set(b, c) = True
same_set(e, g) = True
same_set(h, i) = True
same_set(a, e) = False
same_set(j, j) = True

chain 0-1-2-3-4-5 sets: 1  same_set(0,5) = True
```

## How to Run

```bash
python3 disjoint_set.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the forest
representation with union by rank and path compression.

## Think About

- Which vertices are allowed to be passed to `_link`? What does its comment say, and does every
  caller honor that?
- Process the edges by hand, drawing the forest after each union. At the union of `a` and `b`, what
  are the two arguments, and what are the two *roots*? Are they the same thing?
- After all seven edges, the program reports a set count of 4 but lists six groups. How can a
  vertex end up disconnected from a set it used to belong to?
- In the chain test, each union joins a vertex to its predecessor. Why does `same_set(0, 5)` still
  come out `False`?
