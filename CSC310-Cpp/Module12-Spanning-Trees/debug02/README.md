# Prim's Minimum Spanning Tree

**Course:** CSC310 &nbsp;|&nbsp; **Module 12:** Spanning Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`prim` grows a minimum spanning tree from vertex `a` (CLRS 21.2) using a binary heap (`std::priority_queue` with lazy deletion). For every vertex `v` outside the tree, `key[v]` is the weight of the lightest edge connecting `v` to the tree built so far; the vertex with the smallest key joins next. The graph is the textbook's nine-vertex example. The driver prints each tree edge as parent–child with its weight, then the total weight.

## Expected Behavior

```
tree edges (parent-child):
  a-b (4)
  b-c (8)
  c-d (7)
  d-e (9)
  c-f (4)
  f-g (2)
  g-h (1)
  c-i (2)
total weight: 37
```

## How to Run

```bash
g++ -std=c++17 -Wall -o prim prim.cpp
./prim
```

(on Windows: `prim.exe` or `.\prim.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the priority-queue structure and the lazy-deletion check.

## Think About

- `key[v]` is supposed to be the weight of the cheapest edge joining `v` to the tree. Is that a property of a single edge, or of a whole path from the root?
- Add up the weights of the edges the buggy program lists and compare with the total it prints. Why do the two numbers disagree, and what quantity is the program actually accumulating?
- Vertex `h` is joined to the tree by an edge of weight 1 from `g`, yet the buggy program attaches it directly to `a` with an edge of weight 8. Which quantity must the program be comparing for that to look like the better choice, and is that the quantity Prim's algorithm is supposed to compare?
