# Solution: Building a Binary Search Tree

**Course/Module/Activity:** CSC205 · Module 13 Binary Search Trees · debug01
**Bug type(s):** logic, conceptual/design
**Bug count:** 2 (same misconception on the left and right branches)

## Observed Behavior

```
in-order: 50
size:     7
height:   0
```

The tree never grows past its root, although the size counter climbs to 7.

## The Bug(s)

`BST.java`, private `insert(Node node, int key)`:

```java
if (key < node.key) {
    insert(node.left, key);
} else if (key > node.key) {
    insert(node.right, key);
}
return node;
```

Both recursive calls discard the returned subtree instead of storing it back into `node.left` / `node.right`.

## Why the Program Behaved Incorrectly

The helper follows the "return the (possibly new) root of this subtree" pattern: when it reaches `null` it creates a node and returns it, and the caller is supposed to hang that node in the right place by assigning the result. The public method does this (`root = insert(root, key)`), so the first insert works. On the second insert, `insert(root.left, 30)` is called with `null`, creates `new Node(30)`, increments `size`, and returns it — to nobody. `root.left` is still `null`. Every subsequent insertion does the same: a node is allocated and immediately becomes garbage, while `size++` faithfully records it. Hence in-order shows only 50, `height` is 0, and `size` is 7.

## The Concept This Illustrates

Java passes references *by value*. Inside the helper, `node` is a copy of the caller's reference; assigning to `node` (or passing `node.left` to a call that assigns to *its* parameter) never changes the caller's field. That is exactly why the recursive insert returns the subtree root: the return value is the only channel back to the parent's `left`/`right` field. Students who write `insert(node.left, key);` are thinking of `node.left` as an out-parameter, which Java does not have.

## The Correction

```java
// before
if (key < node.key) {
    insert(node.left, key);
} else if (key > node.key) {
    insert(node.right, key);
}
// after
if (key < node.key) {
    node.left = insert(node.left, key);
} else if (key > node.key) {
    node.right = insert(node.right, key);
}
```

## Instructor Notes

- The size/in-order contradiction is the hook. Ask "which method is right?" before anyone opens `BST.java`; students must reason that `size` is incremented when a node is *created*, not when it is *attached*.
- Some students rewrite `insert` iteratively (walk down with a `parent` pointer). That is correct but violates the README's scope sentence; ask them to also fix the recursive version so they confront the return-value pattern.
- Others try `if (node.left == null) node.left = new Node(key); else insert(node.left, key);` — a hybrid that works but duplicates the null case. Ask what the `return node;` at the bottom is then for.
- Follow-up: "Why does `height` print 0 rather than -1?" (The root exists; only the children are missing.)
