// bfs_distances.cpp
// Computes the fewest number of hops from a source router to every other
// router in a small network using breadth-first search, and reports how
// many times a router was placed on the queue.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacent;

public:
    Graph(int n) : numVertices(n), adjacent(n) {}

    void addEdge(int u, int v) {
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    int size() const { return numVertices; }
    const vector<int>& neighbors(int u) const { return adjacent[u]; }
};

// Returns dist[v] = number of hops on a shortest path from source to v, or
// -1 if v is unreachable. enqueues counts every push onto the queue.
vector<int> bfsDistances(const Graph& g, int source, int& enqueues) {
    vector<int> dist(g.size(), -1);
    vector<bool> visited(g.size(), false);
    queue<int> pending;

    dist[source] = 0;
    visited[source] = true;
    pending.push(source);
    enqueues = 1;

    while (!pending.empty()) {
        int u = pending.front();
        pending.pop();

        for (int v : g.neighbors(u)) {
            if (!visited[v]) {
                visited[v] = true;          // mark when enqueued, not when dequeued
                dist[v] = dist[u] + 1;
                pending.push(v);
                enqueues++;
            }
        }
    }
    return dist;
}

int main() {
    Graph network(6);
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 2);
    network.addEdge(1, 3);
    network.addEdge(2, 3);
    network.addEdge(3, 4);
    // router 5 is disconnected

    int enqueues = 0;
    vector<int> dist = bfsDistances(network, 0, enqueues);

    cout << "Hops from router 0:" << endl;
    for (int v = 0; v < network.size(); v++) {
        cout << "  router " << v << ": ";
        if (dist[v] < 0) {
            cout << "unreachable" << endl;
        } else {
            cout << dist[v] << endl;
        }
    }
    cout << "Queue pushes: " << enqueues << endl;
    return 0;
}
