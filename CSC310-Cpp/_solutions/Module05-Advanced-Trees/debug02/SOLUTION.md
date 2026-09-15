# Solution: Binary Search Tree Deletion

**Course/Module/Activity:** CSC310 · Module 5 Advanced Trees · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
initial      (10 nodes): 20 30 35 40 45 50 60 65 70 80
remove 20    (9 nodes): 30 35 40 45 50 60 65 70 80
remove 30    (8 nodes): 35 40 45 50 60 65 70 80
remove 50    (8 nodes): 35 40 45 60 60 65 70 80
remove 70    (8 nodes): 35 40 45 60 60 65 80 80
```

The first two removals are right. Removing 50 leaves the node count at 8 and the in-order listing now contains 60 twice; removing 70 likewise leaves 8 nodes and duplicates 80.

## The Bug(s)

`bst_delete.cpp`, function `remove`, two-children case:

```cpp
node->key = minKey(node->right);
node->left = remove(node->left, node->key);
```

The successor key is taken from the right subtree, but the recursive removal of that successor is issued on the *left* subtree.

## Why the Program Behaved Incorrectly

Insert order builds 50 at the root with 30 (children 20, 40; 40 has 35 and 45) on the left and 70 (children 60 → 65, and 80) on the right.

- `remove(20)`: 20 is a leaf, so the leaf case runs and the count drops to 9.
- `remove(30)`: after 20 is gone, 30 has only a right child (40), so the one-child case runs and is correct. Count 8.
- `remove(50)`: 50 has two children. Its successor is 60, the minimum of the right subtree, and 60 is copied into the root. The recursive call then searches the *left* subtree {35, 40, 45} for 60, finds nothing, and returns that subtree unchanged. Nothing is deleted, so the tree still holds the original 60 node under 70 and now also has 60 at the root: count stays 8, and the traversal shows `60 60`.
- `remove(70)`: same story with successor 80, producing `80 80`.

The defect only surfaces on the two-children path, which is why the first two removals looked fine.

## The Concept This Illustrates

Deleting a node with two children is a two-step transformation: replace its key with the in-order successor, then remove the successor *from the subtree where it lives*—the right subtree, where it is the minimum and therefore has at most one child (which is what guarantees the second removal terminates in a simpler case). Students who think of step two as "now delete that key from the tree" without locating it correctly break the size invariant and introduce duplicate keys, which then corrupt later searches and deletions.

## The Correction

```cpp
} else {
    node->key = minKey(node->right);
    node->right = remove(node->right, node->key);
}
```

## Instructor Notes

- Ask students why `remove 30` came out right even though 30 originally had two children. (Because 20 had already been deleted, 30 was on the one-child path by then.) It is a good reminder that the order of operations in a test driver decides which code paths are exercised.
- A common wrong "fix" is to switch to the predecessor (`maxKey(node->left)`) but leave the recursive call on the right subtree; it fails symmetrically. Either successor-from-right or predecessor-from-left is fine as long as the recursive removal targets the same subtree the replacement key came from.
- Ask why the successor is guaranteed to have no left child, and what the running time of `remove` is in terms of the tree height.
- If a student adds a structural print, they will see the duplicate 60 sitting under 70 while another 60 is at the root—useful for making the invariant violation concrete.
