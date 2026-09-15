# Restaurant Receipt

**Course:** CSC110 &nbsp;|&nbsp; **Module 2:** Data and Expressions &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads a meal subtotal, computes a 15% tip, and prints the subtotal, the tip, and the
grand total. Tips are not rounded to whole dollars.

## Expected Behavior

Sample run (the user types `52.40`):

```
Enter the meal subtotal: 52.40
Subtotal:  $52.4
Tip (15%): $7.86
Total:     $60.26
```

## How to Run

```bash
g++ -std=c++17 -Wall -o receipt receipt.cpp
./receipt
```

(on Windows: `receipt.exe` or `.\receipt.exe`)

When prompted, type a dollar amount such as `52.40` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- What is the exact value of `52.40 * 0.15`? What value do you expect the tip variable to hold?
- What happens when a value with a fractional part is stored in a variable of a whole-number type?
- Which of the three printed values would you expect to be affected, and which would not?
