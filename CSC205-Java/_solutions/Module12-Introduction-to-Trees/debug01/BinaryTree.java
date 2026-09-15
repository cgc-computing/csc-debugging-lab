// A binary tree of integers built by hand, with the three depth-first traversals.
public class BinaryTree {
    private static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
        }
    }

    private Node root;

    // Builds the tree used in this activity:
    //           4
    //         /   \
    //        2     6
    //       / \   / \
    //      1   3 5   7
    public static BinaryTree sample() {
        BinaryTree t = new BinaryTree();
        t.root = new Node(4);
        t.root.left = new Node(2);
        t.root.right = new Node(6);
        t.root.left.left = new Node(1);
        t.root.left.right = new Node(3);
        t.root.right.left = new Node(5);
        t.root.right.right = new Node(7);
        return t;
    }

    public String preOrder() {
        StringBuilder sb = new StringBuilder();
        preOrder(root, sb);
        return sb.toString().trim();
    }

    private void preOrder(Node n, StringBuilder sb) {
        if (n == null) {
            return;
        }
        sb.append(n.value).append(' ');
        preOrder(n.left, sb);
        preOrder(n.right, sb);
    }

    public String inOrder() {
        StringBuilder sb = new StringBuilder();
        inOrder(root, sb);
        return sb.toString().trim();
    }

    private void inOrder(Node n, StringBuilder sb) {
        if (n == null) {
            return;
        }
        inOrder(n.left, sb);
        sb.append(n.value).append(' ');
        inOrder(n.right, sb);
    }

    public String postOrder() {
        StringBuilder sb = new StringBuilder();
        postOrder(root, sb);
        return sb.toString().trim();
    }

    private void postOrder(Node n, StringBuilder sb) {
        if (n == null) {
            return;
        }
        postOrder(n.left, sb);
        postOrder(n.right, sb);
        sb.append(n.value).append(' ');
    }
}
