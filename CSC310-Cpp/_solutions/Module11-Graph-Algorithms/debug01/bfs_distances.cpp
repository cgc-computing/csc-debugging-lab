// bfs_distances.cpp
// Breadth-first search (CLRS 20.2) on an undirected graph. Computes the
// distance (fewest edges) from a source to every vertex, the BFS-tree parent
// of each vertex, and counts how many times a vertex was placed in the queue.
#include <iostream>
#include <queue>
#include <string>
#include <vector>

const std::vector<std::string> names = {"r", "s", "t", "u", "v", "w", "x", "y"};

struct BfsResult {
    std::vector<int> dist;
    std::vector<int> parent;
    long enqueues;
};

BfsResult bfs(const std::vector<std::vector<int>>& adj, int source) {
    const int n = static_cast<int>(adj.size());
    BfsResult r{std::vector<int>(n, -1), std::vector<int>(n, -1), 0};
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    r.dist[source] = 0;
    visited[source] = true;
    q.push(source);
    ++r.enqueues;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                r.dist[v] = r.dist[u] + 1;
                r.parent[v] = u;
                q.push(v);
                ++r.enqueues;
            }
        }
    }
    return r;
}

int main() {
    const int n = 8;
    std::vector<std::vector<int>> adj(n);
    auto edge = [&](const std::string& a, const std::string& b) {
        int u = 0, v = 0;
        for (int i = 0; i < n; ++i) {
            if (names[i] == a) u = i;
            if (names[i] == b) v = i;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    edge("r", "s"); edge("r", "v"); edge("s", "w"); edge("w", "t"); edge("w", "x");
    edge("t", "x"); edge("t", "u"); edge("x", "u"); edge("x", "y"); edge("u", "y");

    BfsResult r = bfs(adj, 1);   // source s
    std::cout << "BFS from s\n";
    for (int v = 0; v < n; ++v) {
        std::cout << "  " << names[v] << ": dist " << r.dist[v] << ", parent "
                  << (r.parent[v] < 0 ? "-" : names[r.parent[v]]) << '\n';
    }
    std::cout << "vertices enqueued: " << r.enqueues << '\n';
    return 0;
}
