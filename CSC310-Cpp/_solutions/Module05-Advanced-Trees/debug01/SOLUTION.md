# Solution: Left Rotation in a Binary Search Tree

**Course/Module/Activity:** CSC310 · Module 5 Advanced Trees · debug01
**Bug type(s):** logic (pointer update omitted)
**Bug count:** 1

## Observed Behavior

```
left-rotate at 20
inorder: 10 20 25
structure (root first, children indented):
20
  10
  25

left-rotate at 40
cannot rotate: 40 is not in the tree
```

After the first rotation the tree appears to have lost keys 30, 35, 40 and 45, and the second rotation cannot find 40.

## The Bug(s)

`tree_rotation.cpp`, `Tree::leftRotate`. The routine sets `y->parent = x->parent` but never makes `x`'s former parent (or the root pointer) refer to `y`:

```cpp
y->parent = x->parent;
y->left = x;
x->parent = y;
```

The downward link into the rotated subtree is missing.

## Why the Program Behaved Incorrectly

With x = 20 (the root) and y = 30, the code correctly moves y's left subtree (25) under x and makes x the left child of y. But `root_` still points at x = 20, whose right child is now 25. Traversals start from `root_`, so they see only 10, 20 and 25; node 30 (with 40, 35, 45 beneath it) is still allocated but unreachable from the root, so `find(40)` fails. The same omission would break a rotation at a non-root node: the old parent's child pointer would still refer to x.

## The Concept This Illustrates

A rotation is a *local restructuring* that must leave every incoming and outgoing pointer of the affected nodes consistent: the parent's child pointer, the two nodes' parent pointers, and the moved subtree's parent pointer. Students frequently update the pointers *inside* the rotated pair and forget the single pointer that comes *into* the pair from above. This is precisely the step CLRS spells out with the three-way `if x.p == T.nil / x == x.p.left / else` test, and it is why red-black and AVL implementations need parent pointers or return values from rotation.

## The Correction

```cpp
y->parent = x->parent;
if (x->parent == nullptr) {
    root_ = y;
} else if (x == x->parent->left) {
    x->parent->left = y;
} else {
    x->parent->right = y;
}
y->left = x;
x->parent = y;
```

## Instructor Notes

- Some students add only `root_ = y;` (unconditionally). That fixes the first rotation and then makes the second one, at 40, replace the whole tree with the subtree rooted at 45. Ask them to trace the second rotation with their fix.
- Others fix the parent's child pointer but forget the root case, or vice versa. Having two rotations in the driver (one at the root, one below it) is deliberate; make sure both outputs match.
- Follow-up: write `rightRotate` as the mirror image and check that a left rotation followed by a right rotation at the new root restores the original structure.
- The unreachable nodes in the buggy version are also a memory leak; the destructor only frees what it can reach from `root_`.
