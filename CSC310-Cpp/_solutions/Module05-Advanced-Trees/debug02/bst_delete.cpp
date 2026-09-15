// bst_delete.cpp
// Binary search tree with recursive insert and remove. Removal handles the
// three classic cases: leaf, one child, and two children (replace the key
// with its in-order successor, then remove the successor).
#include <iostream>

struct Node {
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    explicit Node(int k) : key(k) {}
};

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

int minKey(const Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->key;
}

// Removes key from the subtree rooted at node and returns the new subtree root.
Node* remove(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else if (node->left == nullptr) {
        Node* r = node->right;
        delete node;
        return r;
    } else if (node->right == nullptr) {
        Node* l = node->left;
        delete node;
        return l;
    } else {
        node->key = minKey(node->right);
        node->right = remove(node->right, node->key);
    }
    return node;
}

void inorder(const Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    std::cout << ' ' << node->key;
    inorder(node->right);
}

int count(const Node* node) {
    return node == nullptr ? 0 : 1 + count(node->left) + count(node->right);
}

void destroy(Node* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void show(const char* label, const Node* root) {
    std::cout << label << " (" << count(root) << " nodes):";
    inorder(root);
    std::cout << '\n';
}

int main() {
    Node* root = nullptr;
    for (int k : {50, 30, 70, 20, 40, 60, 80, 35, 45, 65}) {
        root = insert(root, k);
    }
    show("initial     ", root);

    root = remove(root, 20);
    show("remove 20   ", root);
    root = remove(root, 30);
    show("remove 30   ", root);
    root = remove(root, 50);
    show("remove 50   ", root);
    root = remove(root, 70);
    show("remove 70   ", root);

    destroy(root);
    return 0;
}
