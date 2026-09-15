// topological_sort.cpp
// Topological sort of a DAG by depth-first search (CLRS 20.4). The example
// is the getting-dressed graph: an edge u -> v means u must be put on before
// v. After producing an order, the driver verifies that every edge points
// forward in it.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> names = {"undershorts", "pants", "belt", "shirt", "tie",
                                        "jacket", "socks", "shoes", "watch"};

void dfsVisit(const std::vector<std::vector<int>>& adj, int u, std::vector<bool>& visited,
              std::vector<int>& order) {
    visited[u] = true;
    order.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsVisit(adj, v, visited, order);
        }
    }
}

std::vector<int> topologicalSort(const std::vector<std::vector<int>>& adj) {
    const int n = static_cast<int>(adj.size());
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            dfsVisit(adj, u, visited, order);
        }
    }
    std::reverse(order.begin(), order.end());
    return order;
}

int main() {
    const int n = static_cast<int>(names.size());
    std::vector<std::vector<int>> adj(n);
    std::vector<std::pair<int, int>> edges = {
        {0, 1}, {0, 7}, {1, 2}, {1, 7}, {2, 5}, {3, 2}, {3, 4}, {4, 5}, {6, 7}};
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
    }

    std::vector<int> order = topologicalSort(adj);
    std::vector<int> position(n);
    std::cout << "order:";
    for (int i = 0; i < n; ++i) {
        position[order[i]] = i;
        std::cout << ' ' << names[order[i]];
    }
    std::cout << '\n';

    int violations = 0;
    for (auto [u, v] : edges) {
        if (position[u] > position[v]) {
            std::cout << "  violated: " << names[u] << " -> " << names[v] << '\n';
            ++violations;
        }
    }
    std::cout << (violations == 0 ? "valid topological order" : "NOT a valid topological order")
              << '\n';
    return 0;
}
