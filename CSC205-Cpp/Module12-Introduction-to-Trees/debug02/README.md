# Binary Tree Statistics

**Course:** CSC205 &nbsp;|&nbsp; **Module 12:** Introduction to Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program builds a small binary tree of integers by hand and reports three statistics for it: the number of nodes, the number of leaves, and the height. Height is measured in **edges**: a tree consisting of a single node has height 0, and the empty tree has height -1. It runs the same functions on a one-node tree and on an empty tree as sanity checks.

```
            1
          /   \
         2     3
        / \     \
       4   5     6
      /         / \
     7         8   9
```

## Expected Behavior

```
Main tree:   nodes=9 leaves=4 height=3
Single node: nodes=1 leaves=1 height=0
Empty tree:  nodes=0 leaves=0 height=-1
```

## How to Run

```bash
g++ -std=c++17 -Wall -o tree_stats tree_stats.cpp
./tree_stats
```
(on Windows: `tree_stats.exe` or `.\tree_stats.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `countLeaves` is correct; use it as a model.

## Think About

- Compare the reported node count with the drawing. Which nodes were not counted? What do they have in common about where they sit in the tree?
- When a recursive function calls itself, what happens to the value that call returns if nobody stores or uses it?
- Using the README's definition, what height should a single leaf have? What must the base case (an empty subtree) return so that a leaf's `1 + max(...)` comes out right?
