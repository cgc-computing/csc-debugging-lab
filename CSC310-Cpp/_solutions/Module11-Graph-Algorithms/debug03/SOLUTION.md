# Solution: Detecting a Cycle in a Directed Graph

**Course/Module/Activity:** CSC310 · Module 11 Graph Algorithms · debug03
**Bug type(s):** conceptual/design (edge classification: a two-state visited flag cannot distinguish back edges from cross/forward edges)
**Bug count:** 1

## Observed Behavior

```
diamond: cycle found: 3
prerequisites: cycle found: 5
ring road: cycle found: 1 2 3 1
self loop: cycle found: 1 1
```

Both acyclic graphs are reported cyclic, with a nonsensical one-vertex "cycle". The two genuinely cyclic graphs are reported correctly.

## The Bug(s)

`cycle_detection.cpp`, `Detector`. The search tracks only a boolean:

```cpp
std::vector<bool> visited;
...
for (int v : adj[u]) {
    if (visited[v]) {          // treats any visited vertex as a back edge
        ...cycle...
        return true;
    }
    if (visit(v)) return true;
}
```

Any edge into a previously visited vertex is declared a back edge. Only an edge into a vertex that is *still on the stack* (gray) is one.

## Why the Program Behaved Incorrectly

In the diamond, DFS goes `0 -> 1 -> 3`, finishes `3` and `1`, then goes `0 -> 2` and examines `2 -> 3`. Vertex `3` is visited but *finished*: it is a cross edge (or forward edge), and there is no path from `3` back to `2`. The boolean cannot tell finished from active, so the program declares a cycle. Its path reconstruction then searches the current stack `[0, 2]` for `3`, does not find it, and prints just the closing vertex—hence `cycle found: 3`. The cyclic graphs happen to work because their first offending edge really does lead to an active vertex.

## The Concept This Illustrates

CLRS's white/gray/black coloring is not decoration. Gray means "on the current root-to-vertex path"; an edge to a gray vertex closes a cycle. Black means "finished"; an edge to a black vertex is a cross or forward edge and is harmless for cycle detection (in a DAG, such edges are common—any shared descendant produces one). Students who compress the three colors into a boolean lose exactly the distinction the algorithm depends on, and the false positives look like a "cycle" only until you try to print it.

## The Correction

```cpp
enum class Color { White, Gray, Black };
std::vector<Color> color;
...
color[u] = Color::Gray;
for (int v : adj[u]) {
    if (color[v] == Color::Gray) { ...report cycle...; return true; }
    if (color[v] == Color::White && visit(v)) return true;
}
path.pop_back();
color[u] = Color::Black;
```

## Instructor Notes

- A correct alternative students find: keep the boolean and instead test `std::find(path.begin(), path.end(), v) != path.end()`. That works (the path *is* the gray set) but costs O(V) per edge; ask them to compare with the O(1) color test and to explain why the two tests agree.
- Another partial fix: add an `onStack` boolean alongside `visited`. That is the three-color scheme in disguise—fine, and a good moment to name the colors.
- Ask why the self-loop `1 -> 1` is a back edge under the color rule (1 is gray when its own edge is examined).
- Follow-up: extend the detector to return *all* cycles or to compute strongly connected components (Kosaraju/Tarjan); both depend on the same gray/black distinction.
