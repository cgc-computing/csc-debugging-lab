# Solution: Undirected Graph with Adjacency Lists

**Course/Module/Activity:** CSC310 · Module 6 Disjoint Sets and Introduction to Graphs · debug02
**Bug type(s):** conceptual/design (representation), logic
**Bug count:** 2 related (both stem from treating an undirected edge as a single directed entry)

## Observed Behavior

```
vertex 0: degree 1, neighbors 1
vertex 1: degree 1, neighbors 2
vertex 2: degree 1, neighbors 0
vertex 3: degree 1, neighbors 1
vertex 4: degree 2, neighbors 3 2
edges: 6
connected: no
```

Every degree is too small, neighbor lists are one-directional (0 lists 1 but 1 does not list 0), the graph is reported disconnected, yet the edge count happens to be right.

## The Bug(s)

`undirected_graph.cpp`:

1. `Graph::addEdge` records the edge in only one list:
   ```cpp
   void addEdge(int u, int v) {
       adj_[u].push_back(v);
   }
   ```
2. `Graph::edgeCount` returns the raw degree sum:
   ```cpp
   return total;   // should be total / 2 for an undirected graph
   ```

## Why the Program Behaved Incorrectly

Each `addEdge(u, v)` appends `v` to `u`'s list only, so the structure is really a *directed* graph with six arcs. Degrees therefore count only outgoing arcs (0 has one, not two), and the depth-first walk from 0 can only follow arcs in the stored direction: 0 → 1 → 2 → 0, so vertices 3 and 4 are never reached and the graph is declared disconnected. The degree sum is 6 because there are six arcs; in a correctly stored undirected graph the sum would be 12 and would have to be halved. The two bugs cancel in `edgeCount`, which is why that one line of output looks right.

## The Concept This Illustrates

An undirected edge {u, v} is *one* edge but occupies *two* adjacency-list entries, one in each endpoint's list. Everything downstream depends on this: degree is the list length, the sum of degrees is twice the edge count (handshaking lemma), and traversals must be able to cross an edge in either direction. Students who build the list from an edge list often add one entry per edge and then either get half the degrees or, if they notice the edge count is off, adjust `edgeCount` instead of the representation. The correct fix is to make the representation right and let the lemma do its job.

## The Correction

```cpp
void addEdge(int u, int v) {
    adj_[u].push_back(v);
    adj_[v].push_back(u);
}

int edgeCount() const {
    int total = 0;
    for (int v = 0; v < vertexCount(); ++v) {
        total += degree(v);
    }
    return total / 2;
}
```

## Instructor Notes

- Students who fix only `addEdge` will see `edges: 12`; students who fix only `edgeCount` will see `edges: 3`. Both are good moments to state the handshaking lemma and ask which quantity each function is actually computing.
- Ask what would change if the graph allowed self-loops (a self-loop adds 2 to the degree of one vertex, so the lemma still holds, but `addEdge(u, u)` should append `u` twice or be special-cased).
- Follow-up: how would you represent the same graph with an adjacency matrix, and what symmetry property would the buggy `addEdge` violate there?
- The neighbor order in the expected output (for example, vertex 2 lists `1 0 4`) follows the order in which edges were added; that is fine and worth pointing out so students do not "fix" ordering.
