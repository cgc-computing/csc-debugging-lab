// bst_insert.cpp
// A binary search tree of integers built with a recursive insert. The driver
// inserts several values and prints the tree in order along with its size.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Inserts value into the subtree rooted at node and returns the
    // (possibly new) root of that subtree.
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void printInOrder(const Node* node) const {
        if (node == nullptr) {
            return;
        }
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }

    int size(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(int value) { root = insert(root, value); }
    int size() const { return size(root); }

    int min() const {
        const Node* node = root;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    int max() const {
        const Node* node = root;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->data;
    }

    void printInOrder() const {
        printInOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int v : values) {
        tree.insert(v);
    }

    cout << "In order: ";
    tree.printInOrder();
    cout << "Size: " << tree.size() << endl;
    cout << "Min: " << tree.min() << "  Max: " << tree.max() << endl;
    return 0;
}
