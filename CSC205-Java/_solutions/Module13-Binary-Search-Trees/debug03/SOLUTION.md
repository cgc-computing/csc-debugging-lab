# Solution: Deleting from a Binary Search Tree

**Course/Module/Activity:** CSC205 · Module 13 Binary Search Trees · debug03
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

```
start:       in-order: 20 30 40 50 60 70 80   size 7
delete(20):  in-order: 30 40 50 60 70 80   size 6
delete(30):  in-order: 40 50 60 70 80   size 5
delete(50):  in-order: 40 60 60 70 80   size 4
delete(70):  in-order: 40 60 60 80 80   size 3
```

Leaf and one-child deletions are fine. Each two-child deletion removes the key but leaves a duplicate of the successor behind, so the listing has more keys than `size`.

## The Bug(s)

`BST.java`, private `delete(Node node, int key)`, the two-children case:

```java
Node successor = minNode(node.right);
node.key = successor.key;
// missing: remove the successor node from the right subtree
```

The successor's key is copied up, but the successor node itself is never unlinked.

## Why the Program Behaved Incorrectly

Before `delete(50)` the tree is `50(40, 70(60, 80))`. 50 has two children, so the code finds the minimum of the right subtree (60) and overwrites `node.key` with 60. The tree is now `60(40, 70(60, 80))`: two nodes hold 60. The public `delete` decrements `size` because `contains(50)` was true, so `size` says 4 while the tree has 5 nodes. `delete(70)` repeats the pattern with successor 80, giving `40 60 60 80 80` and `size 3`.

The tree is still ordered (in-order is non-decreasing), which is why nothing crashes — the damage is only visible by counting.

## The Concept This Illustrates

Two-child deletion is a *two-step* operation: (1) replace the node's key with the in-order successor's key, then (2) delete the successor from the right subtree. Step 2 is safe and simple because the successor is the leftmost node of the right subtree, so it has at most one child and its deletion falls into one of the two already-handled cases. Students frequently stop after step 1 because "the value is gone" — the deleted *key* has vanished, but the *node count* is unchanged and a duplicate key has appeared. It also shows why the recursive "return the new subtree root" shape (debug01) is so useful: removing the successor is just `node.right = delete(node.right, successor.key)`.

## The Correction

```java
// before
Node successor = minNode(node.right);
node.key = successor.key;
// after
Node successor = minNode(node.right);
node.key = successor.key;
node.right = delete(node.right, successor.key);
```

## Instructor Notes

- The `size` line is the tell: make students explain how a listing can have five keys when `size` is 4 before they open the file.
- Some students try `successor = null;` after the copy. Ask what that changes (nothing — it only clears a local variable). This is a good moment to revisit reference semantics.
- Others write `node.right = null;`, which deletes the whole right subtree. Run it: `delete(50)` would lose 70 and 80.
- Ask why the recursive call with `successor.key` is guaranteed to hit the leaf/one-child case and not recurse into the two-child case again (the successor has no left child by construction).
- Follow-up: implement the predecessor variant (max of the left subtree) and confirm both give valid, if differently shaped, trees.
