# Solution: Dijkstra's Shortest Paths

**Course/Module/Activity:** CSC310 · Module 13 Shortest Paths · debug01
**Bug type(s):** conceptual/design (distance estimates not maintained; outdated heap entries treated as fresh)
**Bug count:** 1 misconception (the correction touches the initialization, the pop, and the relaxation)

## Observed Behavior

```
shortest paths from s
  s: dist 0   path s
  t: dist 10   path s -> y -> t
  x: dist 14   path s -> y -> t -> x
  y: dist 5   path s -> y
  z: dist 7   path s -> y -> z
vertices removed from the queue: 8 (vertices: 5)
```

The paths are right but `dist[t]` and `dist[x]` are 10 and 14 instead of 8 and 9 — each path's printed
distance disagrees with the sum of its own edge weights — and vertices were removed from the heap 8
times.

## The Bug(s)

`dijkstra.py`, function `dijkstra`:

```python
while heap:
    d, u = heapq.heappop(heap)
    removed += 1
    dist[u] = d                       # runs on every pop, including outdated ones
    for v, w in adj[u]:
        if d + w < dist[v]:           # dist[v] is still INF until v itself is popped
            parent[v] = u
            heapq.heappush(heap, (d + w, v))
```

The distance is recorded only when a vertex is popped, and it is recorded on *every* pop; nothing
recognizes that a popped entry may be outdated.

## Why the Program Behaved Incorrectly

Because `dist[v]` stays `INF` until `v` is popped, every edge into a not-yet-popped vertex pushes an
entry, and `parent[v]` is overwritten by each push. `t` is pushed as `(10, t)` from `s` and `(8, t)`
from `y`; `x` is pushed as `(14, x)` from `y`, `(13, x)` from `z` and `(9, x)` from `t`. The first pop
of each vertex is correct (`t` at 8, `x` at 9), but the outdated entries are popped later and
`dist[u] = d` overwrites the correct value with 10 and then 13 and 14. The parent pointers were set at
*push* time, and the last push for `t` was the good one from `y`, so the printed paths are right while
the printed distances come from the last *pop*. The 3 outdated pops account for 8 − 5.

## The Concept This Illustrates

Dijkstra's algorithm maintains `d[v]` as a shortest-path *estimate* that relaxation only ever lowers,
and a vertex's estimate becomes final at the moment it is extracted with the minimum key. With a heap
that cannot decrease keys, the heap entry is only a snapshot of `d[v]` at push time; the truth lives in
`dist`, and any popped entry whose recorded distance exceeds the current `dist[u]` is stale and must
be skipped. Writing `dist[u] = d` on every pop lets a stale snapshot overwrite a finalized value.

## The Correction

```python
# before
heap = [(0, source)]
...
    d, u = heapq.heappop(heap)
    removed += 1
    dist[u] = d
    for v, w in adj[u]:
        if d + w < dist[v]:
            parent[v] = u
            heapq.heappush(heap, (d + w, v))

# after
dist[source] = 0
heap = [(0, source)]
...
    d, u = heapq.heappop(heap)
    if d > dist[u]:
        continue
    removed += 1
    for v, w in adj[u]:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            parent[v] = u
            heapq.heappush(heap, (dist[v], v))
```

## Instructor Notes

- Two one-line fixes also work and are worth discussing. Inserting `if d > dist[u]: continue` before
  `dist[u] = d` (with `dist[u]` still `INF` on the first pop) skips stale entries; inserting
  `if dist[u] != INF: continue` treats the first pop as final (a "finished set"). Both give the
  expected output. Ask why the first pop is guaranteed to be the shortest distance, and what property
  of the edge weights that argument uses (non-negativity — a good bridge to Bellman-Ford in debug02).
- Students who add the stale-entry check *after* `dist[u] = d` see no change; ask them what `dist[u]`
  holds at the moment of the comparison.
- The one-line variants still push an entry for every edge; the CLRS-style version above pushes only
  on a genuine improvement. Have students count pushes under each version.
- Follow-up: on which graphs is the bug invisible? Whenever no vertex is ever pushed twice, e.g. a
  tree or a graph where the first path found to every vertex is already shortest.
