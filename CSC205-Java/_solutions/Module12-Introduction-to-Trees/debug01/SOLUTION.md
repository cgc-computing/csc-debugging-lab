# Solution: Binary Tree Traversals

**Course/Module/Activity:** CSC205 · Module 12 Introduction to Trees · debug01
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

```
pre-order:  4 2 1 3 6 5 7
in-order:   4 2 1 3 6 5 7
post-order: 1 3 2 5 7 6 4
```

The in-order line is identical to the pre-order line.

## The Bug(s)

`BinaryTree.java`, private `inOrder(Node n, StringBuilder sb)`: the node's value is appended *before* the recursive call on the left subtree:

```java
sb.append(n.value).append(' ');
inOrder(n.left, sb);
inOrder(n.right, sb);
```

That is a pre-order traversal with an in-order name.

## Why the Program Behaved Incorrectly

The order of the three statements in the recursive helper *is* the traversal. With "visit, left, right" the root 4 is printed immediately, then the entire left subtree in the same visit-first fashion (2, 1, 3), then the right (6, 5, 7). The correct in-order helper must finish the whole left subtree before appending the node, which is what makes the leftmost leaf (1) print first and the root print exactly in the middle.

## The Concept This Illustrates

Pre-, in-, and post-order differ *only* in where the "visit" step sits among the two recursive calls. Students often understand the definitions when reading a picture but do not connect them to statement order in code, or they copy-paste `preOrder` to make `inOrder` and move the wrong line. The tree here is deliberately laid out so a correct in-order traversal prints 1 through 7 in sequence, making the mistake obvious and the corrected output self-checking.

## The Correction

```java
// before
sb.append(n.value).append(' ');
inOrder(n.left, sb);
inOrder(n.right, sb);
// after
inOrder(n.left, sb);
sb.append(n.value).append(' ');
inOrder(n.right, sb);
```

## Instructor Notes

- Ask students to say the three orders aloud as "root-left-right / left-root-right / left-right-root" and then point at the line in each helper that is the "root" step.
- Some students will move the append to *after* both calls, producing a second copy of post-order. Have them compare with the post-order line.
- Follow-up: "If this tree were a binary search tree, which traversal would print the keys sorted, and why?" bridges to Module 13.
- Follow-up: "Which traversal would you use to delete every node safely? To copy the tree?" (post-order; pre-order.)
