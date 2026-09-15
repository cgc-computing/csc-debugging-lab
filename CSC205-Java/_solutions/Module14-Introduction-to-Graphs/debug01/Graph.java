// An undirected graph stored as adjacency lists, with breadth-first search.
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

    // Adds the undirected edge between u and v.
    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    public List<Integer> neighbors(int v) {
        return adj.get(v);
    }

    // Vertices in the order BFS first reaches them, starting from source.
    public List<Integer> bfsOrder(int source) {
        boolean[] visited = new boolean[vertexCount];
        List<Integer> order = new ArrayList<>();
        Queue<Integer> queue = new ArrayDeque<>();

        visited[source] = true;
        queue.add(source);
        while (!queue.isEmpty()) {
            int u = queue.remove();
            order.add(u);
            for (int v : adj.get(u)) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.add(v);
                }
            }
        }
        return order;
    }

    public String adjacencyTable() {
        StringBuilder sb = new StringBuilder();
        for (int v = 0; v < vertexCount; v++) {
            sb.append(v).append(": ").append(adj.get(v)).append('\n');
        }
        return sb.toString();
    }
}
