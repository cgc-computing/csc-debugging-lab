# Solution: Member ID Lookup

**Course/Module/Activity:** CSC205 · Module 13 Binary Search Trees · debug02
**Bug type(s):** logic, boundary
**Bug count:** 1

## Observed Behavior

```
Members (7): 1200 2500 3300 5000 6100 7500 9000 
ID 5000: not a member
ID 3300: not a member
ID 9000: not a member
ID 1200: not a member
ID 4000: not a member
ID 8000: not a member
```

The tree is built correctly, but every lookup — including the root's own key — reports "not a member."

## The Bug(s)

`bst_contains.cpp`, private `MemberTree::contains`:

```cpp
if (key <= node->key) {
    return contains(node->left, key);
} else if (key > node->key) {
    return contains(node->right, key);
} else {
    return true;
}
```

The first test uses `<=`, so an *equal* key is sent down the left subtree instead of being recognized. The `else` branch that returns true can never run.

## Why the Program Behaved Incorrectly

`<=` and `>` together cover every possible relationship between `key` and `node->key`; there is no value left for the final `else`. When the search reaches the node that actually holds the key, `key <= node->key` is true and the search moves left. By the BST ordering, everything in the left subtree is strictly smaller (this `insert` ignores duplicates), so the key is never seen again and the search runs off the bottom of the tree to a `nullptr`, returning false. The `insert` function uses `<` and `>` with a fall-through for equality, which is why the tree itself is correct.

## The Concept This Illustrates

A BST search has three outcomes at each node — go left, go right, or stop because you have found it — and the comparisons must partition the possibilities into exactly those three cases. Using `<=` where `<` is needed collapses "equal" into "smaller," which silently deletes the success case. This also connects to duplicate policy: the class's `insert` chose "ignore duplicates," so equal keys are never to the left or the right; `contains` must agree with that decision. The output is a strong hint: since the in-order print is right, `insert` is right, and the fault must be in how `contains` compares.

## The Correction

```cpp
// before
if (key <= node->key) {
// after
if (key < node->key) {
```

## Instructor Notes

- Ask students to explain, in one sentence, why the `else` was unreachable. Then ask whether the compiler could have warned them (with `-Wall` it does not; some static analyzers would).
- A student may instead put an explicit `if (key == node->key) return true;` first. That is fine and arguably clearer; make sure they can also say why the original order failed.
- Ask what would change if `insert` stored duplicates to the *right* (`>=`). Would `contains` need to change? (No — but a `count(key)` function would need to keep descending after a match.)
- Follow-up: have them add a `remove` stub and predict which comparison operators it needs — a lead-in to debug03.
