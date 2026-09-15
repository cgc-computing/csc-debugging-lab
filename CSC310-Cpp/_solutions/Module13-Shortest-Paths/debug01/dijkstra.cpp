// dijkstra.cpp
// Dijkstra's single-source shortest paths (CLRS 22.3) on a directed graph
// with non-negative weights, using std::priority_queue with lazy deletion.
// Prints the distance and the shortest path to every vertex.
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

const int INF = std::numeric_limits<int>::max();
const std::string names = "stxyz";

struct Neighbor {
    int to, weight;
};

void dijkstra(const std::vector<std::vector<Neighbor>>& adj, int source,
              std::vector<int>& dist, std::vector<int>& parent) {
    const int n = static_cast<int>(adj.size());
    dist.assign(n, INF);
    parent.assign(n, -1);
    std::vector<bool> finalized(n, false);
    using Entry = std::pair<int, int>;   // (distance, vertex)
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;

    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (finalized[u]) {
            continue;   // stale entry left behind by an earlier relaxation
        }
        finalized[u] = true;
        for (const Neighbor& nb : adj[u]) {
            int v = nb.to;
            if (dist[u] + nb.weight < dist[v]) {
                dist[v] = dist[u] + nb.weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(const std::vector<int>& parent, int v) {
    if (parent[v] >= 0) {
        printPath(parent, parent[v]);
        std::cout << " -> ";
    }
    std::cout << names[v];
}

int main() {
    const int n = 5;
    std::vector<std::vector<Neighbor>> adj(n);
    auto edge = [&](char a, char b, int w) {
        adj[names.find(a)].push_back({static_cast<int>(names.find(b)), w});
    };
    edge('s', 't', 10); edge('s', 'y', 5); edge('t', 'x', 1); edge('t', 'y', 2);
    edge('y', 't', 3);  edge('y', 'x', 9); edge('y', 'z', 2); edge('x', 'z', 4);
    edge('z', 's', 7);  edge('z', 'x', 6);

    std::vector<int> dist, parent;
    dijkstra(adj, 0, dist, parent);
    std::cout << "shortest paths from s\n";
    for (int v = 0; v < n; ++v) {
        std::cout << "  " << names[v] << ": dist " << dist[v] << "   path ";
        printPath(parent, v);
        std::cout << '\n';
    }
    return 0;
}
