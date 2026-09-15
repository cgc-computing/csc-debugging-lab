# Max-Heap in a Python List

**Course:** CSC310 &nbsp;|&nbsp; **Module 2:** Heaps, Priority Queues, and Quicksort &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`max_heap.py` stores a binary max-heap in a 0-based Python list and implements the CLRS Chapter 6
procedures MAX-HEAPIFY, BUILD-MAX-HEAP and HEAP-INSERT. The `main` block builds a heap from the same
eleven keys in two ways (bottom-up, and by repeated insertion) and then extracts every element,
which should produce the keys in decreasing order both times.

## Expected Behavior

```
bottom-up build   : [16, 14, 10, 8, 11, 9, 3, 2, 4, 7, 1]
extract order     : [16, 14, 11, 10, 9, 8, 7, 4, 3, 2, 1]
descending order? : True

built by insertion: [16, 14, 10, 8, 11, 3, 9, 1, 4, 2, 7]
extract order     : [16, 14, 11, 10, 9, 8, 7, 4, 3, 2, 1]
descending order? : True
```

## How to Run

```bash
python3 max_heap.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the heap in a
plain list; do not switch to the `heapq` module.

## Think About

- Draw the list `[16, 14, 10, 8, 11, 9, 3, 2, 4, 7, 1]` as a binary tree. Which indices hold the
  children of index 0? Of index 1? Of index 4?
- CLRS gives PARENT, LEFT and RIGHT for an array whose first element is `A[1]`. Write the three
  formulas for an array whose first element is `A[0]` and check that PARENT undoes LEFT and RIGHT.
- Heap insertion walks *up* the tree and heapify walks *down*. If those two walks disagree about who
  is whose child, what would you expect to happen when you extract?
