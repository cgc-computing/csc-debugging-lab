# Measuring a Binary Tree

**Course:** CSC205 &nbsp;|&nbsp; **Module 12:** Introduction to Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`BinaryTree` builds a seven-node tree by hand and computes three recursive measurements: the number of nodes, the number of leaves, and the height. Height is measured in **edges** along the longest root-to-leaf path: a single node has height 0 and an empty tree has height -1.

```
           1
         /   \
        2     3
       / \     \
      4   5     6
               /
              7
```

## Expected Behavior

```
nodes:  7
leaves: 3
height: 3
empty tree nodes:  0
empty tree height: -1
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `countLeaves` is correct and can serve as a reference for how the other two methods should be shaped.

## Think About

- For `countNodes`: each recursive call returns a number. What happens to that number in each place the method is called?
- Trace `countNodes` on the subtree rooted at 3. What should it return, and what does it return?
- For `height`: what should a leaf return under the "edges" definition? What does an empty subtree return? Are the two answers one apart, as the recursive formula needs them to be?
- Is a separate leaf case even necessary in `height`, or does the general case already produce the right answer for a leaf?
