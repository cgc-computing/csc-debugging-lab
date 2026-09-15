# Solution: Measuring a Binary Tree

**Course/Module/Activity:** CSC205 · Module 12 Introduction to Trees · debug02
**Bug type(s):** logic, boundary
**Bug count:** 2 (related: both misuse the recursive results/base cases)

## Observed Behavior

```
nodes:  3
leaves: 3
height: 4
empty tree nodes:  0
empty tree height: -1
```

## The Bug(s)

`BinaryTree.java`:

1. `countNodes(Node n)`:
   ```java
   countNodes(n.left);
   return 1 + countNodes(n.right);
   ```
   The left subtree is traversed but its count is discarded.

2. `height(Node n)`: the explicit leaf case returns `1`, while the null case returns `-1`:
   ```java
   if (n == null) return -1;
   if (n.left == null && n.right == null) return 1;
   return 1 + Math.max(height(n.left), height(n.right));
   ```
   Under the edges convention a leaf has height 0. The two base cases disagree by one.

## Why the Program Behaved Incorrectly

`countNodes` from the root: the left call (subtree 2/4/5) runs and returns 3, but nothing keeps it. `1 + countNodes(3)`; inside, `countNodes(null)` is dropped and `1 + countNodes(6)`; inside, `countNodes(7)` is dropped and `1 + countNodes(null) = 1`. Total `1 + (1 + 1) = 3` — only the nodes along the rightmost path are counted.

`height`: leaf 7 returns 1 instead of 0; node 6 returns `1 + max(1, -1) = 2` instead of 1; node 3 returns 3; the left subtree returns `1 + max(1, 1) = 2`; the root returns `1 + max(2, 3) = 4`. Every path is measured one too long because the leaf case reports a node count where an edge count was wanted. The empty tree prints -1 correctly because that base case is fine on its own.

## The Concept This Illustrates

Two habits of recursive tree code:

- **A recursive call that computes a value must have its result used.** Calling `countNodes(n.left)` as a statement is not "counting the left subtree"; it is doing the work and throwing the answer away. Students who have just come from void traversals (debug01) often carry that pattern into value-returning methods.
- **Base cases must agree with the recurrence.** `1 + max(...)` adds one edge per level, so the base cases must be one apart: null is -1, leaf is 0 — and in fact the leaf case is redundant, since `1 + max(-1, -1) = 0` already. Adding a special leaf case "for safety" and getting its value wrong is a very common way to introduce an off-by-one.

## The Correction

```java
// countNodes, before
countNodes(n.left);
return 1 + countNodes(n.right);
// after
return 1 + countNodes(n.left) + countNodes(n.right);

// height, before
if (n == null) return -1;
if (n.left == null && n.right == null) return 1;
return 1 + Math.max(height(n.left), height(n.right));
// after (leaf case removed; the general case yields 0 for a leaf)
if (n == null) return -1;
return 1 + Math.max(height(n.left), height(n.right));
```

Changing the leaf case to `return 0;` instead of deleting it is equally correct.

## Instructor Notes

- Have students trace `countNodes` on the subtree rooted at 3 before fixing: the answer 2 for a three-node subtree isolates the bug quickly.
- For `height`, some students will change the null case to `0` and leave the leaf case at `1`, switching to the "count nodes on the path" convention. Under that convention the sample tree has height 4 and the empty tree 0 — which contradicts the README's stated definition and its expected output. Use this to discuss that both conventions exist and the definition must be pinned down before coding.
- Ask why `countLeaves` gets away with a leaf case: there, the leaf case is the *only* way to produce a 1; the recurrence adds nothing itself.
- Follow-up: write `countInternal` and check that `countInternal + countLeaves == countNodes`.
