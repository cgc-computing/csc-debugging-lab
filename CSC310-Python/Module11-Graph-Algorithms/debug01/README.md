# Breadth-First Search Distances

**Course:** CSC310 &nbsp;|&nbsp; **Module 11:** Graph Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`bfs_distances.py` implements breadth-first search (CLRS Section 20.2) on an undirected graph.
Starting from a source vertex it computes, for every vertex, the distance in edges from the source and
the parent in the breadth-first tree, and it counts how many times any vertex was placed on the queue.
The `main` block runs the search on the textbook's eight-vertex example graph (vertices
`r s t u v w x y`) from source `s`.

## Expected Behavior

```
dequeue order : s r w v t x u y
times enqueued: 8 (vertices: 8 )

  r: dist 1   path s->r
  s: dist 0   path s
  t: dist 2   path s->w->t
  u: dist 3   path s->w->t->u
  v: dist 2   path s->r->v
  w: dist 1   path s->w
  x: dist 2   path s->w->x
  y: dist 3   path s->w->x->y
```

These are the distances CLRS shows for this graph. Every vertex is reachable from `s`, so each vertex
is enqueued exactly once and the count equals the number of vertices.

## How to Run

```bash
python3 bfs_distances.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
queue-based design; do not switch to a recursive search.

## Think About

- CLRS colors a vertex gray at the moment it is *discovered* and black when it is *finished*. Which
  statement in this program corresponds to each of those two events, and which event is the one that
  records "this vertex has been seen"?
- Vertex `x` is adjacent to `w`, and `w` is at distance 1. What distance should `x` receive, and from
  which vertex? Use the printed dequeue order to work out which vertex was the *last* one to write
  `dist[x]`, and why it was allowed to.
- Eight vertices, eleven enqueues. Which vertices were enqueued more than once, and what was true of
  each of them at the moment of the extra enqueue?
- On what kind of graph would this program still print correct distances? What about the graph in
  `main` makes the difference visible?
