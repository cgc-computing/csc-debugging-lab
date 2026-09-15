# Recursive Factorial

**Course:** CSC205 &nbsp;|&nbsp; **Module 5:** Recursion and Analysis of Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`factorial(n)` computes n! recursively for any non-negative `n`. The driver prints the factorial of several values, including the edge case 0! = 1.

## Expected Behavior

```
5! = 120
10! = 3628800
1! = 1
0! = 1
```

## How to Run

```bash
g++ -std=c++17 -Wall -o factorial factorial.cpp
./factorial
```
(on Windows: `factorial.exe` or `.\factorial.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did.

## Think About

- Trace `factorial(0)` by hand. Which branch runs? What is the next call?
- Every recursive function needs a base case that every valid input eventually reaches. Which inputs to this function actually reach its base case?
- What does the operating system do when a program calls itself hundreds of thousands of times without returning?
