// two_stack_queue.cpp
// A FIFO queue built from two LIFO stacks (an "inbox" and an "outbox").
// Enqueue pushes onto the inbox; dequeue pops from the outbox, refilling
// the outbox from the inbox when necessary. Amortized O(1) per operation.
#include <iostream>
#include <stack>
#include <stdexcept>

class TwoStackQueue {
public:
    void enqueue(int value) {
        inbox_.push(value);
    }

    int dequeue() {
        shift();
        if (outbox_.empty()) {
            throw std::runtime_error("dequeue on empty queue");
        }
        int front = outbox_.top();
        outbox_.pop();
        return front;
    }

    int peek() {
        shift();
        if (outbox_.empty()) {
            throw std::runtime_error("peek on empty queue");
        }
        return outbox_.top();
    }

    bool empty() const {
        return inbox_.empty() && outbox_.empty();
    }

    std::size_t size() const {
        return inbox_.size() + outbox_.size();
    }

private:
    // Move everything from the inbox to the outbox so that the oldest
    // element ends up on top of the outbox. Only done when the outbox is
    // empty; otherwise the outbox already holds older elements.
    void shift() {
        if (!outbox_.empty()) {
            return;
        }
        while (!inbox_.empty()) {
            outbox_.push(inbox_.top());
            inbox_.pop();
        }
    }

    std::stack<int> inbox_;
    std::stack<int> outbox_;
};

int main() {
    TwoStackQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "dequeue -> " << q.dequeue() << '\n';

    q.enqueue(4);
    q.enqueue(5);
    std::cout << "peek    -> " << q.peek() << '\n';

    std::cout << "draining: ";
    while (!q.empty()) {
        std::cout << q.dequeue() << ' ';
    }
    std::cout << '\n';

    // A second round to make sure the queue is reusable.
    for (int v = 10; v <= 14; ++v) {
        q.enqueue(v);
        if (v % 2 == 0) {
            std::cout << "dequeue -> " << q.dequeue() << '\n';
        }
    }
    std::cout << "remaining size: " << q.size() << '\n';
    std::cout << "draining: ";
    while (!q.empty()) {
        std::cout << q.dequeue() << ' ';
    }
    std::cout << '\n';
    return 0;
}
