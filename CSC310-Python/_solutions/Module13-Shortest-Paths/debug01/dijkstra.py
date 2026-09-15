"""Dijkstra's single-source shortest paths (CLRS Section 22.3).

dijkstra(adj, source) works on a directed graph with non-negative edge
weights.  A binary heap holds (distance, vertex) pairs; because heapq has
no decrease-key, a vertex is pushed again whenever a shorter path to it is
found, and the heap may therefore hold outdated entries.  The main block
runs the algorithm on the example graph of CLRS Section 22.3 from source s
and
prints each vertex's distance and shortest path.
"""

import heapq

INF = float("inf")


def dijkstra(adj, source):
    dist = {v: INF for v in adj}
    parent = {v: None for v in adj}
    dist[source] = 0
    heap = [(0, source)]
    removed = 0
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        removed += 1
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                heapq.heappush(heap, (dist[v], v))
    return dist, parent, removed


def path_to(parent, v):
    path = []
    while v is not None:
        path.append(v)
        v = parent[v]
    return " -> ".join(reversed(path))


def main():
    # The example graph of CLRS Section 22.3
    edges = [
        ("s", "t", 10), ("s", "y", 5), ("t", "x", 1), ("t", "y", 2),
        ("x", "z", 4), ("y", "t", 3), ("y", "x", 9), ("y", "z", 2),
        ("z", "s", 7), ("z", "x", 6),
    ]
    adj = {v: [] for v in "stxyz"}
    for u, v, w in edges:
        adj[u].append((v, w))

    dist, parent, removed = dijkstra(adj, "s")
    print("shortest paths from s")
    for v in sorted(adj):
        print(f"  {v}: dist {dist[v]}   path {path_to(parent, v)}")
    print(f"vertices removed from the queue: {removed} (vertices: {len(adj)})")


if __name__ == "__main__":
    main()
