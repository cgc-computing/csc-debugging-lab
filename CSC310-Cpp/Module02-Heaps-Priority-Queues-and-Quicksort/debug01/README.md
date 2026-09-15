# Max-Priority Queue on a Binary Heap

**Course:** CSC310 &nbsp;|&nbsp; **Module 2:** Heaps, Priority Queues, and Quicksort &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`MaxHeapPQ` is a max-priority queue stored as a binary heap in a 0-based `std::vector<int>`. `insert` floats a new key toward the root, `maximum` returns the root, and `extractMax` removes the root and restores the heap property with MAX-HEAPIFY. Extracting repeatedly must return the keys in strictly decreasing order.

## Expected Behavior

```
insert 5  (max is now 5)
insert 12  (max is now 12)
insert 8  (max is now 12)
insert 20  (max is now 20)
insert 15  (max is now 20)
insert 27  (max is now 27)
insert 31  (max is now 31)
insert 3  (max is now 31)
insert 24  (max is now 31)
extract order: 31 27 24 20 15 12 8 5 3
```

## How to Run

```bash
g++ -std=c++17 -Wall -o max_heap_pq max_heap_pq.cpp
./max_heap_pq
```

(on Windows: `max_heap_pq.exe` or `.\max_heap_pq.exe`)

## Your Task

Run the program, compare the output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the array-based heap design.

## Think About

- In a 0-based array, which indices hold the children of the node at index 0? Of the node at index 1? Of the node at index 2?
- The heap is correct after all nine inserts (the maximum is always right). What is different about the work `extractMax` does compared with `insert`?
- Draw the array after the first `extractMax` moves the last key to the root. Which two indices must MAX-HEAPIFY compare it with, and which does it actually look at?
