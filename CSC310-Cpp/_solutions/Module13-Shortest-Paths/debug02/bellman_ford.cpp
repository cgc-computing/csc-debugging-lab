// bellman_ford.cpp
// Bellman-Ford single-source shortest paths (CLRS 22.1). Handles negative
// edge weights and reports whether a negative-weight cycle is reachable from
// the source. The driver runs it on three small directed graphs.
#include <iostream>
#include <limits>
#include <string>
#include <vector>

const long INF = std::numeric_limits<long>::max() / 4;

struct Edge {
    int u, v;
    long weight;
};

// Returns true if shortest paths are well defined (no reachable negative
// cycle) and fills dist; returns false if a negative cycle was detected.
bool bellmanFord(int n, const std::vector<Edge>& edges, int source, std::vector<long>& dist) {
    dist.assign(n, INF);
    dist[source] = 0;
    for (int pass = 1; pass <= n - 1; ++pass) {
        for (const Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
    }
    for (const Edge& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
            return false;
        }
    }
    return true;
}

void report(const std::string& label, int n, const std::vector<Edge>& edges, int source) {
    std::vector<long> dist;
    std::cout << label << ": ";
    if (!bellmanFord(n, edges, source, dist)) {
        std::cout << "negative-weight cycle reachable from the source\n";
        return;
    }
    std::cout << "distances from " << source << ":";
    for (int v = 0; v < n; ++v) {
        std::cout << ' ' << v << '=';
        if (dist[v] == INF) std::cout << "inf";
        else std::cout << dist[v];
    }
    std::cout << '\n';
}

int main() {
    // CLRS's Bellman-Ford worked example (§22.1): vertices s=0 t=1 x=2 y=3 z=4
    report("textbook graph", 5,
           {{1, 2, 5}, {1, 3, 8}, {1, 4, -4}, {2, 1, -2}, {3, 2, -3},
            {3, 4, 9}, {4, 2, 7}, {4, 0, 2}, {0, 1, 6}, {0, 3, 7}},
           0);
    // A simple chain whose edges are listed from the far end back to the source.
    report("chain", 5, {{3, 4, 1}, {2, 3, 1}, {1, 2, 1}, {0, 1, 1}}, 0);
    // A graph that really does contain a negative cycle (1 -> 2 -> 1).
    report("bad loop", 4, {{0, 1, 4}, {1, 2, -3}, {2, 1, 1}, {2, 3, 2}}, 0);
    return 0;
}
