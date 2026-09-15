// bst_delete.cpp
// A binary search tree of integers with insert and remove. The driver removes
// a leaf, a node with one child, and nodes with two children, printing the
// tree after each removal.

#include <iostream>
#include <string>
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

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    int minValue(const Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    // Removes value from the subtree at node and returns the subtree's new root.
    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {             // zero or one child
                Node* replacement = node->right;
                delete node;
                return replacement;
            }
            if (node->right == nullptr) {
                Node* replacement = node->left;
                delete node;
                return replacement;
            }
            // Two children: replace this value with its in-order successor.
            node->data = minValue(node->right);
        }
        return node;
    }

    void printInOrder(const Node* node) const {
        if (node == nullptr) return;
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }

    int size(const Node* node) const {
        if (node == nullptr) return 0;
        return 1 + size(node->left) + size(node->right);
    }

    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(int value) { root = insert(root, value); }
    void remove(int value) { root = remove(root, value); }

    void print(const string& label) const {
        cout << label << ": ";
        printInOrder(root);
        cout << " (size " << size(root) << ")" << endl;
    }
};

int main() {
    BST tree;
    for (int v : { 50, 30, 70, 20, 40, 60, 80, 65 }) {
        tree.insert(v);
    }
    tree.print("start         ");

    tree.remove(20);
    tree.print("remove 20     ");
    tree.remove(80);
    tree.print("remove 80     ");
    tree.remove(30);
    tree.print("remove 30     ");
    tree.remove(50);
    tree.print("remove 50     ");
    return 0;
}
