# Solution: Student ID Set with a BST

**Course/Module/Activity:** CSC205 · Module 13 Binary Search Trees · debug02
**Bug type(s):** logic, boundary
**Bug count:** 2 (related: equal keys routed the wrong way in both `insert` and `contains`)

## Observed Behavior

```
in-order: 20 30 30 40 50 60 70 70 80
size:     9
contains(40): false
contains(65): false
contains(80): false
contains(20): false
contains(50): false
contains(10): false
```

Duplicates are stored, and no lookup ever succeeds.

## The Bug(s)

`BST.java`:

1. `insert(Node node, int key)`: `if (key <= node.key) go left; else go right;` — an equal key is treated as "smaller" and inserted into the left subtree, so duplicates are stored and `size` over-counts. Under the stated set policy an equal key must be ignored.

2. `contains(Node node, int key)`:
   ```java
   if (key <= node.key) {
       return contains(node.left, key);
   } else if (key > node.key) {
       return contains(node.right, key);
   }
   return true;
   ```
   An equal key satisfies `key <= node.key` and is sent left; the `return true` is unreachable. Since every branch eventually hits `null`, `contains` always returns false.

## Why the Program Behaved Incorrectly

`contains(50)`: 50 is the root. `50 <= 50` is true, so search continues in the left subtree (30, 20, 40 …), which cannot contain 50 by the BST property, and bottoms out at `null` → false. The same happens for every present key: the moment the search *reaches* the key, it steps past it to the left. Absent keys (65, 10) return false for the right reason.

`insert(30)` the second time: `30 <= 50` → left; `30 <= 30` → left again; `30 > 20` → right of 20 → `null`, so a second 30 is created there. In-order now shows `20 30 30`. Same for the repeat 70. Size becomes 9.

## The Concept This Illustrates

A BST has three outcomes at every node — less, greater, *equal* — and the equal case must be decided explicitly. Writing `<=` collapses "equal" into "less" and quietly determines the duplicate policy (duplicates go left) while making a search for an existing key impossible to succeed. Whatever policy the class promises (here: a set, duplicates ignored), `insert` and `contains` must implement the *same* three-way decision, and the equal case must be tested before or instead of the inequality that would swallow it.

## The Correction

```java
// insert, before
if (key <= node.key) {
    node.left = insert(node.left, key);
} else {
    node.right = insert(node.right, key);
}
// after
if (key < node.key) {
    node.left = insert(node.left, key);
} else if (key > node.key) {
    node.right = insert(node.right, key);
}

// contains, before
if (key <= node.key) {
    return contains(node.left, key);
// after
if (key < node.key) {
    return contains(node.left, key);
```

## Instructor Notes

- Start with "trace `contains(50)`" — the root — so students see the search walk *away* from a key it is standing on.
- Some students fix `contains` only. The lookups pass, but size 9 and the doubled 30 and 70 remain; the README's expected output catches it.
- Some fix `insert` by adding `else if (key == node.key) return node;` *after* the `<=` branch. It is unreachable; ask them why.
- Discuss the alternative policy: a BST that *allows* duplicates (multiset) consistently sends equal keys right (or left) and `contains` checks equality first. The bug is not `<=` per se; it is that the equal case was never consciously decided. Ask which methods would need to agree if duplicates were allowed (insert, contains, delete, count).
