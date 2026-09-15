"""Bellman-Ford single-source shortest paths (CLRS Section 22.1).

bellman_ford(n, edges, source) handles directed graphs whose edge weights
may be negative.  It makes repeated passes over the edge list, relaxing
every edge, and afterwards checks whether any edge can still be relaxed;
if one can, a negative-weight cycle is reachable from the source and the
function reports failure instead of distances.  The main block runs the
algorithm on the example graph of CLRS Section 22.1, on a simple chain, and
on a
graph that really does contain a negative-weight cycle.
"""

INF = float("inf")


def bellman_ford(n, edges, source):
    dist = [INF] * n
    parent = [None] * n
    dist[source] = 0
    for _ in range(1, n - 1):
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            return None
    return dist


def report(title, n, edges, source):
    dist = bellman_ford(n, edges, source)
    if dist is None:
        print(f"{title}: negative-weight cycle reachable from the source")
    else:
        pairs = " ".join(f"{v}={dist[v]}" for v in range(n))
        print(f"{title}: distances from {source}: {pairs}")


def main():
    # The example graph of CLRS Section 22.1 with s=0, t=1, x=2, y=3, z=4
    textbook = [
        (0, 1, 6), (0, 3, 7), (1, 2, 5), (1, 3, 8), (1, 4, -4),
        (2, 1, -2), (3, 2, -3), (3, 4, 9), (4, 0, 2), (4, 2, 7),
    ]
    report("textbook graph", 5, textbook, 0)

    # A path 0 -> 1 -> 2 -> 3 -> 4; the edge list happens to start at the
    # far end of the path and work back toward the source.
    chain = [(3, 4, 1), (2, 3, 1), (1, 2, 1), (0, 1, 1)]
    report("chain", 5, chain, 0)

    # 1 -> 2 -> 1 has total weight -2, so no shortest paths exist.
    bad_loop = [(0, 1, 1), (1, 2, -3), (2, 1, 1), (2, 3, 2)]
    report("bad loop", 4, bad_loop, 0)


if __name__ == "__main__":
    main()
