# Left Rotation in a Binary Search Tree

**Course:** CSC310 &nbsp;|&nbsp; **Module 5:** Advanced Trees &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`Tree` is a binary search tree whose nodes carry parent pointers, together with the LEFT-ROTATE operation from CLRS chapter 13. A rotation changes the local shape of the tree around one node without changing the set of keys or their in-order sequence. The driver builds a tree, performs a left rotation at the root and then at another node, and prints the in-order sequence and the structure after each one.

## Expected Behavior

Every in-order listing must show all seven keys in the same order, and after each rotation the printed structure must show the rotated node's former right child sitting where the rotated node used to be.

```
before rotation
inorder: 10 20 25 30 35 40 45
structure (root first, children indented):
20
  10
  30
    25
    40
      35
      45

left-rotate at 20
inorder: 10 20 25 30 35 40 45
structure (root first, children indented):
30
  20
    10
    25
  40
    35
    45

left-rotate at 40
inorder: 10 20 25 30 35 40 45
structure (root first, children indented):
30
  20
    10
    25
  45
    40
      35
```

## How to Run

```bash
g++ -std=c++17 -Wall -o tree_rotation tree_rotation.cpp
./tree_rotation
```

(on Windows: `tree_rotation.exe` or `.\tree_rotation.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the parent-pointer design; the rest of the class is fine.

## Think About

- A rotation rewires several pointers. List every pointer that refers to the two nodes involved before the rotation, and decide what each should refer to afterwards.
- After the first rotation, which node should the tree's root pointer refer to? What does the program's output tell you about that?
- Why does the second rotation report that 40 is not in the tree, even though no key was ever removed?
