# Solution: Topological Sort by Depth-First Search

**Course/Module/Activity:** CSC310 · Module 11 Graph Algorithms · debug02
**Bug type(s):** logic (vertex recorded at discovery instead of at finish)
**Bug count:** 1

## Observed Behavior

```
order: watch socks tie shirt shoes jacket belt pants undershorts
  violated: undershorts -> pants
  violated: undershorts -> shoes
  violated: pants -> belt
  violated: pants -> shoes
  violated: belt -> jacket
  violated: shirt -> tie
NOT a valid topological order
```

Six of the nine edges point backwards.

## The Bug(s)

`topological_sort.cpp`, `dfsVisit`:

```cpp
visited[u] = true;
order.push_back(u);          // recorded on discovery
for (int v : adj[u]) { ... }
```

The vertex is appended when it is *discovered*. CLRS's TOPOLOGICAL-SORT inserts each vertex onto the front of the list when it is *finished*; equivalently, append on finish and reverse at the end.

## Why the Program Behaved Incorrectly

Appending on discovery records a *preorder*: `undershorts, pants, belt, jacket, shoes, shirt, tie, socks, watch`. Reversing a preorder puts children before parents (`pants` before `undershorts`), so almost every edge is violated. Even without the reversal a preorder is not a topological order: `belt` is discovered from `pants` before `shirt` has been visited at all, yet `shirt -> belt` requires `shirt` first. Only the *finish* order has the property that guarantees correctness: when `u` finishes, every vertex reachable from `u` has already finished, so `u` precedes all of them once the list is reversed.

## The Concept This Illustrates

The DFS topological sort rests on one fact (the topological-sort theorem in CLRS §20.4): for every edge `u -> v` in a DAG, `v.f < u.f`—`v` finishes before `u`. Sorting by decreasing finish time therefore puts `u` before `v`. Discovery times have no such property; `v` may be discovered before or after `u` depending on where the search happens to start. Students who think of DFS as "the order in which we reach vertices" miss that DFS produces two orderings, and it is the second one—the order in which calls return—that carries the dependency information.

## The Correction

```cpp
visited[u] = true;
for (int v : adj[u]) {
    if (!visited[v]) dfsVisit(adj, v, visited, order);
}
order.push_back(u);          // recorded on finish
```

(keep the `std::reverse` in `topologicalSort`).

## Instructor Notes

- Students who remove the `std::reverse` but keep recording on discovery still get an invalid order (`shirt -> belt`, `tie -> jacket`, and `socks -> shoes` are violated). Have them run the checker rather than eyeballing.
- Students who record on finish *and* remove the reverse produce the exact opposite of a valid order—every edge violated. That is a useful "all or nothing" confirmation of the theorem.
- Ask for the discovery and finish timestamps of `undershorts` and `pants` in a hand trace; then ask which timestamp is monotone along edges.
- Alternative correct algorithm worth mentioning: Kahn's (repeatedly remove an in-degree-0 vertex). Ask why both produce valid, possibly different, orders.
