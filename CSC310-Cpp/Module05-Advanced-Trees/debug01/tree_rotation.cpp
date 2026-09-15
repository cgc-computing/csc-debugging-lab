// tree_rotation.cpp
// A binary search tree with parent pointers and the LEFT-ROTATE operation
// from CLRS chapter 13. Rotations are the building block of red-black and
// AVL rebalancing; a rotation must preserve the in-order sequence of keys.
#include <iostream>

struct Node {
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    explicit Node(int k) : key(k) {}
};

class Tree {
public:
    ~Tree() { destroy(root_); }

    void insert(int key) {
        Node* y = nullptr;
        Node* x = root_;
        while (x != nullptr) {
            y = x;
            x = (key < x->key) ? x->left : x->right;
        }
        Node* z = new Node(key);
        z->parent = y;
        if (y == nullptr) {
            root_ = z;
        } else if (key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

    Node* find(int key) const {
        Node* x = root_;
        while (x != nullptr && x->key != key) {
            x = (key < x->key) ? x->left : x->right;
        }
        return x;
    }

    // Rotates left around x: x's right child y becomes the subtree root,
    // x becomes y's left child, and y's old left subtree moves under x.
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        y->left = x;
        x->parent = y;
    }

    void printInorder() const {
        std::cout << "inorder:";
        inorder(root_);
        std::cout << '\n';
    }

    void printStructure() const {
        std::cout << "structure (root first, children indented):\n";
        structure(root_, 0);
    }

private:
    static void inorder(const Node* n) {
        if (n == nullptr) return;
        inorder(n->left);
        std::cout << ' ' << n->key;
        inorder(n->right);
    }
    static void structure(const Node* n, int depth) {
        if (n == nullptr) return;
        std::cout << std::string(depth * 2, ' ') << n->key << '\n';
        structure(n->left, depth + 1);
        structure(n->right, depth + 1);
    }
    static void destroy(Node* n) {
        if (n == nullptr) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
    Node* root_ = nullptr;
};

void rotateAt(Tree& t, int key) {
    std::cout << "\nleft-rotate at " << key << '\n';
    Node* x = t.find(key);
    if (x == nullptr || x->right == nullptr) {
        std::cout << "cannot rotate: " << key
                  << (x == nullptr ? " is not in the tree" : " has no right child") << '\n';
        return;
    }
    t.leftRotate(x);
    t.printInorder();
    t.printStructure();
}

int main() {
    Tree t;
    for (int k : {20, 10, 30, 25, 40, 35, 45}) {
        t.insert(k);
    }
    std::cout << "before rotation\n";
    t.printInorder();
    t.printStructure();

    rotateAt(t, 20);
    rotateAt(t, 40);
    return 0;
}
