# Binary Search Tree Insert

**Course:** CSC205 &nbsp;|&nbsp; **Module 13:** Binary Search Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`BST` is a binary search tree of integers built with a recursive `insert` that returns the root of the subtree it worked on. The driver inserts seven values and prints the tree in order, its size, and its smallest and largest values.

## Expected Behavior

```
In order: 20 30 40 50 60 70 80 
Size: 7
Min: 20  Max: 80
```

(The in-order line ends with a trailing space; that is fine.)

## How to Run

```bash
g++ -std=c++17 -Wall -o bst_insert bst_insert.cpp
./bst_insert
```
(on Windows: `bst_insert.exe` or `.\bst_insert.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the recursive design; do not rewrite `insert` as a loop.

## Think About

- The private `insert` returns a `Node*`. Read its comment: what is that return value *for*? Look at every place `insert` is called and check what happens to the value each call returns.
- Draw the tree after inserting 50, then 30. A new node for 30 is definitely created — what points to it?
- Seven values were inserted but the size is 1. Where are the other six nodes, and will they ever be deleted?
