# Solution: Breadth-First Search Distances

**Course/Module/Activity:** CSC310 · Module 11 Graph Algorithms · debug01
**Bug type(s):** conceptual/design (vertex state changed at the wrong moment: on dequeue instead of on discovery)
**Bug count:** 1

## Observed Behavior

```
dequeue order : s r w v t x u y
times enqueued: 11 (vertices: 8 )

  r: dist 1   path s->r
  s: dist 0   path s
  t: dist 2   path s->w->t
  u: dist 4   path s->w->t->x->u
  v: dist 2   path s->r->v
  w: dist 1   path s->w
  x: dist 3   path s->w->t->x
  y: dist 5   path s->w->t->x->u->y
```

The dequeue order is right, but `x`, `u` and `y` receive distances 3, 4 and 5 instead of 2, 3 and 3,
their paths take detours, and vertices were enqueued 11 times for an 8-vertex graph.

## The Bug(s)

`bfs_distances.py`, function `bfs`. The `visited` flag is set when a vertex is *dequeued*
(`visited[u] = True` right after `popleft`, protected by `if visited[u]: continue`) instead of when it
is *enqueued*, and the source is never marked at all:

```python
while queue:
    u = queue.popleft()
    if visited[u]:
        continue
    visited[u] = True
    order.append(u)
    for v in adj[u]:
        if not visited[v]:
            dist[v] = dist[u] + 1
            parent[v] = u
            queue.append(v)
```

## Why the Program Behaved Incorrectly

A vertex that is sitting in the queue still has `visited[v] == False`, so every vertex dequeued before
it that is adjacent to it re-enqueues it and overwrites `dist[v]` and `parent[v]`. Later writers are
always farther from the source, and the last writer wins. Here `w` discovers `x` correctly with
distance 2, but `t` is dequeued before `x` and, finding `visited[x]` still false, rewrites `dist[x] = 3`
and `parent[x] = t`. `u` is then written by `t` (3) and again by `x` (now 3 + 1 = 4); `y` is written by
`x` (4) and again by `u` (5). The three extra enqueues (`x`, `u`, `y`) account for 11 − 8. The
`continue` guard hides the duplicates from the dequeue order, which is why that line looks fine.

## The Concept This Illustrates

BFS is correct because the first vertex to reach `v` does so along a shortest path: the queue is
processed in nondecreasing order of distance, and `d[v]` is written exactly once, at discovery. The
state change that prevents re-processing ("gray") must therefore happen at the same moment as the
enqueue. Marking on dequeue turns "first to reach" into "last to reach", and on dense graphs the
queue can grow far beyond |V| because the same vertex is pushed by every earlier neighbor.

## The Correction

```python
# before
dist[source] = 0
queue = deque([source])
...
    u = queue.popleft()
    if visited[u]:
        continue
    visited[u] = True
    order.append(u)
    for v in adj[u]:
        if not visited[v]:
            dist[v] = dist[u] + 1

# after
dist[source] = 0
visited[source] = True
queue = deque([source])
...
    u = queue.popleft()
    order.append(u)
    for v in adj[u]:
        if not visited[v]:
            visited[v] = True
            dist[v] = dist[u] + 1
```

## Instructor Notes

- An equivalent fix drops `visited` entirely and tests `dist[v] is None` (the distance doubles as the
  white/gray marker, which is what CLRS's `d = ∞` does). Accept it, and ask whether the `visited`
  dictionary is then doing anything.
- Students who mark on enqueue but forget `visited[source] = True` get a program that hangs: `r`
  re-enqueues `s` with `dist[s] = 2` and `parent[s] = r`, creating a parent cycle that `path_to`
  follows forever. That is a good moment to ask what the source's state should be *before* the loop.
- Students who only delete the `if visited[u]: continue` guard make things worse (14 enqueues, the
  dequeue order shows repeats, distances still wrong). Ask them to predict the output before running.
- Follow-up: on a tree the buggy program is correct, because every vertex has exactly one neighbor
  closer to the source and so exactly one writer. Ask which edges of this graph create the second
  writers (the edges `t–x`, `x–u`, `u–y` between vertices at the same or adjacent levels).
