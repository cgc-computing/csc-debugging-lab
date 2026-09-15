"""Topological sort by depth-first search (CLRS Section 20.4).

topological_sort(adj) returns a linear ordering of the vertices of a DAG
such that every edge (u, v) has u before v.  The main block orders the
getting-dressed graph of CLRS Section 20.4 and verifies the ordering
against every edge.
"""


def topological_sort(adj):
    WHITE, GRAY, BLACK = 0, 1, 2
    color = {v: WHITE for v in adj}
    finished = []

    def visit(u):
        color[u] = GRAY
        finished.append(u)
        for v in adj[u]:
            if color[v] == WHITE:
                visit(v)
        color[u] = BLACK

    for u in adj:
        if color[u] == WHITE:
            visit(u)
    return finished


def violations(adj, order):
    position = {v: i for i, v in enumerate(order)}
    return [(u, v) for u in adj for v in adj[u] if position[u] > position[v]]


def main():
    adj = {
        "undershorts": ["pants", "shoes"],
        "pants": ["belt", "shoes"],
        "belt": ["jacket"],
        "shirt": ["belt", "tie"],
        "tie": ["jacket"],
        "socks": ["shoes"],
        "watch": [],
        "shoes": [],
        "jacket": [],
    }
    order = topological_sort(adj)
    print("order:")
    for i, v in enumerate(order, 1):
        print(f"  {i}. {v}")
    bad = violations(adj, order)
    print("edges out of order:", bad if bad else "none")
    print("valid topological order:", not bad)


if __name__ == "__main__":
    main()
