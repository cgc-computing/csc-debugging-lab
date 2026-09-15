// insert_at.cpp
// A singly linked list that supports inserting a value at any position,
// where position 0 is the front and position size() is the back.

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

    int size() const { return count; }

    // Inserts value so that it ends up at the given index.
    // Returns false if the index is out of range.
    bool insertAt(int index, int value) {
        if (index < 0 || index >= count) {
            return false;
        }
        Node* node = new Node(value);
        if (index == 0) {
            node->next = head;
            head = node;
        } else {
            Node* previous = head;
            for (int i = 0; i < index; i++) {
                previous = previous->next;
            }
            node->next = previous->next;
            previous->next = node;
        }
        count++;
        return true;
    }

    void print() const {
        cout << "[";
        for (Node* current = head; current != nullptr; current = current->next) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAt(0, 10);
    list.insertAt(0, 5);
    list.print();                       // [5, 10]

    cout << "insert 7 at 1: " << (list.insertAt(1, 7) ? "ok" : "rejected") << "  ";
    list.print();

    cout << "insert 20 at 3: " << (list.insertAt(3, 20) ? "ok" : "rejected") << "  ";
    list.print();

    cout << "insert 99 at 9: " << (list.insertAt(9, 99) ? "ok" : "rejected") << "  ";
    list.print();

    cout << "size: " << list.size() << endl;
    return 0;
}
