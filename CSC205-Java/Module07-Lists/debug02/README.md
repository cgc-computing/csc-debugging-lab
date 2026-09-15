# Linked List Insert at Index

**Course:** CSC205 &nbsp;|&nbsp; **Module 7:** Lists &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`insertAt(index, value)` inserts `value` into a hand-built singly linked list so that afterwards `value` occupies position `index` (0 is the front; `size` means append at the end). Existing elements keep their relative order.

## Expected Behavior

```
Start:            10 -> 20 -> 30 -> 40
insertAt(0, 5):   5 -> 10 -> 20 -> 30 -> 40
insertAt(2, 15):  5 -> 10 -> 15 -> 20 -> 30 -> 40
insertAt(6, 45):  5 -> 10 -> 15 -> 20 -> 30 -> 40 -> 45
Size: 7
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the single-pass approach: walk from `head`, then relink.

## Think About

- To place a new node at position `index`, which existing node must you stop on before relinking — the one *at* `index` or the one *before* it?
- After the walk loop finishes, what position is `cur` at? Count the steps by hand for `insertAt(2, 15)`.
- Why does inserting at the very end behave differently from inserting in the middle, and what does that tell you about the walk?
