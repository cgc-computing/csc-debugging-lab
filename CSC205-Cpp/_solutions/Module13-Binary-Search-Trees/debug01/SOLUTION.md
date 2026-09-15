# Solution: Binary Search Tree Insert

**Course/Module/Activity:** CSC205 · Module 13 Binary Search Trees · debug01
**Bug type(s):** logic, conceptual/design
**Bug count:** 1 (the same omission on both branches of the recursion)

## Observed Behavior

```
In order: 50 
Size: 1
Min: 50  Max: 50
```

Only the first value inserted is ever visible. The tree behaves as if it had a root and nothing else.

## The Bug(s)

`bst_insert.cpp`, private `BST::insert(Node*, int)`:

```cpp
if (value < node->data) {
    insert(node->left, value);
} else {
    insert(node->right, value);
}
return node;
```

The recursive calls return the (possibly new) subtree root, but that result is thrown away. `node->left` and `node->right` are never assigned.

## Why the Program Behaved Incorrectly

The public `insert` does the right thing: `root = insert(root, value)`. For the first value, `root` is `nullptr`, the private function returns a new node, and `root` is assigned. For the second value (30), the call `insert(root->left, 30)` receives `nullptr` *by value*, allocates a node, and returns it — but the caller ignores the return, so `root->left` is still `nullptr`. Every subsequent insert does the same: a node is allocated, returned, and leaked. The tree never grows past its root, so in-order, size, min, and max all report a single value. (The leaked nodes are never freed either; the destructor only walks from `root`.)

## The Concept This Illustrates

In the "insert returns the new subtree root" style, the pointer parameter is a *copy*; assigning to it inside the callee does not change the caller's field. The link between parent and child is created by the caller storing the returned pointer: `node->left = insert(node->left, value)`. Students who understand recursion but are still shaky on pass-by-value pointers often miss this — the code "calls insert on the left subtree" and looks complete. The alternative style, `void insert(Node*& node, int value)` with a reference parameter, avoids the assignment but has the same lesson underneath: *someone* has to write the new address into the parent.

## The Correction

```cpp
// before
if (value < node->data) {
    insert(node->left, value);
} else {
    insert(node->right, value);
}
// after
if (value < node->data) {
    node->left = insert(node->left, value);
} else {
    node->right = insert(node->right, value);
}
```

## Instructor Notes

- Ask students why the *public* `insert(int)` works and the private one does not, when both call the same function. The difference — `root = insert(root, v)` versus a bare call — is the whole lesson.
- A student may switch the parameter to `Node*&` instead. That is a valid fix; ask them to explain why it works without an assignment in the caller, and what the `return node;` is now for.
- Ask what `-fsanitize=address` would report if the program were built with `-fsanitize=address` and run with leak detection: six leaked `Node` allocations. On macOS leak detection is off by default, so do not promise a report.
- Follow-up: "What would happen if a duplicate of the root value were inserted?" (goes right, per the `else`). Discuss duplicate policy before Module 13 debug02.
