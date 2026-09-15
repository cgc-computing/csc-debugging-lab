# Shape Collection Areas

**Course:** CSC205 &nbsp;|&nbsp; **Module 3:** Polymorphism and Interfaces &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

A `Shape` base class with `Rectangle`, `Circle`, and `Square` subclasses. The program stores several shapes in one collection, prints each shape's name and area polymorphically, and sums the areas.

## Expected Behavior

```
rectangle area = 12
circle area = 3.14159
square area = 4
Total area = 19.1416
```

## How to Run

```bash
g++ -std=c++17 -Wall -o shapes shapes.cpp
./shapes
```
(on Windows: `shapes.exe` or `.\shapes.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The classes themselves are correct; focus on how `main` stores and uses them.

## Think About

- How big (in bytes) is a `Shape` compared with a `Circle`? What happens to the extra data when a `Circle` is copied *into* a variable whose type is exactly `Shape`?
- The methods are marked `virtual` and `override`. Under what conditions does a virtual call actually reach the derived version?
- What is the difference between a collection *of* shapes and a collection of *pointers or references to* shapes?
