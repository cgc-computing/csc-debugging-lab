# Building a Binary Search Tree

**Course:** CSC205 &nbsp;|&nbsp; **Module 13:** Binary Search Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`BST` is a binary search tree of `int` keys with a recursive `insert`, plus `size`, `height` (in edges), and an in-order listing. `Main` inserts seven keys and prints the resulting tree.

## Expected Behavior

```
in-order: 20 30 40 50 60 70 80
size:     7
height:   2
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `insert` recursive.

## Think About

- `size` reports 7 while the in-order listing shows one key. How can both be true at the same time? Which one is lying about the tree, and which one is telling the truth?
- The recursive `insert` helper *returns* a `Node`. What is that return value for? Look at how the public `insert` uses it, then look at how the helper itself uses it.
- Draw what the tree looks like after inserting 50 and then 30. Where did the node holding 30 go?
- Why does the very first insertion work correctly?
