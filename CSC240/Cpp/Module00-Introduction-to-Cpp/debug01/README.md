# Welcome Badge

**Course:** CSC240 &nbsp;|&nbsp; **Module 0:** Introduction to C++ &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program asks a visitor for their full name and their age, then prints a two-line badge inside a box. A helper that takes the line by reference pads it with spaces so the box edges line up.

## Expected Behavior

```
Enter your full name: Ada Lovelace
Enter your age: 36
+--------------------------------+
| Hello, Ada Lovelace!           |
| Age: 36                        |
+--------------------------------+
```

## How to Run

```bash
g++ -std=c++17 -Wall -o welcome_badge welcome_badge.cpp
./welcome_badge
```

(on Windows: `welcome_badge.exe` or `.\welcome_badge.exe`)

At the first prompt type `Ada Lovelace` and press Enter; at the second type `36` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- Where does `>>` stop reading when it fills a `std::string`? What is still waiting in the input stream after that?
- The age printed is not the number you typed. What did the second `>>` try to read, and what does a stream do to an `int` when the read fails?
- Java's `Scanner` has both `next()` and `nextLine()`. What are the two corresponding ways to read text in C++, and when do you want each?
