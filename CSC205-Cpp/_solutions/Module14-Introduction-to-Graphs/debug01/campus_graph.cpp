// campus_graph.cpp
// An undirected graph of campus buildings connected by walkways, stored as
// an adjacency list. The driver lists which buildings can be reached from a
// few starting points using breadth-first search.

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacent;

public:
    Graph(int n) : numVertices(n), adjacent(n) {}

    // Adds an undirected walkway between buildings u and v.
    void addEdge(int u, int v) {
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);      // undirected: record both directions
    }

    // Returns the vertices reachable from start, in BFS order.
    vector<int> bfs(int start) const {
        vector<bool> visited(numVertices, false);
        vector<int> order;
        queue<int> pending;

        visited[start] = true;
        pending.push(start);
        while (!pending.empty()) {
            int u = pending.front();
            pending.pop();
            order.push_back(u);
            for (int v : adjacent[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    pending.push(v);
                }
            }
        }
        return order;
    }
};

int main() {
    const string names[] = { "Library", "Science", "Union", "Gym", "Dorms", "Annex", "Garage" };
    Graph campus(7);
    campus.addEdge(0, 1);   // Library - Science
    campus.addEdge(0, 2);   // Library - Union
    campus.addEdge(1, 3);   // Science - Gym
    campus.addEdge(2, 3);   // Union - Gym
    campus.addEdge(3, 4);   // Gym - Dorms
    campus.addEdge(5, 6);   // Annex - Garage

    for (int start : { 0, 4, 5 }) {
        vector<int> reached = campus.bfs(start);
        cout << "From " << names[start] << " (" << reached.size() << " reachable):";
        for (int v : reached) {
            cout << " " << names[v];
        }
        cout << endl;
    }
    return 0;
}
