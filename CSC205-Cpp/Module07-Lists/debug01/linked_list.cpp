// linked_list.cpp
// A singly linked list of integers with head and tail pointers.
// Supports adding at the front and back and printing the contents.

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
    Node* tail;
    int count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addFirst(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
        count++;
    }

    void addLast(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
        }
        count++;
    }

    int size() const { return count; }

    void print() const {
        cout << "[";
        for (Node* current = head; current != nullptr; current = current->next) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
        }
        cout << "]  (size " << count << ")" << endl;
    }
};

int main() {
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.addFirst(5);
    list.addLast(40);

    list.print();
    return 0;
}
