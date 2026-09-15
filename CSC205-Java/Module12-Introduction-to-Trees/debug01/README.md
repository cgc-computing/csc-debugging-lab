# Binary Tree Traversals

**Course:** CSC205 &nbsp;|&nbsp; **Module 12:** Introduction to Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`BinaryTree` builds a seven-node tree by hand and offers the three depth-first traversals: pre-order, in-order, and post-order. `Main` prints the tree in each order.

```
          4
        /   \
       2     6
      / \   / \
     1   3 5   7
```

## Expected Behavior

```
pre-order:  4 2 1 3 6 5 7
in-order:   1 2 3 4 5 6 7
post-order: 1 3 2 5 7 6 4
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The tree itself is built correctly.

## Think About

- For each traversal, *when* is a node's own value handled relative to its left and right subtrees? Say it in words for all three before you look at the code.
- Two of the three lines of output are identical. What does that tell you about how those two methods are written?
- In an in-order traversal of this tree, which node is printed first, and what has to happen before the root can be printed?
- Trace the in-order traversal by hand, starting at 4, and write down the sequence of method calls and prints.
