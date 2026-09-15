# Test Score Average

**Course:** CSC110 &nbsp;|&nbsp; **Module 2:** Data and Expressions &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads three whole-number test scores, adds them, and prints the total and the
average. The average should keep its fractional part.

## Expected Behavior

Sample run (the user types `88 90 91`):

```
Enter three test scores: 88 90 91
Total points: 269
Average: 89.6667
```

## How to Run

```bash
g++ -std=c++17 -Wall -o test_average test_average.cpp
./test_average
```

(on Windows: `test_average.exe` or `.\test_average.exe`)

When prompted, type three whole numbers separated by spaces, for example `88 90 91`, and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- What is the type of `total / 3`? Does the type of the variable receiving the result change that?
- In what order does C++ evaluate the expression on the right-hand side and then store it?
- What would you expect `7 / 2` to print in C++? What about `7.0 / 2`?
