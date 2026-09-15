// expression_tree.cpp
// Builds the binary tree for the expression (3 + 4) * (5 - 2) by hand and
// prints it with the three standard traversals, then evaluates it.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string token;      // an operator (+ - *) or a number
    Node* left;
    Node* right;
    Node(const string& t, Node* l = nullptr, Node* r = nullptr)
        : token(t), left(l), right(r) {}
};

// Root, then left subtree, then right subtree.
void preorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->token << " ";
    preorder(node->left);
    preorder(node->right);
}

// Left subtree, then root, then right subtree.
void inorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->token << " ";
    inorder(node->right);
}

// Left subtree, then right subtree, then root.
void postorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->token << " ";
}

// Evaluates the expression tree rooted at node.
int evaluate(const Node* node) {
    if (node->left == nullptr && node->right == nullptr) {
        return stoi(node->token);
    }
    int a = evaluate(node->left);
    int b = evaluate(node->right);
    if (node->token == "+") return a + b;
    if (node->token == "-") return a - b;
    return a * b;
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
    //        *
    //      /   \
    //     +     -
    //    / \   / \
    //   3   4 5   2
    Node* root = new Node("*",
                          new Node("+", new Node("3"), new Node("4")),
                          new Node("-", new Node("5"), new Node("2")));

    cout << "Pre-order:  ";  preorder(root);  cout << endl;
    cout << "In-order:   ";  inorder(root);   cout << endl;
    cout << "Post-order: ";  postorder(root); cout << endl;
    cout << "Value:      " << evaluate(root) << endl;

    destroy(root);
    return 0;
}
