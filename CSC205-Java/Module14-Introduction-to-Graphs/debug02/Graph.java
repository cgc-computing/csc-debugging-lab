// An undirected graph stored as adjacency lists. BFS computes the
// number of edges on the shortest path from a source to every vertex.
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class Graph {
    private final int vertexCount;
    private final List<List<Integer>> adj;

    public Graph(int vertexCount) {
        this.vertexCount = vertexCount;
        adj = new ArrayList<>();
        for (int v = 0; v < vertexCount; v++) {
            adj.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // dist[v] = shortest-path length (in edges) from source to v.
    // Also records every vertex in the order it is taken off the queue.
    public int[] bfsDistances(int source, List<Integer> dequeued) {
        boolean[] visited = new boolean[vertexCount];
        int[] dist = new int[vertexCount];
        Queue<Integer> queue = new ArrayDeque<>();

        dist[source] = 0;
        queue.add(source);
        while (!queue.isEmpty()) {
            int u = queue.remove();
            visited[u] = true;
            dequeued.add(u);
            for (int v : adj.get(u)) {
                if (!visited[v]) {
                    dist[v] = dist[u] + 1;
                    queue.add(v);
                }
            }
        }
        return dist;
    }
}
