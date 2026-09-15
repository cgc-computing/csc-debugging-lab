# Two Values in Order

**Course:** CSC110 &nbsp;|&nbsp; **Module 6:** User-Defined Static Methods &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads two integers and prints the smaller one first, then the larger one. If the
user enters them in the wrong order, a helper function `swapValues` exchanges them.

## Expected Behavior

Sample run (the user types `42 17`):

```
Enter two integers: 42 17
Smaller: 17
Larger:  42
```

If the values are already in order (for example `3 9`), they print unchanged.

## How to Run

```bash
g++ -std=c++17 -Wall -o swap_values swap_values.cpp
./swap_values
```

(on Windows: `swap_values.exe` or `.\swap_values.exe`)

Type two integers separated by a space, for example `42 17`, and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- Inside `swapValues`, are `a` and `b` the same variables as `low` and `high` in `main`, or something else?
- Trace the function by hand: what are `a` and `b` when it ends? What are `low` and `high` at that moment?
- What are the different ways a function can affect a variable that belongs to its caller?
