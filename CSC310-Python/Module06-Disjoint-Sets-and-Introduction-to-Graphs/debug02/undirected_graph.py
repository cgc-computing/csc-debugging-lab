"""Adjacency-list representation of an undirected graph (CLRS Section 20.1).

The class stores, for every vertex, the list of its neighbours.  It can
report degrees, count edges with the handshake lemma, test for an edge,
and convert itself to an adjacency matrix.  The main block builds the
example graph of CLRS Section 20.1 and prints these views of it.
"""


class UndirectedGraph:
    def __init__(self, vertices):
        self.vertices = list(vertices)
        self.adj = {v: [] for v in self.vertices}

    def add_edge(self, u, v):
        self.adj[u].append(v)

    def degree(self, v):
        return len(self.adj[v])

    def edge_count(self):
        return sum(len(lst) for lst in self.adj.values())

    def has_edge(self, u, v):
        return v in self.adj[u]

    def to_matrix(self):
        index = {v: i for i, v in enumerate(self.vertices)}
        n = len(self.vertices)
        matrix = [[0] * n for _ in range(n)]
        for u in self.vertices:
            for v in self.adj[u]:
                matrix[index[u]][index[v]] = 1
        return matrix

    def is_symmetric(self):
        m = self.to_matrix()
        n = len(m)
        return all(m[i][j] == m[j][i] for i in range(n) for j in range(n))


def main():
    g = UndirectedGraph([1, 2, 3, 4, 5])
    for u, v in [(1, 2), (1, 5), (2, 5), (2, 4), (2, 3), (3, 4), (4, 5)]:
        g.add_edge(u, v)

    print("adjacency lists:")
    for v in g.vertices:
        print(f"  {v}: {g.adj[v]}")
    print()
    degrees = [g.degree(v) for v in g.vertices]
    print("degrees        :", degrees)
    print("sum of degrees :", sum(degrees))
    print("edge count     :", g.edge_count())
    print("has_edge(2, 5) :", g.has_edge(2, 5))
    print("has_edge(5, 2) :", g.has_edge(5, 2))
    print("has_edge(1, 3) :", g.has_edge(1, 3))
    print()
    print("adjacency matrix:")
    for row in g.to_matrix():
        print("  " + " ".join(str(x) for x in row))
    print("symmetric      :", g.is_symmetric())


if __name__ == "__main__":
    main()
