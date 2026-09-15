// Inserts a handful of keys and prints the resulting tree.
public class Main {
    public static void main(String[] args) {
        BST tree = new BST();
        int[] keys = {50, 30, 70, 20, 40, 60, 80};
        for (int k : keys) {
            tree.insert(k);
        }
        System.out.println("in-order: " + tree.inOrder());
        System.out.println("size:     " + tree.size());
        System.out.println("height:   " + tree.height());
    }
}
