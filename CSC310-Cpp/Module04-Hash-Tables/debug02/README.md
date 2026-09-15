# Deleting from an Open-Addressing Hash Set

**Course:** CSC310 &nbsp;|&nbsp; **Module 4:** Hash Tables &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`ProbingSet` is a hash set of `int` keys using open addressing with linear probing in a table of capacity 7. It supports `insert`, `contains`, and `remove`. Keys that are still in the set must remain findable after other keys are removed, and freed space must be reusable by later inserts.

## Expected Behavior

```
after inserts:   [0]=7 [1]=14 [2]=21 [3]=3 [4]=10 [5]=- [6]=- 
contains(21) = true
contains(10) = true
after removals:  [0]=7 [1]=x [2]=21 [3]=x [4]=10 [5]=- [6]=- 
contains(21) = true
contains(10) = true
contains(14) = false
after insert 28: [0]=7 [1]=28 [2]=21 [3]=x [4]=10 [5]=- [6]=- 
contains(28) = true
contains(21) = true
```

(`-` marks a slot that has never been used; `x` marks a slot whose key was removed.)

## How to Run

```bash
g++ -std=c++17 -Wall -o open_addressing_delete open_addressing_delete.cpp
./open_addressing_delete
```

(on Windows: `open_addressing_delete.exe` or `.\open_addressing_delete.exe`)

## Your Task

Run the program, compare its output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep open addressing with linear probing.

## Think About

- Keys 7, 14, and 21 all hash to slot 0. Where does each one end up, and what path does `contains(21)` follow to reach it?
- `contains` stops probing when it meets a never-used slot. Why is that stopping rule correct for a table that has only had inserts, and what assumption does it make about the slots along the probe path?
- After removing 14, what should the slot that held 14 mean to a *search*? What should it mean to an *insert*? Are those the same?
