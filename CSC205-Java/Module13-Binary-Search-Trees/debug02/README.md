# Student ID Set with a BST

**Course:** CSC205 &nbsp;|&nbsp; **Module 13:** Binary Search Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`BST` stores a *set* of student ID numbers: every key appears at most once, and inserting a key that is already present leaves the tree unchanged. `contains` answers membership questions. `Main` inserts nine values (two of them repeats), prints the tree, and runs six lookups.

## Expected Behavior

```
in-order: 20 30 40 50 60 70 80
size:     7
contains(40): true
contains(65): false
contains(80): true
contains(20): true
contains(50): true
contains(10): false
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The insert/contains structure is sound; look closely at how each method decides which way to go.

## Think About

- When the key being inserted or searched for is *equal* to the key at the current node, what should happen? Which direction does the code actually send it?
- Trace `contains(50)` by hand. 50 is the root. Why does the method still return false?
- How can `size` be 9 when the set is supposed to hold seven distinct IDs? What does the in-order listing show?
- Every `contains` query returns false, even for keys that are plainly in the tree. What single decision, made at every node, could cause *all* of them to fail?
