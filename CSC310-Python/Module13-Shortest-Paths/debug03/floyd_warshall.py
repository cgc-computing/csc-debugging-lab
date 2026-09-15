"""Floyd-Warshall all-pairs shortest paths (CLRS Section 23.2).

floyd_warshall(W) takes the weight matrix of a directed graph with no
negative-weight cycles and returns the matrix D of shortest-path weights
together with a predecessor matrix for reconstructing paths.  The
dynamic-programming idea: d[i][j] is improved by allowing one more vertex
k to serve as an intermediate vertex on the path from i to j.  The main
block runs the algorithm on the five-vertex example graph of CLRS Chapter 23,
prints both
matrices, and reconstructs a few shortest paths.
"""

INF = float("inf")


def floyd_warshall(W):
    n = len(W)
    d = [row[:] for row in W]
    pred = [[None if i == j or W[i][j] == INF else i for j in range(n)]
            for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]
                    pred[i][j] = pred[k][j]
    return d, pred


def path_between(pred, i, j):
    path = [j]
    while j != i and len(path) <= len(pred):
        j = pred[i][j]
        path.append(j)
    return " -> ".join(str(v + 1) for v in reversed(path))


def print_matrix(title, M):
    print(title)
    for row in M:
        print("  " + " ".join(f"{'inf' if x == INF else x:>4}" for x in row))


def main():
    # The five-vertex example graph of CLRS Chapter 23, vertices 1..5 stored as 0..4
    W = [
        [0,   3,   8,   INF, -4],
        [INF, 0,   INF, 1,   7],
        [INF, 4,   0,   INF, INF],
        [2,   INF, -5,  0,   INF],
        [INF, INF, INF, 6,   0],
    ]
    print_matrix("weight matrix W:", W)
    D, pred = floyd_warshall(W)
    print_matrix("shortest-path weights D:", D)
    print("sample paths:")
    for i, j in [(0, 1), (0, 2), (4, 0)]:
        print(f"  {i + 1} to {j + 1}: {path_between(pred, i, j)}   (weight {D[i][j]})")


if __name__ == "__main__":
    main()
