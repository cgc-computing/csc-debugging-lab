// A binary search tree of integers with insert and contains.
// Policy: every key appears at most once; inserting a key that is
// already present leaves the tree unchanged.
public class BST {
    private static class Node {
        int key;
        Node left;
        Node right;

        Node(int key) {
            this.key = key;
        }
    }

    private Node root;
    private int size;

    public void insert(int key) {
        root = insert(root, key);
    }

    private Node insert(Node node, int key) {
        if (node == null) {
            size++;
            return new Node(key);
        }
        if (key <= node.key) {
            node.left = insert(node.left, key);
        } else {
            node.right = insert(node.right, key);
        }
        return node;
    }

    public boolean contains(int key) {
        return contains(root, key);
    }

    private boolean contains(Node node, int key) {
        if (node == null) {
            return false;
        }
        if (key <= node.key) {
            return contains(node.left, key);
        } else if (key > node.key) {
            return contains(node.right, key);
        }
        return true;
    }

    public int size() {
        return size;
    }

    public String inOrder() {
        StringBuilder sb = new StringBuilder();
        inOrder(root, sb);
        return sb.toString().trim();
    }

    private void inOrder(Node node, StringBuilder sb) {
        if (node == null) {
            return;
        }
        inOrder(node.left, sb);
        sb.append(node.key).append(' ');
        inOrder(node.right, sb);
    }
}
