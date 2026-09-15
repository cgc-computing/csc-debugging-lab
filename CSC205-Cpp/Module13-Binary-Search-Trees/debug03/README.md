# Binary Search Tree Remove

**Course:** CSC205 &nbsp;|&nbsp; **Module 13:** Binary Search Trees &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

`BST` supports `insert` and a recursive `remove` that handles the three classic cases: a leaf, a node with one child, and a node with two children (replaced by its in-order successor). The driver builds a tree of eight values and removes one node of each kind, printing the in-order contents and size after each step.

## Expected Behavior

```
start         : 20 30 40 50 60 65 70 80  (size 8)
remove 20     : 30 40 50 60 65 70 80  (size 7)
remove 80     : 30 40 50 60 65 70  (size 6)
remove 30     : 40 50 60 65 70  (size 5)
remove 50     : 40 60 65 70  (size 4)
```

## How to Run

```bash
g++ -std=c++17 -Wall -o bst_delete bst_delete.cpp
./bst_delete
```
(on Windows: `bst_delete.exe` or `.\bst_delete.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the successor-based approach for the two-children case.

## Think About

- Draw the tree before and after `remove 30` and again for `remove 50`. Which of the three cases does each removal fall into?
- When a node with two children is removed, its value is replaced by another value from the tree. Immediately after that copy, how many nodes hold that value? What still has to happen?
- Every removal should reduce the size by exactly one. Which step does not, and why does the in-order print for that step contain a repeated value?
