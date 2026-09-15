"""Strongly connected components (CLRS Section 20.5).

STRONGLY-CONNECTED-COMPONENTS runs one depth-first search on G to obtain
finishing times, builds the transpose graph, and then runs a second
depth-first search on the transpose, visiting vertices in order of
decreasing finishing time.  Each tree of the second search is one
strongly connected component.  The main block runs the algorithm on the
example graph of CLRS Section 20.5 and on a second small graph.
"""


def dfs_finish_order(adj):
    """Vertices in increasing order of DFS finishing time."""
    visited = set()
    order = []

    def visit(u):
        visited.add(u)
        for v in adj[u]:
            if v not in visited:
                visit(v)
        order.append(u)

    for u in adj:
        if u not in visited:
            visit(u)
    return order


def transpose(adj):
    rev = {v: [] for v in adj}
    for u in adj:
        for v in adj[u]:
            rev[v].append(u)
    return rev


def strongly_connected_components(adj):
    finish_order = dfs_finish_order(adj)
    graph_t = transpose(adj)
    assigned = set()
    components = []

    def collect(u, comp):
        assigned.add(u)
        comp.append(u)
        for v in adj[u]:
            if v not in assigned:
                collect(v, comp)

    for u in finish_order:
        if u not in assigned:
            comp = []
            collect(u, comp)
            components.append(sorted(comp))
    return components


def report(title, adj):
    comps = strongly_connected_components(adj)
    print(f"{title}: {len(comps)} components")
    for comp in comps:
        print("  {" + ", ".join(comp) + "}")


def main():
    # The example graph of CLRS Section 20.5
    clrs = {
        "a": ["b"], "b": ["c", "e", "f"], "c": ["d", "g"], "d": ["c", "h"],
        "e": ["a", "f"], "f": ["g"], "g": ["f", "h"], "h": ["h"],
    }
    report("CLRS example graph", clrs)

    # A chain of three cycles: 1->2->3->1, 4->5->4, 6 alone
    chain = {
        "1": ["2"], "2": ["3"], "3": ["1", "4"], "4": ["5"], "5": ["4", "6"], "6": [],
    }
    report("Three-cycle chain", chain)


if __name__ == "__main__":
    main()
