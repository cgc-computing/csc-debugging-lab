// cycle_detection.cpp
// Detects a directed cycle with depth-first search (CLRS 20.3): a graph has
// a cycle exactly when DFS finds a back edge, i.e. an edge to a vertex that
// is still on the recursion stack. When a cycle is found the driver prints
// it by reading the current DFS path.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

enum class Color { White, Gray, Black };

struct Detector {
    const std::vector<std::vector<int>>& adj;
    std::vector<Color> color;
    std::vector<int> path;       // current recursion stack of vertices
    std::vector<int> cycle;      // filled in when a cycle is found

    explicit Detector(const std::vector<std::vector<int>>& g)
        : adj(g), color(g.size(), Color::White) {}

    bool visit(int u) {
        color[u] = Color::Gray;
        path.push_back(u);
        for (int v : adj[u]) {
            if (color[v] == Color::Gray) {
                // back edge u -> v: the cycle is the path from v to u, then v
                auto start = std::find(path.begin(), path.end(), v);
                cycle.assign(start, path.end());
                cycle.push_back(v);
                return true;
            }
            if (color[v] == Color::White && visit(v)) {
                return true;
            }
        }
        path.pop_back();
        color[u] = Color::Black;
        return false;
    }

    bool hasCycle() {
        for (int u = 0; u < static_cast<int>(adj.size()); ++u) {
            if (color[u] == Color::White && visit(u)) {
                return true;
            }
        }
        return false;
    }
};

void report(const std::string& label, int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
    }
    Detector d(adj);
    std::cout << label << ": ";
    if (d.hasCycle()) {
        std::cout << "cycle found:";
        for (int v : d.cycle) {
            std::cout << ' ' << v;
        }
        std::cout << '\n';
    } else {
        std::cout << "no cycle (graph is a DAG)\n";
    }
}

int main() {
    report("diamond", 4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}});
    report("prerequisites", 6, {{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {1, 5}});
    report("ring road", 5, {{0, 1}, {1, 2}, {2, 3}, {3, 1}, {3, 4}});
    report("self loop", 3, {{0, 1}, {1, 1}, {1, 2}});
    return 0;
}
