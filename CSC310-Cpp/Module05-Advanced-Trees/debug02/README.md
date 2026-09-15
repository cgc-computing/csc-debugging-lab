# Binary Search Tree Deletion

**Course:** CSC310 &nbsp;|&nbsp; **Module 5:** Advanced Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program builds a binary search tree and then removes keys with a recursive `remove` that handles the leaf, one-child, and two-children cases. After each removal it prints the node count and the in-order traversal, which must remain a strictly increasing sequence of the keys still present.

## Expected Behavior

```
initial      (10 nodes): 20 30 35 40 45 50 60 65 70 80
remove 20    (9 nodes): 30 35 40 45 50 60 65 70 80
remove 30    (8 nodes): 35 40 45 50 60 65 70 80
remove 50    (7 nodes): 35 40 45 60 65 70 80
remove 70    (6 nodes): 35 40 45 60 65 80
```

## How to Run

```bash
g++ -std=c++17 -Wall -o bst_delete bst_delete.cpp
./bst_delete
```

(on Windows: `bst_delete.exe` or `.\bst_delete.exe`)

## Your Task

Run the program, compare its output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the successor-based approach to the two-children case.

## Think About

- Draw the tree after the inserts. When 30 is removed, which node is its in-order successor, and in which subtree of 30 does that node live?
- After the successor's key is copied into the node being removed, the tree briefly contains that key twice. Which copy must be deleted, and where should the recursive call look for it?
- Removing 20 works correctly. What is different about removing 30, 50, and 70?
