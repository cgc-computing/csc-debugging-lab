// Prints the sample tree in each traversal order.
public class Main {
    public static void main(String[] args) {
        BinaryTree tree = BinaryTree.sample();
        System.out.println("pre-order:  " + tree.preOrder());
        System.out.println("in-order:   " + tree.inOrder());
        System.out.println("post-order: " + tree.postOrder());
    }
}
