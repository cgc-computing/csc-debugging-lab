// Builds a small campus-shuttle map and runs BFS from two different stops.
public class Main {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 3);
        g.addEdge(3, 4);

        System.out.print(g.adjacencyTable());
        System.out.println("BFS from 0: " + g.bfsOrder(0));
        System.out.println("BFS from 4: " + g.bfsOrder(4));
        System.out.println("BFS from 2: " + g.bfsOrder(2));
    }
}
