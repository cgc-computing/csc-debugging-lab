# Store Catalog Interface

**Course:** CSC205 &nbsp;|&nbsp; **Module 3:** Polymorphism and Interfaces &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`Sellable` is an interface (a class with only pure virtual functions). `Book` and `Movie` implement it. `catalogTotal` walks a collection of `Sellable*`, prints each item, and sums the prices.

## Expected Behavior

```
Book: Data Structures - $14
Movie: Hackers - $9.99
Movie: The Long Cut - $14.99
Total: $38.98
```

## How to Run

```bash
g++ -std=c++17 -Wall -o catalog catalog.cpp
./catalog
```
(on Windows: `catalog.exe` or `.\catalog.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Read the compiler's messages carefully before changing anything.

## Think About

- What exactly has to match for a derived-class function to *override* a base-class virtual function? Name every part of the declaration that counts.
- What does the `override` keyword ask the compiler to check? What would have happened here without it?
- Why can a class with an unimplemented pure virtual function not be instantiated?
