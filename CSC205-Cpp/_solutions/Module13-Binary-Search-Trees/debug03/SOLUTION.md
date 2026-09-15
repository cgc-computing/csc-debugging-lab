# Solution: Binary Search Tree Remove

**Course/Module/Activity:** CSC205 · Module 13 Binary Search Trees · debug03
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

```
start         : 20 30 40 50 60 65 70 80  (size 8)
remove 20     : 30 40 50 60 65 70 80  (size 7)
remove 80     : 30 40 50 60 65 70  (size 6)
remove 30     : 40 50 60 65 70  (size 5)
remove 50     : 40 60 60 65 70  (size 5)
```

The leaf and one-child removals work, and so does `remove 30` (which also has two children). But `remove 50` leaves the size unchanged and the value 60 appears twice.

## The Bug(s)

`bst_delete.cpp`, private `BST::remove`, two-children case:

```cpp
// Two children: replace this value with its in-order successor.
node->data = minValue(node->right);
```

The successor's value is copied up into the node, but the successor node itself is never removed from the right subtree.

## Why the Program Behaved Incorrectly

Removing 50 (the root, with children 40 and 70): the smallest value in the right subtree is 60, so `node->data` becomes 60. The tree now contains 60 in two places — the root and the original successor node under 70. Nothing is deleted, so the size stays 5 and the in-order print shows `60 60`.

`remove 30` looks correct only by luck: 30's right subtree is the single node 40, so `minValue` returns 40 and the root copy would also duplicate 40 — except that 30 has children 20... no: by the time 30 is removed, 20 is already gone, so 30 has *one* child (40) and takes the one-child path, which is correct. The bug is only exercised by a node that still has two children at removal time, which is why the README's sequence removes 50 last.

## The Concept This Illustrates

Deleting a node with two children is a *two-step* operation: copy the in-order successor's value into the node, then delete the successor from the right subtree (where it is guaranteed to have at most one child, so the simpler cases apply). Students frequently stop after the first step because the tree "has the right value in the right place." The second step is what actually removes a node; it is also why the recursive `remove` is naturally written to call itself on `node->right` with the successor's value. Forgetting it violates both the size invariant and the no-duplicates invariant of this tree.

## The Correction

```cpp
// before
node->data = minValue(node->right);

// after
node->data = minValue(node->right);
node->right = remove(node->right, node->data);
```

## Instructor Notes

- Students who add the recursive call but write `remove(node->right, node->data);` without assigning back to `node->right` will see the successor survive when it is a leaf child of `node` itself (e.g., removing 70 in a tree where 80 is its only right child). Ask them to trace where the returned pointer goes — it echoes Module 13 debug01.
- Some will fix it by removing the *predecessor* (max of the left subtree) instead. That is equally valid; make sure the implementation is symmetric and complete.
- The note about `remove 30` is worth walking through: ask students to predict which case each removal hits *before* running, then check. Changing the order in `main` (remove 30 before 20) makes 30 a two-children removal and exposes the bug earlier — a good exercise in choosing test cases.
- Follow-up: what happens if `remove` is called with a value not in the tree? (Falls off to `nullptr`, returns `nullptr`, parent link unchanged — correct.)
