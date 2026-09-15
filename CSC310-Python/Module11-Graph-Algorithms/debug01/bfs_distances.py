"""Breadth-first search (CLRS Section 20.2).

bfs(adj, s) computes the shortest-path distance (number of edges) from
the source s to every reachable vertex, together with the BFS tree, and
counts how many times a vertex was placed on the queue.  The main block
runs the search on the undirected example graph of CLRS Section 20.2
from source s.
"""

from collections import deque


def bfs(adj, source):
    dist = {v: None for v in adj}
    parent = {v: None for v in adj}
    visited = {v: False for v in adj}
    enqueued = 0

    dist[source] = 0
    queue = deque([source])
    enqueued += 1
    order = []
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
                enqueued += 1
    return dist, parent, order, enqueued


def path_to(parent, v):
    path = []
    while v is not None:
        path.append(v)
        v = parent[v]
    return "->".join(reversed(path))


def main():
    # The BFS example graph of CLRS Section 20.2 (undirected)
    edges = [("r", "v"), ("r", "s"), ("s", "w"), ("w", "t"), ("w", "x"),
             ("t", "x"), ("t", "u"), ("x", "u"), ("x", "y"), ("u", "y")]
    adj = {v: [] for v in "rstuvwxy"}
    for a, b in edges:
        adj[a].append(b)
        adj[b].append(a)

    dist, parent, order, enqueued = bfs(adj, "s")
    print("dequeue order :", " ".join(order))
    print("times enqueued:", enqueued, "(vertices:", len(adj), ")")
    print()
    for v in sorted(adj):
        print(f"  {v}: dist {dist[v]}   path {path_to(parent, v)}")


if __name__ == "__main__":
    main()
