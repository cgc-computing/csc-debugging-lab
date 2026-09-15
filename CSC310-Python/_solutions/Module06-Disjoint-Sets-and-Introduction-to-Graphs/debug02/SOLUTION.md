# Solution: Undirected Graph as Adjacency Lists

**Course/Module/Activity:** CSC310 · Module 6 Disjoint Sets and Introduction to Graphs · debug02
**Bug type(s):** conceptual/design (representation of undirected edges), logic
**Bug count:** 2 (related: both stem from "one undirected edge = two list entries")

## Observed Behavior

```
adjacency lists:
  1: [2, 5]
  2: [5, 4, 3]
  3: [4]
  4: [5]
  5: []

degrees        : [2, 3, 1, 1, 0]
sum of degrees : 7
edge count     : 7
has_edge(2, 5) : True
has_edge(5, 2) : False
has_edge(1, 3) : False

adjacency matrix:
  0 1 0 0 1
  0 0 1 1 1
  0 0 0 1 0
  0 0 0 0 1
  0 0 0 0 0
symmetric      : False
```

Vertex 5 has degree 0 although three edges touch it, `has_edge` is not symmetric, the matrix is
upper-triangular, yet the edge count happens to be right.

## The Bug(s)

1. `undirected_graph.py`, `add_edge` stores the edge in only one list:

   ```python
   def add_edge(self, u, v):
       self.adj[u].append(v)
   ```

2. `edge_count` sums the list lengths without halving:

   ```python
   return sum(len(lst) for lst in self.adj.values())
   ```

## Why the Program Behaved Incorrectly

Each call `add_edge(u, v)` records `v` as a neighbour of `u` but not `u` as a neighbour of `v`, so the
structure is really a *directed* graph whose arcs all point from the first endpoint to the second.
Degrees are out-degrees, `has_edge(5, 2)` fails because 5's list is empty, and the matrix has ones
only above the diagonal. The edge count is correct by accident: the sum of list lengths is 7 because
each edge was stored once. That coincidence masks the second bug; as soon as `add_edge` is fixed the
sum becomes 14 and `edge_count` reports 14 unless it is halved.

## The Concept This Illustrates

CLRS Section 20.1: for an undirected graph, edge (u, v) appears in *both* Adj[u] and Adj[v], so the
adjacency-list representation uses 2|E| entries, the sum of degrees is 2|E| (handshake lemma), and
the adjacency matrix is symmetric (A = Aᵀ). A student holding this bug is treating "the edge list"
and "the adjacency lists" as the same thing; the second bug shows what happens when one part of the
code assumes the correct representation and another does not.

## The Correction

```python
# before
def add_edge(self, u, v):
    self.adj[u].append(v)

def edge_count(self):
    return sum(len(lst) for lst in self.adj.values())

# after
def add_edge(self, u, v):
    self.adj[u].append(v)
    self.adj[v].append(u)

def edge_count(self):
    return sum(len(lst) for lst in self.adj.values()) // 2
```

## Instructor Notes

- Expect most groups to fix `add_edge` first and then be surprised that `edge count` jumps to 14.
  That is the intended second discussion: which quantity is 2|E|, and why.
- Some students fix `has_edge` by checking both directions instead of fixing `add_edge`. Ask them
  what `degree(5)` should be and whether their fix changes it.
- Others fix `add_edge` and then "fix" the edge count by keeping a separate counter incremented in
  `add_edge`. That is legitimate; ask whether the handshake-lemma version and the counter version
  can ever disagree, and what a self-loop would do to each.
- Follow-up: what changes if the graph is directed? (Only `add_edge`; the degree of a vertex then
  splits into in-degree and out-degree, and the matrix need not be symmetric.)
