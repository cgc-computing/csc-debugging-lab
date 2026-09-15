// array_stack.cpp
// An integer stack stored in a fixed-capacity array, with a short driver
// that pushes a few values and pops them back off.

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* items;
    int capacity;
    int top;        // number of items currently stored

public:
    ArrayStack(int cap) : capacity(cap), top(0) {
        items = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            items[i] = 0;          // start with clean storage
        }
    }

    ~ArrayStack() { delete[] items; }

    bool isEmpty() const { return top == 0; }
    bool isFull() const { return top == capacity; }
    int size() const { return top; }

    bool push(int value) {
        if (isFull()) {
            return false;
        }
        items[top] = value;
        top++;
        return true;
    }

    // Returns the top value without removing it. The stack must not be empty.
    int peek() const {
        return items[top - 1];
    }

    // Removes and returns the top value. The stack must not be empty.
    int pop() {
        top--;
        int value = items[top];
        return value;
    }
};

int main() {
    ArrayStack stack(8);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "size after 3 pushes: " << stack.size() << endl;
    cout << "peek: " << stack.peek() << endl;

    cout << "popping:";
    while (!stack.isEmpty()) {
        cout << " " << stack.pop();
    }
    cout << endl;

    stack.push(7);
    cout << "peek after pushing 7: " << stack.peek() << endl;
    cout << "empty? " << (stack.isEmpty() ? "yes" : "no") << endl;
    return 0;
}
