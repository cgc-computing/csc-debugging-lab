# Linked List Append

**Course:** CSC205 &nbsp;|&nbsp; **Module 7:** Lists &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`SinglyLinkedList` is a hand-built linked list of `int` values that keeps both a `head` and a `tail` reference so that `addLast` runs in constant time. `Main` appends several values, prepends one, and prints the list and its size after each stage.

## Expected Behavior

```
List: 10 -> 20 -> 30 -> 40
Size: 4
List: 5 -> 10 -> 20 -> 30 -> 40 -> 50
Size: 6
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `addLast` O(1); do not walk the list to find the end.

## Think About

- Draw the nodes and both references after each `addLast` call. Which node does `tail` point to after the third call?
- What must be true about `tail` before *and* after every `addLast` so that the next call works?
- Why does `size` disagree with what is printed? Which one is telling the truth about the nodes in memory?
