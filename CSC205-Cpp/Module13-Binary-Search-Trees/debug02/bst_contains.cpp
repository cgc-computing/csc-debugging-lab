// bst_contains.cpp
// A binary search tree of member ID numbers. The driver builds the tree and
// then checks a series of IDs to see whether each one is a member.

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class MemberTree {
private:
    Node* root;
    int count;

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            count++;
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;               // duplicate keys are ignored
    }

    // Returns true if key is stored somewhere in the subtree at node.
    bool contains(const Node* node, int key) const {
        if (node == nullptr) {
            return false;
        }
        if (key <= node->key) {
            return contains(node->left, key);
        } else if (key > node->key) {
            return contains(node->right, key);
        } else {
            return true;
        }
    }

    void printInOrder(const Node* node) const {
        if (node == nullptr) {
            return;
        }
        printInOrder(node->left);
        cout << node->key << " ";
        printInOrder(node->right);
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
    MemberTree() : root(nullptr), count(0) {}
    ~MemberTree() { destroy(root); }

    void add(int key) { root = insert(root, key); }
    bool isMember(int key) const { return contains(root, key); }
    int size() const { return count; }

    void printInOrder() const {
        printInOrder(root);
        cout << endl;
    }
};

int main() {
    MemberTree members;
    int ids[] = { 5000, 2500, 7500, 1200, 3300, 6100, 9000, 3300 };
    for (int id : ids) {
        members.add(id);
    }

    cout << "Members (" << members.size() << "): ";
    members.printInOrder();

    int lookups[] = { 5000, 3300, 9000, 1200, 4000, 8000 };
    for (int id : lookups) {
        cout << "ID " << id << ": " << (members.isMember(id) ? "member" : "not a member") << endl;
    }
    return 0;
}
