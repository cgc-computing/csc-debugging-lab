"""Disjoint-set forest with union by rank and path compression
(CLRS Section 19.3), used to count the connected components of an
undirected graph given as an edge list (CONNECTED-COMPONENTS, Section 19.1).
"""


class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.sets = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def _link(self, x, y):
        # x and y must be roots
        if self.rank[x] > self.rank[y]:
            self.parent[y] = x
        else:
            self.parent[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1
        self.sets -= 1

    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if rx != ry:
            self._link(rx, ry)

    def same_set(self, x, y):
        return self.find(x) == self.find(y)


def connected_components(n, edges):
    ds = DisjointSet(n)
    for u, v in edges:
        ds.union(u, v)
    groups = {}
    for v in range(n):
        groups.setdefault(ds.find(v), []).append(v)
    return ds, sorted(groups.values())


def main():
    # The example graph of CLRS Section 19.1: vertices a..j as 0..9
    names = "abcdefghij"
    edges = [(1, 3), (4, 6), (0, 2), (7, 8), (0, 1), (4, 6), (1, 2)]
    ds, comps = connected_components(10, edges)

    print("edges processed:", [(names[u], names[v]) for u, v in edges])
    print("components     :", ["".join(names[v] for v in c) for c in comps])
    print("set count      :", ds.sets)
    print()
    for x, y in [("a", "d"), ("b", "c"), ("e", "g"), ("h", "i"), ("a", "e"), ("j", "j")]:
        print(f"same_set({x}, {y}) = {ds.same_set(names.index(x), names.index(y))}")

    # A second test: a chain of unions that all attach to vertex 0.
    ds2 = DisjointSet(6)
    for v in range(1, 6):
        ds2.union(v - 1, v)
    print()
    print("chain 0-1-2-3-4-5 sets:", ds2.sets,
          " same_set(0,5) =", ds2.same_set(0, 5))


if __name__ == "__main__":
    main()
