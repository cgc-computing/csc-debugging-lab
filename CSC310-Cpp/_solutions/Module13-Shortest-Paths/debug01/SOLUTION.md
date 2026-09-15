# Solution: Dijkstra's Shortest Paths

**Course/Module/Activity:** CSC310 · Module 13 Shortest Paths · debug01
**Bug type(s):** logic (state: vertex finalized when discovered rather than when extracted; stale entries never recognized)
**Bug count:** 1

## Observed Behavior

```
shortest paths from s
  s: dist 0   path s
  t: dist 10   path s -> t
  x: dist 14   path s -> y -> x
  y: dist 5   path s -> y
  z: dist 7   path s -> y -> z
```

`t` and `x` are wrong (10 and 14 instead of 8 and 9); `y` and `z` are right.

## The Bug(s)

`dijkstra.cpp`, `dijkstra`:

```cpp
dist[source] = 0;
finalized[source] = true;
pq.push({0, source});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    for (const Neighbor& nb : adj[u]) {
        int v = nb.to;
        if (!finalized[v] && dist[u] + nb.weight < dist[v]) {
            dist[v] = dist[u] + nb.weight;
            parent[v] = u;
            finalized[v] = true;      // finalized on discovery
            pq.push({dist[v], v});
```

A vertex is marked `finalized` the first time an edge reaches it, and finalized vertices are never relaxed again. The pop loop has no check for stale entries because, with this scheme, none can exist—at the price of correctness.

## Why the Program Behaved Incorrectly

From `s`, the edges `s -> t` (10) and `s -> y` (5) are relaxed and *both* `t` and `y` are frozen at once. When `y` (5) is extracted, the edge `y -> t` (3) offers `t` a distance of 8, but `t` is already "finalized", so the improvement is refused. `x` is then reached from `y` with 5 + 9 = 14 and frozen; the better route `s -> y -> t -> x` (8 + 1 = 9) can never be recorded because `x` is frozen too. In effect the program has become breadth-first search with weights: whoever reaches a vertex first wins, regardless of cost.

## The Concept This Illustrates

Dijkstra's invariant is that a vertex's distance is final **when it is extracted as the minimum of the queue**, not when it is discovered—the proof (the Dijkstra correctness theorem in CLRS §22.3) relies on every vertex with a smaller true distance having been extracted before it. Discovery only gives an *upper bound*, which later relaxations may lower. With a binary heap that cannot decrease keys, the correct pattern is: push a new entry whenever a distance improves, mark the vertex finalized when it is *popped*, and skip any popped entry whose vertex is already finalized (or whose recorded distance exceeds `dist[u]`—a stale entry). Students who carry over BFS's "mark when enqueued" rule get exactly this failure, and the graph is chosen so that the first edge into `t` is not the cheapest.

## The Correction

```cpp
dist[source] = 0;
pq.push({0, source});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (finalized[u]) continue;          // stale entry
    finalized[u] = true;
    for (const Neighbor& nb : adj[u]) {
        int v = nb.to;
        if (dist[u] + nb.weight < dist[v]) {
            dist[v] = dist[u] + nb.weight;
            parent[v] = u;
            pq.push({dist[v], v});
        }
    }
}
```

## Instructor Notes

- Students who simply delete `finalized[v] = true` (and the `!finalized[v]` test) get correct distances, because relaxation is then unrestricted; but without the pop-time check every stale entry is re-expanded. Ask them how many times `t` is popped and what that does to the O((V + E) log V) bound.
- An equivalent stale test is `if (d > dist[u]) continue;`. Ask why the two tests agree when all weights are non-negative and which one a student would prefer to explain.
- A good "why does this matter" prompt: draw the graph and ask which edge into `t` is examined first and why the answer would differ if the adjacency list of `s` were reversed. (It would not—`y` still pops before `t` because 5 < 10.)
- Connect back to Module 11 debug01: same marking-time mistake, same kind of symptom.
