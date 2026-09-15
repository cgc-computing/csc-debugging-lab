# Linked List Remove by Value

**Course:** CSC205 &nbsp;|&nbsp; **Module 7:** Lists &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

`remove(value)` finds the first node holding `value`, unlinks it from the singly linked list, frees its memory, and returns `true`; it returns `false` if the value is absent. Removing from the middle, the front, and the back must all work.

## Expected Behavior

```
[10, 20, 30, 40, 50]  size=5
remove 30: removed  [10, 20, 40, 50]  size=4
remove 99: not found  [10, 20, 40, 50]  size=4
remove 10: removed  [20, 40, 50]  size=3
remove 50: removed  [20, 40]  size=2
```

## How to Run

Build with the address sanitizer enabled so that any invalid memory access is reported clearly:

```bash
g++ -std=c++17 -Wall -fsanitize=address -o remove_node remove_node.cpp
./remove_node
```
(on Windows: `remove_node.exe` or `.\remove_node.exe`; if your compiler does not support `-fsanitize=address`, omit that flag)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Fix one problem, rebuild, and run again — there may be more than one thing to find.

## Think About

- Once a node has been handed to `delete`, what are you allowed to do with the pointer that used to refer to it?
- Write down the order of the steps needed to unlink a node: read its `next`, redirect the predecessor, free the node. Does the order matter? Why?
- Which node has no predecessor? Trace `remove` for that node and watch what `previous` holds.
