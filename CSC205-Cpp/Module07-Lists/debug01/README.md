# Linked List Add at Both Ends

**Course:** CSC205 &nbsp;|&nbsp; **Module 7:** Lists &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

A singly linked list with `head` and `tail` pointers. `addFirst` inserts at the front and `addLast` appends at the back in O(1) using the tail pointer. `print` walks the list from the head.

## Expected Behavior

```
[5 -> 10 -> 20 -> 30 -> 40]  (size 5)
```

## How to Run

```bash
g++ -std=c++17 -Wall -o linked_list linked_list.cpp
./linked_list
```
(on Windows: `linked_list.exe` or `.\linked_list.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `addLast` O(1); do not walk the list to find the end.

## Think About

- Draw the list after each call in `main`, showing where `head` and `tail` point. At which step does your drawing stop matching what the code does?
- What must be true about `tail` *after* every successful `addLast` for the next `addLast` to work?
- The size is reported as 5 but fewer nodes print. Where did the missing nodes go, and is anything still pointing at them?
