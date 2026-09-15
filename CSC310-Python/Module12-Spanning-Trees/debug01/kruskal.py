"""Kruskal's minimum spanning tree algorithm (CLRS Section 21.2).

kruskal(vertices, edges) sorts the edges by weight and accepts each edge
whose endpoints currently lie in different components, tracking the
components with a disjoint-set forest (union by rank, path compression).
The main block runs the algorithm on the nine-vertex example graph of CLRS Chapter 21
and reports the chosen edges, their count, and the total weight.
"""


class DisjointSet:
    def __init__(self, items):
        self.parent = {x: x for x in items}
        self.rank = {x: 0 for x in items}

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if rx == ry:
            return
        if self.rank[rx] < self.rank[ry]:
            rx, ry = ry, rx
        self.parent[ry] = rx
        if self.rank[rx] == self.rank[ry]:
            self.rank[rx] += 1


def kruskal(vertices, edges):
    ds = DisjointSet(vertices)
    tree = []
    # Python's sort is stable, so equal weights keep their listed order.
    for u, v, w in sorted(edges, key=lambda e: e[2]):
        if ds.parent[u] != ds.parent[v]:
            tree.append((u, v, w))
            ds.union(u, v)
    return tree


def main():
    # The nine-vertex example graph of CLRS Chapter 21
    vertices = list("abcdefghi")
    edges = [
        ("a", "b", 4), ("a", "h", 8), ("b", "c", 8), ("b", "h", 11),
        ("c", "d", 7), ("c", "f", 4), ("c", "i", 2), ("d", "e", 9),
        ("d", "f", 14), ("e", "f", 10), ("f", "g", 2), ("g", "h", 1),
        ("g", "i", 6), ("h", "i", 7),
    ]
    tree = kruskal(vertices, edges)
    print("edges chosen:")
    for u, v, w in tree:
        print(f"  {u}-{v} ({w})")
    print(f"tree edges: {len(tree)} (a spanning tree on {len(vertices)} "
          f"vertices has {len(vertices) - 1})")
    print("total weight:", sum(w for _, _, w in tree))


if __name__ == "__main__":
    main()
