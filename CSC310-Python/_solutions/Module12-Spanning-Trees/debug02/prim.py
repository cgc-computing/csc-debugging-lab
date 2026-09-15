"""Prim's minimum spanning tree algorithm (CLRS Section 21.2).

prim(adj, root) grows a single tree outward from the root.  For every
vertex v not yet in the tree, key[v] is the weight of the lightest edge
joining v to the tree built so far; the vertex with the smallest key is
added next.  A binary heap with lazy deletion plays the role of the
min-priority queue.  The main block builds the tree for the weighted
nine-vertex example graph of CLRS Chapter 21, starting at vertex a.
"""

import heapq

INF = float("inf")


def prim(adj, root):
    key = {v: INF for v in adj}
    parent = {v: None for v in adj}
    in_tree = {v: False for v in adj}
    key[root] = 0
    heap = [(0, root)]
    while heap:
        _, u = heapq.heappop(heap)
        if in_tree[u]:
            continue
        in_tree[u] = True
        for v, w in adj[u]:
            if not in_tree[v] and w < key[v]:
                key[v] = w
                parent[v] = u
                heapq.heappush(heap, (key[v], v))
    return parent, key


def build_graph(edges):
    adj = {}
    for u, v, w in edges:
        adj.setdefault(u, []).append((v, w))
        adj.setdefault(v, []).append((u, w))
    return adj


def main():
    # The nine-vertex example graph of CLRS Chapter 21
    edges = [
        ("a", "b", 4), ("a", "h", 8), ("b", "c", 8), ("b", "h", 11),
        ("c", "d", 7), ("c", "f", 4), ("c", "i", 2), ("d", "e", 9),
        ("d", "f", 14), ("e", "f", 10), ("f", "g", 2), ("g", "h", 1),
        ("g", "i", 6), ("h", "i", 7),
    ]
    adj = build_graph(edges)
    parent, key = prim(adj, "a")
    print("tree edges (parent-child):")
    total = 0
    for v in sorted(adj):
        if parent[v] is not None:
            print(f"  {parent[v]}-{v} ({key[v]})")
            total += key[v]
    print("total weight:", total)


if __name__ == "__main__":
    main()
