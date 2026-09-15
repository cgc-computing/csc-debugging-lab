// Reports the size, leaf count, and height of the sample tree.
public class Main {
    public static void main(String[] args) {
        BinaryTree tree = BinaryTree.sample();
        System.out.println("nodes:  " + tree.countNodes());
        System.out.println("leaves: " + tree.countLeaves());
        System.out.println("height: " + tree.height());

        BinaryTree empty = new BinaryTree();
        System.out.println("empty tree nodes:  " + empty.countNodes());
        System.out.println("empty tree height: " + empty.height());
    }
}
