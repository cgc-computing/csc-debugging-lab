# Expression Tree Traversals

**Course:** CSC205 &nbsp;|&nbsp; **Module 12:** Introduction to Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program builds the binary expression tree for `(3 + 4) * (5 - 2)` by hand — operators in the interior nodes, numbers in the leaves — and prints the tree using pre-order, in-order, and post-order traversal. It then evaluates the tree.

```
        *
      /   \
     +     -
    / \   / \
   3   4 5   2
```

## Expected Behavior

```
Pre-order:  * + 3 4 - 5 2 
In-order:   3 + 4 * 5 - 2 
Post-order: 3 4 + 5 2 - * 
Value:      21
```

(Each traversal prints a trailing space; that is fine.)

## How to Run

```bash
g++ -std=c++17 -Wall -o expression_tree expression_tree.cpp
./expression_tree
```
(on Windows: `expression_tree.exe` or `.\expression_tree.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did.

## Think About

- Two of the three traversals print exactly the same sequence. Can that ever be correct for a tree with more than one node?
- For each traversal, when is the *node itself* printed relative to its left and right subtrees? Say it in words for all three, then compare with the code.
- Which traversal gives back the expression in the order a person would write it, and what information from the original `(3 + 4) * (5 - 2)` does it lose?
