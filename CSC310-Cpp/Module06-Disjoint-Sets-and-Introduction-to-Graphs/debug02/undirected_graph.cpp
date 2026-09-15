// undirected_graph.cpp
// Adjacency-list representation of an undirected graph. The driver builds
// a small graph, prints each vertex's degree and neighbor list, reports the
// number of edges, and checks whether the graph is connected by a
// depth-first walk from vertex 0.
#include <iostream>
#include <vector>

class Graph {
public:
    explicit Graph(int n) : adj_(n) {}

    void addEdge(int u, int v) {
        adj_[u].push_back(v);
    }

    int vertexCount() const { return static_cast<int>(adj_.size()); }

    int degree(int v) const { return static_cast<int>(adj_[v].size()); }

    const std::vector<int>& neighbors(int v) const { return adj_[v]; }

    // Handshaking: the number of edges is the sum of the degrees.
    int edgeCount() const {
        int total = 0;
        for (int v = 0; v < vertexCount(); ++v) {
            total += degree(v);
        }
        return total;
    }

    bool isConnected() const {
        std::vector<bool> seen(vertexCount(), false);
        int reached = 0;
        dfs(0, seen, reached);
        return reached == vertexCount();
    }

private:
    void dfs(int u, std::vector<bool>& seen, int& reached) const {
        seen[u] = true;
        ++reached;
        for (int v : adj_[u]) {
            if (!seen[v]) {
                dfs(v, seen, reached);
            }
        }
    }

    std::vector<std::vector<int>> adj_;
};

int main() {
    Graph g(5);
    std::pair<int, int> edges[] = {{0, 1}, {1, 2}, {2, 0}, {3, 1}, {4, 3}, {4, 2}};
    for (auto [u, v] : edges) {
        g.addEdge(u, v);
    }

    for (int v = 0; v < g.vertexCount(); ++v) {
        std::cout << "vertex " << v << ": degree " << g.degree(v) << ", neighbors";
        for (int w : g.neighbors(v)) {
            std::cout << ' ' << w;
        }
        std::cout << '\n';
    }
    std::cout << "edges: " << g.edgeCount() << '\n';
    std::cout << "connected: " << (g.isConnected() ? "yes" : "no") << '\n';
    return 0;
}
