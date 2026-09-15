// Builds a BST, then deletes a leaf, a node with one child, and a node with two.
public class Main {
    private static void report(String label, BST t) {
        System.out.println(label + "  in-order: " + t.inOrder() + "   size " + t.size());
    }

    public static void main(String[] args) {
        BST tree = new BST();
        int[] keys = {50, 30, 70, 20, 40, 60, 80};
        for (int k : keys) {
            tree.insert(k);
        }
        report("start:     ", tree);

        tree.delete(20);
        report("delete(20):", tree);
        tree.delete(30);
        report("delete(30):", tree);
        tree.delete(50);
        report("delete(50):", tree);
        tree.delete(70);
        report("delete(70):", tree);
    }
}
