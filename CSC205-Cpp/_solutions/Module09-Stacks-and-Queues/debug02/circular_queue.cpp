// circular_queue.cpp
// A queue of print jobs stored in a fixed-size circular array. The driver
// fills the queue, prints a couple of jobs, adds more, and drains it.

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* items;
    int capacity;
    int front;      // index of the oldest item
    int rear;       // index where the next item will be stored
    int count;      // number of items currently in the queue

public:
    CircularQueue(int cap) : capacity(cap), front(0), rear(0), count(0) {
        items = new int[capacity];
    }

    ~CircularQueue() { delete[] items; }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    // Adds value at the rear. Returns false if the queue is full.
    bool enqueue(int value) {
        if (isFull()) {
            return false;
        }
        items[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }

    // Removes the oldest item into value. Returns false if the queue is empty.
    bool dequeue(int& value) {
        if (isEmpty()) {
            return false;
        }
        value = items[front];
        front = (front + 1) % capacity;
        count--;
        return true;
    }
};

void addJob(CircularQueue& q, int id) {
    cout << "add job " << id << ": " << (q.enqueue(id) ? "queued" : "rejected (full)") << endl;
}

void printJobs(CircularQueue& q, int howMany) {
    for (int i = 0; i < howMany; i++) {
        int job;
        if (q.dequeue(job)) {
            cout << "  printed job " << job << endl;
        } else {
            cout << "  nothing to print" << endl;
        }
    }
}

int main() {
    CircularQueue jobs(5);
    for (int id = 101; id <= 105; id++) {
        addJob(jobs, id);
    }
    cout << "size: " << jobs.size() << endl;

    cout << "Printing two jobs:" << endl;
    printJobs(jobs, 2);

    addJob(jobs, 106);
    addJob(jobs, 107);
    cout << "size: " << jobs.size() << endl;

    cout << "Printing everything:" << endl;
    printJobs(jobs, 6);
    return 0;
}
