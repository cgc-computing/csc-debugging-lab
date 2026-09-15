# Solution: Router Hop Counts

**Course/Module/Activity:** CSC205 · Module 14 Introduction to Graphs · debug02
**Bug type(s):** conceptual/design, logic
**Bug count:** 1

## Observed Behavior

```
Hops from router 0:
  router 0: 0
  router 1: 1
  router 2: 2
  router 3: 3
  router 4: 4
  router 5: unreachable
Queue pushes: 7
```

Routers 2, 3, and 4 are reported one hop farther than they really are (router 2 is a direct neighbor of 0), and seven pushes were made for five reachable routers.

## The Bug(s)

`bfs_distances.cpp`, function `bfsDistances`: vertices are marked visited when they are *dequeued*:

```cpp
int u = pending.front();
pending.pop();
if (visited[u]) {
    continue;
}
visited[u] = true;
for (int v : g.neighbors(u)) {
    if (!visited[v]) {
        dist[v] = dist[u] + 1;
        pending.push(v);
        ...
```

Because a neighbor is not marked when it is pushed, it can be pushed again by another vertex before it is dequeued, and each push overwrites `dist[v]`.

## Why the Program Behaved Incorrectly

Trace from 0: pop 0, mark it, push 1 and 2 with `dist = 1`. Pop 1, mark it; its neighbor 2 is *not yet marked* (it is sitting in the queue), so `dist[2]` is overwritten with `dist[1] + 1 = 2` and 2 is pushed a second time; 3 is pushed with `dist = 2`. Pop 2 (first copy), mark it; neighbor 3 is unmarked, so `dist[3]` becomes 3 and 3 is pushed again; 4 gets `dist = 3`. Pop the duplicate 2 — skipped. Pop 3, mark it; 4 is unmarked, so `dist[4]` becomes 4 and 4 is pushed again. Each overwrite happens *later* than the original correct assignment, so it always replaces a smaller distance with a larger one. The duplicate pushes account for 7 instead of 5.

## The Concept This Illustrates

BFS computes shortest hop counts because vertices leave the queue in non-decreasing order of distance, and the *first* time a vertex is discovered is along a shortest path. To preserve that, a vertex must be marked (and its distance fixed) at the moment it is discovered — when it is enqueued — not when it is later dequeued. Marking on dequeue is the natural way to write DFS with an explicit stack, which is why students mix the two up. The consequences are exactly what the output shows: duplicate queue entries (wasted work, potentially O(E) extra pushes) and distances that are overwritten by longer paths.

## The Correction

```cpp
// before
dist[source] = 0;
pending.push(source);
while (!pending.empty()) {
    int u = pending.front();
    pending.pop();
    if (visited[u]) {
        continue;
    }
    visited[u] = true;
    for (int v : g.neighbors(u)) {
        if (!visited[v]) {
            dist[v] = dist[u] + 1;
            pending.push(v);

// after
dist[source] = 0;
visited[source] = true;
pending.push(source);
while (!pending.empty()) {
    int u = pending.front();
    pending.pop();
    for (int v : g.neighbors(u)) {
        if (!visited[v]) {
            visited[v] = true;
            dist[v] = dist[u] + 1;
            pending.push(v);
```

## Instructor Notes

- A partial fix students try: keep marking on dequeue but guard the assignment with `if (dist[v] == -1)`. The distances become correct, but the push count stays 7. Ask whether the queue can still grow beyond the number of vertices on a denser graph, and whether that matters for the O(V + E) bound.
- Another partial fix: mark on enqueue but forget `visited[source] = true`. On this graph, router 0 gets re-pushed from router 1 with `dist[0] = 2` — an eye-opening result to show them.
- Ask students to convert the function to DFS by swapping `queue` for a stack and to decide *then* whether marking on pop is acceptable (it is, for reachability; it is not, for shortest paths — DFS does not give shortest paths anyway).
- Follow-up: have them record a `parent[]` array alongside `dist[]` and print the actual shortest path to router 4.
