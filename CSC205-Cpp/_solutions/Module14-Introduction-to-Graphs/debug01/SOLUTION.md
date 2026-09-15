# Solution: Campus Walkway Graph

**Course/Module/Activity:** CSC205 · Module 14 Introduction to Graphs · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

```
From Library (5 reachable): Library Science Union Gym Dorms
From Dorms (1 reachable): Dorms
From Annex (2 reachable): Annex Garage
```

Starting from Dorms, BFS finds nothing but Dorms itself, although Dorms is connected to Gym and, through Gym, to the rest of the main campus.

## The Bug(s)

`campus_graph.cpp`, `Graph::addEdge`:

```cpp
void addEdge(int u, int v) {
    adjacent[u].push_back(v);
}
```

Only the `u → v` direction is recorded. For an undirected graph the edge must appear in both vertices' lists.

## Why the Program Behaved Incorrectly

Every call in `main` lists the lower-numbered building first, so all edges are stored pointing "forward": Library's list has Science and Union, Gym's list has Dorms, but Dorms's list is empty and Science's list has only Gym. BFS from Library happens to work because every vertex in that component is reachable by following forward edges. BFS from Dorms (vertex 4) looks at `adjacent[4]`, finds it empty, and stops. The graph the program actually built is a *directed* graph that only resembles the intended one when you start at a source.

## The Concept This Illustrates

An adjacency list represents each edge as an entry in the list of its *source* vertex. An undirected edge {u, v} therefore takes two entries — `v` in u's list and `u` in v's list — because it is a source from both ends. Students often reason "I added the edge between 3 and 4, so they are connected," conflating the abstract edge with its storage. The symptom is instructive: a traversal that works from one starting point and fails from another is a classic sign that the graph is unintentionally directed.

## The Correction

```cpp
// before
void addEdge(int u, int v) {
    adjacent[u].push_back(v);
}
// after
void addEdge(int u, int v) {
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
}
```

## Instructor Notes

- Some students "fix" `main` by adding six reverse `addEdge` calls. It works, but ask where the knowledge "this graph is undirected" should live — in the class, once — and what happens the next time someone adds an edge.
- Ask students to explain why the BFS *order* from Dorms in the expected output is `Dorms Gym Science Union Library`: Gym's list is `[1, 2, 4]` after the fix (Science and Union were pushed by earlier calls, Dorms by a later one), so Science is enqueued before Union. Good practice for reading adjacency lists.
- Follow-up: an adjacency *matrix* version would set `m[u][v] = m[v][u] = 1`; ask which representation makes the mistake easier to spot.
- Ask what the program would print for a graph with a self-loop `addEdge(2, 2)` after the fix (vertex 2 appears twice in its own list — harmless for BFS, but worth noticing).
