// kruskal.cpp
// Kruskal's minimum spanning tree algorithm (CLRS 21.2) with a disjoint-set
// forest. Edges are examined in order of increasing weight and an edge is
// added to the tree when its endpoints are in different components.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Edge {
    int u, v, weight;
};

int find(std::vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unite(std::vector<int>& parent, int a, int b) {
    parent[find(parent, a)] = find(parent, b);
}

std::vector<Edge> kruskal(int n, std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        if (a.weight != b.weight) return a.weight < b.weight;
        if (a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    std::vector<Edge> tree;
    for (const Edge& e : edges) {
        if (parent[e.u] != parent[e.v]) {
            tree.push_back(e);
            unite(parent, e.u, e.v);
        }
    }
    return tree;
}

int main() {
    const std::string names = "abcdefghi";
    const int n = 9;
    std::vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2},
        {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};

    std::vector<Edge> tree = kruskal(n, edges);
    int total = 0;
    std::cout << "edges chosen:\n";
    for (const Edge& e : tree) {
        std::cout << "  " << names[e.u] << "-" << names[e.v] << " (" << e.weight << ")\n";
        total += e.weight;
    }
    std::cout << "tree edges: " << tree.size() << " (a spanning tree on " << n
              << " vertices has " << n - 1 << ")\n";
    std::cout << "total weight: " << total << '\n';
    return 0;
}
