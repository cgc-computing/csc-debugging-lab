# Linked List Remove by Value

**Course:** CSC205 &nbsp;|&nbsp; **Module 7:** Lists &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

`remove(value)` deletes the first node in a hand-built singly linked list whose value matches, returning `true` if a node was removed and `false` otherwise. `head`, `tail`, and `size` must all stay accurate so that later operations (like `addLast`) keep working.

## Expected Behavior

```
Start:      10 -> 20 -> 30 -> 40   size 4
remove(30): removed   -> 10 -> 20 -> 40   size 3
remove(10): removed   -> 20 -> 40   size 2
remove(99): not found   -> 20 -> 40   size 2
remove(40): removed   -> 20   size 1
addLast(50): 20 -> 50   size 2
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `remove` as a single walk with a `prev`/`cur` pair.

## Think About

- Where does the walk start, and which node is therefore never compared against `value`?
- Which node has no predecessor, and what has to change when *that* node is removed?
- List every field of the list object that describes its state. After a successful removal, which of them did the code update, and which did it leave alone?
