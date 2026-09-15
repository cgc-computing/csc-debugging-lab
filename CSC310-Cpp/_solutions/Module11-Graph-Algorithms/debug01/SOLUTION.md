# Solution: Breadth-First Search Distances

**Course/Module/Activity:** CSC310 · Module 11 Graph Algorithms · debug01
**Bug type(s):** logic (state: vertex marked discovered at the wrong time)
**Bug count:** 1

## Observed Behavior

```
BFS from s
  r: dist 1, parent s
  s: dist 0, parent -
  t: dist 2, parent w
  u: dist 4, parent x
  v: dist 2, parent r
  w: dist 1, parent s
  x: dist 3, parent t
  y: dist 5, parent u
vertices enqueued: 11
```

Distances to `x`, `u`, and `y` are too large (3, 4, 5 instead of 2, 3, 3), their parents are wrong, and 11 enqueues happen for 8 vertices.

## The Bug(s)

`bfs_distances.cpp`, `bfs`. A vertex is marked `visited` only when it is **dequeued**:

```cpp
int u = q.front(); q.pop();
if (visited[u]) continue;
visited[u] = true;
for (int v : adj[u]) {
    if (!visited[v]) {
        r.dist[v] = r.dist[u] + 1;   // may overwrite an earlier, smaller value
        ...
        q.push(v);
```

CLRS colors a vertex gray (discovered) the moment it is *enqueued*.

## Why the Program Behaved Incorrectly

Between being enqueued and being dequeued, a vertex is still "unvisited" as far as the test is concerned, so every other neighbor dequeued in the meantime rediscovers it, overwrites its distance with a larger value, and enqueues it again. Trace: `w` (dist 1) enqueues `t` and `x` with dist 2. Then `t` is dequeued *before* `x`; `x` is not yet marked, so `t` sets `dist[x] = 3` and pushes `x` a second time. When the first copy of `x` is finally dequeued its distance is already wrong, and the damage propagates: `x` sets `dist[u] = 4`, `u` sets `dist[y] = 5`. Duplicate queue entries are skipped on dequeue, so the program terminates—but on a denser graph the number of duplicates can grow exponentially.

## The Concept This Illustrates

BFS computes shortest paths because of a queue invariant: the queue holds all gray vertices, and their distances are non-decreasing from front to back, differing by at most one. The invariant only holds if a vertex becomes gray—is marked and gets its distance—at the moment it is *discovered*, so that the first (and therefore shortest) discovery is the one that sticks. Marking on dequeue turns "discovered" into "finished" and allows later, longer discoveries to overwrite earlier ones. The same confusion appears later in Dijkstra's algorithm, so it is worth getting right here.

## The Correction

```cpp
r.dist[source] = 0;
visited[source] = true;
q.push(source);
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            r.dist[v] = r.dist[u] + 1;
            r.parent[v] = u;
            q.push(v);
            ++r.enqueues;
        }
    }
}
```

## Instructor Notes

- A common partial fix is to keep marking on dequeue but only assign `dist[v]` if it is still `-1`. Distances become correct, yet `vertices enqueued` stays at 11. Ask what the running-time bound O(V + E) relies on and whether a vertex may be enqueued more than once.
- Ask students to write the queue contents after each dequeue for both versions; the moment `x` appears twice is the "aha".
- Follow-up: in the corrected program, `x`'s parent is `w` and `u`'s parent is `t`. Are other BFS trees possible? (Yes—adjacency-list order decides among equal-distance parents.)
- Contrast with DFS, where marking on entry to the recursive call is the natural (and correct) place; students sometimes port that habit to BFS backwards.
