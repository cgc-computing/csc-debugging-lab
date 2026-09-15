# AVL Tree Insert and Delete

**Course:** CSC310 &nbsp;|&nbsp; **Module 5:** Advanced Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`avl_tree.py` implements an AVL tree: a binary search tree in which every node stores the height of
its subtree and the heights of any node's two subtrees differ by at most one. Insert and delete
recompute heights on the way back up and rebalance with single or double rotations. The `main` block
inserts the keys 1 through 15 in ascending order, then deletes five keys, and after each phase
reports the root, the height stored in the root, the height measured by walking the tree, and whether
the tree satisfies the AVL balance condition.

## Expected Behavior

```
after inserting 1..15
  inorder        : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
  root           : 8
  stored height  : 3
  measured height: 3
  balanced       : True
after deleting 1, 2, 3, 4, 8
  inorder        : [5, 6, 7, 9, 10, 11, 12, 13, 14, 15]
  root           : 9
  stored height  : 3
  measured height: 3
  balanced       : True
```

Fifteen keys inserted in order should produce the perfect tree of height 3 rooted at 8.

## How to Run

```bash
python3 avl_tree.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite
the program; the recursive structure and the rotation cases are fine.

## Think About

- The stored height and the measured height disagree. Which nodes' `height` fields could be stale,
  and which operations write to them?
- Inside a rotation, one node becomes the child of the other. Whose height depends on whose? In what
  order must the two heights be recomputed so that neither uses a stale value?
- `rebalance` decides whether to rotate by reading stored heights. If a stored height is too large,
  can the tree rotate when it should not, or fail to rotate when it should? Which of those would make
  the tree taller than it needs to be?
- Why does the tree look healthy again after the deletions even though nothing was fixed?
