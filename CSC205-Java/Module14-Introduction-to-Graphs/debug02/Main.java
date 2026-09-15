// Finds how many hops each router is from router 0.
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 4);

        List<Integer> dequeued = new ArrayList<>();
        int[] dist = g.bfsDistances(0, dequeued);

        System.out.println("dequeue order: " + dequeued);
        System.out.println("vertices dequeued: " + dequeued.size());
        for (int v = 0; v < dist.length; v++) {
            System.out.println("hops to " + v + ": " + dist[v]);
        }
    }
}
