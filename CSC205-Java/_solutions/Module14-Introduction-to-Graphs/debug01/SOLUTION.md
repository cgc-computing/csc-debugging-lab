# Solution: Campus Shuttle Map with BFS

**Course/Module/Activity:** CSC205 · Module 14 Introduction to Graphs · debug01
**Bug type(s):** conceptual/design, logic
**Bug count:** 1

## Observed Behavior

```
0: [1, 2]
1: [3]
2: [3]
3: [4]
4: []
BFS from 0: [0, 1, 2, 3, 4]
BFS from 4: [4]
BFS from 2: [2, 3, 4]
```

The adjacency lists are one-directional; BFS from 0 happens to be right, BFS from 4 and 2 miss vertices.

## The Bug(s)

`Graph.java`, `addEdge(int u, int v)`:

```java
public void addEdge(int u, int v) {
    adj.get(u).add(v);
}
```

Only `u → v` is recorded. For an undirected graph the edge must appear in both vertices' lists.

## Why the Program Behaved Incorrectly

`Main` adds every edge with the smaller endpoint first, so the stored graph is a DAG pointing "downhill": 0→1, 0→2, 1→3, 2→3, 3→4. From 0 everything is downhill, so BFS reaches all five and even in the expected order. From 4 there are no outgoing entries, so BFS stops immediately. From 2 the search goes 2→3→4 and never sees 0 or 1, which are only reachable "uphill."

## The Concept This Illustrates

An adjacency-list representation of an *undirected* graph stores each edge twice, once in each endpoint's list — the symmetry is not implied by the data structure, it must be written in. Students who test only from vertex 0 (the usual habit) never notice, because the edge-entry order happens to make every vertex reachable from 0. The bug is in the representation, not the algorithm: BFS is correct and faithfully explores the graph it was given.

## The Correction

```java
// before
adj.get(u).add(v);
// after
adj.get(u).add(v);
adj.get(v).add(u);
```

## Instructor Notes

- Have students compare the printed adjacency table against the picture *first*; the missing entries are visible before any tracing.
- Some students "fix" it in `Main` by adding each edge twice (`addEdge(0,1); addEdge(1,0);`). It produces the right output; ask whether a `Graph` that calls itself undirected should push that burden onto every caller.
- Ask why BFS from 0 was correct anyway, and what would have happened if `Main` had written `addEdge(1, 0)` instead of `addEdge(0, 1)`.
- Follow-up: the corrected BFS order from 2 is `[2, 0, 3, 1, 4]`. Ask students to justify it from the adjacency lists (0 before 3 because 0 was added to 2's list first).
