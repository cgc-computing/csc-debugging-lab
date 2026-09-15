// bracket_checker.cpp
// Checks whether the brackets ( ) [ ] { } in a string are balanced, using a
// stack of characters implemented as a linked list.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c, Node* n) : data(c), next(n) {}
};

class CharStack {
private:
    Node* top;

public:
    CharStack() : top(nullptr) {}

    ~CharStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const { return top == nullptr; }

    void push(char c) { top = new Node(c, top); }

    // Removes and returns the top character. The stack must not be empty.
    char pop() {
        Node* old = top;
        char c = old->data;
        top = old->next;
        delete old;
        return c;
    }
};

bool isOpening(char c) { return c == '(' || c == '[' || c == '{'; }
bool isClosing(char c) { return c == ')' || c == ']' || c == '}'; }

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Returns true if every bracket in text is closed by the matching kind of
// bracket, in the correct order. Non-bracket characters are ignored.
bool isBalanced(const string& text) {
    CharStack stack;
    for (char c : text) {
        if (isOpening(c)) {
            stack.push(c);
        } else if (isClosing(c)) {
            if (stack.isEmpty()) {
                return false;          // a closer with nothing left to close
            }
            char open = stack.pop();
            if (!matches(open, c)) {
                return false;
            }
        }
    }
    return stack.isEmpty();       // every opener must have been closed
}

int main() {
    string tests[] = {
        "(a + b) * [c - d]",
        "{[()]}",
        "[(])",
        "((a + b)",
        "a + b)",
        "no brackets here"
    };
    for (const string& t : tests) {
        cout << "\"" << t << "\" -> " << (isBalanced(t) ? "balanced" : "NOT balanced") << endl;
    }
    return 0;
}
