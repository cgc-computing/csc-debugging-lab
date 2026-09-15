// A binary tree of integers with a few recursive measurements:
// number of nodes, number of leaves, and height (edges on the longest
// root-to-leaf path; a single node has height 0, an empty tree -1).
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
    //            1
    //          /   \
    //         2     3
    //        / \     \
    //       4   5     6
    //                /
    //               7
    public static BinaryTree sample() {
        BinaryTree t = new BinaryTree();
        t.root = new Node(1);
        t.root.left = new Node(2);
        t.root.right = new Node(3);
        t.root.left.left = new Node(4);
        t.root.left.right = new Node(5);
        t.root.right.right = new Node(6);
        t.root.right.right.left = new Node(7);
        return t;
    }

    public int countNodes() {
        return countNodes(root);
    }

    private int countNodes(Node n) {
        if (n == null) {
            return 0;
        }
        return 1 + countNodes(n.left) + countNodes(n.right);
    }

    public int countLeaves() {
        return countLeaves(root);
    }

    private int countLeaves(Node n) {
        if (n == null) {
            return 0;
        }
        if (n.left == null && n.right == null) {
            return 1;
        }
        return countLeaves(n.left) + countLeaves(n.right);
    }

    public int height() {
        return height(root);
    }

    private int height(Node n) {
        if (n == null) {
            return -1;
        }
        return 1 + Math.max(height(n.left), height(n.right));
    }
}
