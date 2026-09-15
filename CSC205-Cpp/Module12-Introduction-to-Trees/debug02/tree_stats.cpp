// tree_stats.cpp
// Builds a small binary tree of integers by hand and reports its node count,
// leaf count, and height. Height is measured in edges: a tree with a single
// node has height 0, and the empty tree has height -1.

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r) {}
};

// Total number of nodes in the tree.
int countNodes(const Node* node) {
    if (node == nullptr) {
        return 0;
    }
    countNodes(node->left);
    return 1 + countNodes(node->right);
}

// Number of nodes that have no children.
int countLeaves(const Node* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}

// Number of edges on the longest path from node down to a leaf.
int height(const Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

void destroy(Node* node) {
    if (node == nullptr) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int main() {
    //            1
    //          /   \
    //         2     3
    //        / \     \
    //       4   5     6
    //      /         / \
    //     7         8   9
    Node* root = new Node(1,
                          new Node(2,
                                   new Node(4, new Node(7), nullptr),
                                   new Node(5)),
                          new Node(3,
                                   nullptr,
                                   new Node(6, new Node(8), new Node(9))));

    Node* single = new Node(42);

    cout << "Main tree:   nodes=" << countNodes(root)
         << " leaves=" << countLeaves(root)
         << " height=" << height(root) << endl;
    cout << "Single node: nodes=" << countNodes(single)
         << " leaves=" << countLeaves(single)
         << " height=" << height(single) << endl;
    cout << "Empty tree:  nodes=" << countNodes(nullptr)
         << " leaves=" << countLeaves(nullptr)
         << " height=" << height(nullptr) << endl;

    destroy(root);
    destroy(single);
    return 0;
}
