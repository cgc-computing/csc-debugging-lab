# Card Hand Insertion Sort

**Course:** CSC205 &nbsp;|&nbsp; **Module 11:** Sorting &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program sorts a six-card hand into ascending order using insertion sort, printing the hand after each pass so the growing sorted prefix is visible.

## Expected Behavior

```
Start:   7 3 9 2 8 4
  pass 1: 3 7 9 2 8 4
  pass 2: 3 7 9 2 8 4
  pass 3: 2 3 7 9 8 4
  pass 4: 2 3 7 8 9 4
  pass 5: 2 3 4 7 8 9
Sorted:  2 3 4 7 8 9
```

## How to Run

Build with the address sanitizer enabled so that any invalid memory access is reported clearly:

```bash
g++ -std=c++17 -Wall -fsanitize=address -o insertion_sort insertion_sort.cpp
./insertion_sort
```
(on Windows: `insertion_sort.exe` or `.\insertion_sort.exe`; if your compiler does not support `-fsanitize=address`, omit that flag)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Read the sanitizer report carefully: it tells you what kind of access failed and where.

## Think About

- In pass 1 the key is 3 and the only card to its left is 7. After 7 is shifted one slot right, what is `j`? What does the loop check next?
- When two conditions are joined with `&&`, in what order are they evaluated, and is the second one evaluated when the first is false? Does that order matter here?
- What is the smallest index you are allowed to use on this vector? Which part of the loop is supposed to guarantee that?
