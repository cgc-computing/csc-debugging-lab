# Deleting from a Binary Search Tree

**Course:** CSC205 &nbsp;|&nbsp; **Module 13:** Binary Search Trees &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

`BST` supports `insert`, `contains`, and `delete`. Deletion handles the three classic cases: a leaf, a node with one child, and a node with two children — the last by replacing the node's key with its in-order successor (the smallest key in its right subtree). `Main` builds a seven-key tree and deletes one node of each kind, then one more.

## Expected Behavior

```
start:       in-order: 20 30 40 50 60 70 80   size 7
delete(20):  in-order: 30 40 50 60 70 80   size 6
delete(30):  in-order: 40 50 60 70 80   size 5
delete(50):  in-order: 40 60 70 80   size 4
delete(70):  in-order: 40 60 80   size 3
```

After every deletion the in-order listing contains exactly `size` distinct keys and the deleted key is gone.

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `insert`, `contains`, and the size bookkeeping are correct.

## Think About

- Which of the four deletions leave the listing disagreeing with `size`? What do those deleted nodes have in common that the others do not?
- Draw the tree just before `delete(50)`. After the successor's key is copied into the node that held 50, how many nodes hold the value 60? How many should?
- The successor of a node with two children never has a left child. Why is that guaranteed, and why does it make the successor easy to remove?
- After the copy step, what still needs to happen in the right subtree for the tree to be a valid BST with the correct number of nodes?
