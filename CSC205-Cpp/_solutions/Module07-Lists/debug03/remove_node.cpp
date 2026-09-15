// remove_node.cpp
// A singly linked list of integers with a remove(value) operation that
// unlinks and frees the first node holding the given value.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void addFirst(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        count++;
    }

    // Removes the first node containing value. Returns false if not found.
    bool remove(int value) {
        Node* previous = nullptr;
        Node* current = head;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            return false;
        }
        if (previous == nullptr) {
            head = current->next;          // removing the first node
        } else {
            previous->next = current->next;
        }
        delete current;                    // unlink first, then free
        count--;
        return true;
    }

    int size() const { return count; }

    void print() const {
        cout << "[";
        for (Node* current = head; current != nullptr; current = current->next) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ", ";
            }
        }
        cout << "]  size=" << count << endl;
    }
};

int main() {
    LinkedList list;
    for (int v : { 50, 40, 30, 20, 10 }) {
        list.addFirst(v);
    }
    list.print();

    cout << "remove 30: " << (list.remove(30) ? "removed" : "not found") << "  ";
    list.print();

    cout << "remove 99: " << (list.remove(99) ? "removed" : "not found") << "  ";
    list.print();

    cout << "remove 10: " << (list.remove(10) ? "removed" : "not found") << "  ";
    list.print();

    cout << "remove 50: " << (list.remove(50) ? "removed" : "not found") << "  ";
    list.print();
    return 0;
}
