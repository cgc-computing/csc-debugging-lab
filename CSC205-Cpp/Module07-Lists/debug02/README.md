# Linked List Insert at Index

**Course:** CSC205 &nbsp;|&nbsp; **Module 7:** Lists &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`insertAt(index, value)` inserts `value` into a singly linked list so that it ends up at position `index`, where 0 is the front and `size()` is one past the last node (an append). Indices outside `0..size()` are rejected with `false`.

## Expected Behavior

```
[5, 10]
insert 7 at 1: ok  [5, 7, 10]
insert 20 at 3: ok  [5, 7, 10, 20]
insert 99 at 9: rejected  [5, 7, 10, 20]
size: 4
```

## How to Run

```bash
g++ -std=c++17 -Wall -o insert_at insert_at.cpp
./insert_at
```
(on Windows: `insert_at.exe` or `.\insert_at.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did.

## Think About

- To insert a node at position `k`, which node do you need a pointer to — the one at `k`, or the one before it? How many `next` hops from `head` is that node?
- For a list of `n` nodes, how many *valid* insertion positions are there? Is `n` one of them?
- Two of the calls in `main` exercise the two ends of the valid range. Which parts of the function decide each one?
