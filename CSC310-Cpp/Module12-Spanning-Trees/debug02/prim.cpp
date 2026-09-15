// prim.cpp
// Prim's minimum spanning tree algorithm (CLRS 21.2) with a binary heap
// (std::priority_queue, lazy deletion). key[v] is the weight of the lightest
// edge connecting v to the tree built so far; the vertex with the smallest
// key joins the tree next.
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

const int INF = std::numeric_limits<int>::max();

struct Neighbor {
    int to, weight;
};

int prim(const std::vector<std::vector<Neighbor>>& adj, int root, std::vector<int>& parent) {
    const int n = static_cast<int>(adj.size());
    std::vector<int> key(n, INF);
    std::vector<bool> inTree(n, false);
    parent.assign(n, -1);
    using Entry = std::pair<int, int>;   // (key, vertex)
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;

    key[root] = 0;
    pq.push({0, root});
    int total = 0;
    while (!pq.empty()) {
        auto [k, u] = pq.top();
        pq.pop();
        if (inTree[u]) {
            continue;   // stale entry
        }
        inTree[u] = true;
        total += key[u];
        for (const Neighbor& nb : adj[u]) {
            int v = nb.to;
            if (!inTree[v] && key[u] + nb.weight < key[v]) {
                key[v] = key[u] + nb.weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    return total;
}

int main() {
    const std::string names = "abcdefghi";
    const int n = 9;
    std::vector<std::vector<Neighbor>> adj(n);
    auto edge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    edge(0, 1, 4); edge(0, 7, 8); edge(1, 2, 8); edge(1, 7, 11); edge(2, 3, 7);
    edge(2, 5, 4); edge(2, 8, 2); edge(3, 4, 9); edge(3, 5, 14); edge(4, 5, 10);
    edge(5, 6, 2); edge(6, 7, 1); edge(6, 8, 6); edge(7, 8, 7);

    std::vector<int> parent;
    int total = prim(adj, 0, parent);
    std::cout << "tree edges (parent-child):\n";
    for (int v = 0; v < n; ++v) {
        if (parent[v] >= 0) {
            int w = 0;
            for (const Neighbor& nb : adj[v]) {
                if (nb.to == parent[v]) w = nb.weight;
            }
            std::cout << "  " << names[parent[v]] << "-" << names[v] << " (" << w << ")\n";
        }
    }
    std::cout << "total weight: " << total << '\n';
    return 0;
}
