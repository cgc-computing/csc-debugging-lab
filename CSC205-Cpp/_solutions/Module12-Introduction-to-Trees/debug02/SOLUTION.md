# Solution: Binary Tree Statistics

**Course/Module/Activity:** CSC205 · Module 12 Introduction to Trees · debug02
**Bug type(s):** logic, boundary
**Bug count:** 2 (related: both are recursive tree functions whose result is assembled incorrectly — one drops a recursive result, one has the wrong base case)

## Observed Behavior

```
Main tree:   nodes=4 leaves=4 height=4
Single node: nodes=1 leaves=1 height=1
Empty tree:  nodes=0 leaves=0 height=0
```

The leaf counts are right. The node count is far too small (4 instead of 9), and every height is exactly one more than it should be.

## The Bug(s)

`tree_stats.cpp`:

1. `countNodes`:
   ```cpp
   countNodes(node->left);
   return 1 + countNodes(node->right);
   ```
   The left subtree is traversed but its count is discarded.

2. `height`:
   ```cpp
   if (node == nullptr) {
       return 0;
   }
   return 1 + max(height(node->left), height(node->right));
   ```
   With the empty tree defined as 0, a single node gets height 1. The README defines height in edges (leaf = 0, empty = -1).

## Why the Program Behaved Incorrectly

`countNodes` only accumulates along the chain of right children: 1 → 3 → 6 → 9 gives 4. Nodes 2, 4, 5, 7, 8 are visited (the call happens) but their counts vanish because the return value is not added to anything.

`height` is internally consistent but measures the wrong quantity: it counts *nodes* on the longest root-to-leaf path rather than *edges*. The main tree's longest path 1-2-4-7 has 4 nodes and 3 edges. Every answer is therefore off by exactly one, including the empty tree (0 instead of -1).

## The Concept This Illustrates

Recursive functions on trees follow one pattern: solve the problem for each subtree, then *combine* those results with information about the current node. Two things can go wrong with that pattern, and this activity has one of each. First, a recursive call whose return value is ignored contributes nothing — the recursion "happens" but the answer is lost; `countLeaves`, written correctly in the same file, shows the sum of both results. Second, the base case sets the units for the whole recursion: returning 0 for an empty tree makes `1 + ...` count nodes, returning -1 makes it count edges. The "leaf is 1 vs. leaf is 0" confusion is common because textbooks differ; what matters is that the base case matches the stated definition.

## The Correction

```cpp
// countNodes, before
countNodes(node->left);
return 1 + countNodes(node->right);
// after
return 1 + countNodes(node->left) + countNodes(node->right);
```

```cpp
// height, before
if (node == nullptr) {
    return 0;
}
// after
if (node == nullptr) {
    return -1;
}
```

## Instructor Notes

- Students often fix `height` by special-casing leaves: `if (leaf) return 0;` while keeping `nullptr → 0`. Ask them what a node with exactly one child returns (it comes out as 1 either way here, so the main tree passes) and then what the empty tree returns (still 0, not -1). The base-case fix is cleaner and handles all three lines.
- For `countNodes`, some students write `int left = countNodes(node->left); return 1 + countNodes(node->right);` — still dropping `left`. Compilers do not warn about an unused *call* result here; this is a good moment to note that the compiler cannot tell you your recursion is incomplete.
- Ask why `countLeaves` was right: it combines both results explicitly. Have them rewrite `countNodes` in the same shape.
- Follow-up: "What is the relationship between height and the maximum number of nodes a binary tree can hold?" — leads into the BST efficiency discussion in Module 13.
