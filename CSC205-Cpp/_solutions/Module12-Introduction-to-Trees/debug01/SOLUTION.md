# Solution: Expression Tree Traversals

**Course/Module/Activity:** CSC205 · Module 12 Introduction to Trees · debug01
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

```
Pre-order:  * + 3 4 - 5 2 
In-order:   * + 3 4 - 5 2 
Post-order: 3 4 + 5 2 - * 
Value:      21
```

Pre-order and post-order are correct and the value is correct, but the line labeled "In-order" prints the pre-order sequence.

## The Bug(s)

`expression_tree.cpp`, function `inorder`:

```cpp
cout << node->token << " ";
inorder(node->left);
inorder(node->right);
```

The node is visited *before* the left subtree. That is pre-order. In-order must visit the left subtree, then the node, then the right subtree.

## Why the Program Behaved Incorrectly

A traversal's name describes *when* the current node is processed relative to the recursive calls on its children. The three functions in this file differ only in the position of the `cout` line. In `inorder`, the `cout` sits first, so the function's body is identical to `preorder` and it necessarily prints the same sequence: root `*`, then the whole left subtree, then the whole right subtree.

## The Concept This Illustrates

Pre-, in-, and post-order are the same recursive skeleton with the "visit" step moved: before both calls, between them, or after them. Students who can recite the definitions sometimes still place the visit line by habit at the top of the function. The expression tree makes the difference tangible: in-order reproduces infix notation (`3 + 4 * 5 - 2`, minus the parentheses that the tree structure made unnecessary), post-order gives postfix/RPN (the order an evaluator needs its operands), and pre-order gives prefix. The `evaluate` function is itself a post-order traversal — children first, then the operator — which is why it is correct even though the printing function is not.

## The Correction

```cpp
// before
cout << node->token << " ";
inorder(node->left);
inorder(node->right);

// after
inorder(node->left);
cout << node->token << " ";
inorder(node->right);
```

## Instructor Notes

- Ask students to point out which traversal `evaluate` performs, and why it *has* to be that one.
- A good discussion: in-order output `3 + 4 * 5 - 2` reads as 3 + 20 - 2 = 21 only by coincidence of these numbers? No — check: with normal precedence it is 3 + 20 - 2 = 21, the same as (3 + 4) * (5 - 2) = 21. Change the leaves (e.g. 1 + 2 times 5 - 2) to show that in-order without parentheses is ambiguous; then ask how a fully parenthesized in-order print would look (print `(` before recursing left and `)` after recursing right on interior nodes).
- Some students will change the *label* in `main` rather than the function. Ask what a user calling `inorder` expects.
- Follow-up: have them write `countLeaves` and identify which traversal order it "uses" (it does not matter — a good moment to discuss when order is irrelevant).
