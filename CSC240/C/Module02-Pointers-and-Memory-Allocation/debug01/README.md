# Sort Three Numbers

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Pointers and Memory Allocation &nbsp;|&nbsp; **Activity:** debug01
**Language:** C (C11)

## Goal

The program reads three integers and prints them in ascending order. The sorting is done by a `sort_three` function that receives the addresses of the three variables and calls a `swap` helper whenever two of them are out of order.

## Expected Behavior

```
Enter three integers: 42 7 19
Before: 42 7 19
After:  7 19 42
```

## How to Run

```bash
gcc -std=c11 -Wall -o sort_three sort_three.c
./sort_three
```

(on Windows: `sort_three.exe` or `.\sort_three.exe`)

When prompted, type `42 7 19` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- `swap` receives two pointers. What is stored *in* those pointer variables, and what do they point *at*?
- Draw a box diagram of `first`, `second`, `a`, `b`, and `temp` just before `swap` returns. Which boxes changed?
- Why does `sort_three` need pointers at all? What would happen if it took three plain `int` parameters?
