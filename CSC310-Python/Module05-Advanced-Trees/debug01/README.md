# Rotations in a BST With Parent Pointers

**Course:** CSC310 &nbsp;|&nbsp; **Module 5:** Advanced Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`bst_rotations.py` implements a binary search tree whose nodes carry `parent` pointers, together with
LEFT-ROTATE and RIGHT-ROTATE from CLRS Section 13.2. The `main` block inserts the keys 1 through 7 in
order (producing a chain of height 6) and then applies five rotations that should reshape the chain
into a perfectly balanced tree rooted at 4. After every rotation it prints the root and an in-order
traversal; at the end it verifies that every child's `parent` pointer points back at its parent.

## Expected Behavior

```
chain     : [1, 2, 3, 4, 5, 6, 7] height 6
after L-rotate at 1: root 2, inorder [1, 2, 3, 4, 5, 6, 7]
after L-rotate at 2: root 3, inorder [1, 2, 3, 4, 5, 6, 7]
after L-rotate at 3: root 4, inorder [1, 2, 3, 4, 5, 6, 7]
after R-rotate at 3: root 4, inorder [1, 2, 3, 4, 5, 6, 7]
after L-rotate at 5: root 4, inorder [1, 2, 3, 4, 5, 6, 7]

final root      : 4
final height    : 2
parent links ok : True
```

A rotation never changes the set of keys or their in-order sequence, so every `inorder` line must
list all seven keys.

## How to Run

```bash
python3 bst_rotations.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
parent-pointer design; do not rewrite the rotations recursively.

## Think About

- Draw the tree just before the last rotation and label every pointer that a left rotation at node 5
  must change. How many pointers is that, and how many does each of the two rotation methods
  actually assign?
- The first three rotations are all performed at the root. What is different about a rotation
  performed at a node that has a parent?
- The two rotation methods are mirror images of each other. Compare them line by line: does every
  statement in one have a counterpart in the other?
- Keys 6 and 7 are still in memory after the last rotation. Why can the traversal no longer reach
  them, and what does `parent_links_ok` reveal about node 5?
