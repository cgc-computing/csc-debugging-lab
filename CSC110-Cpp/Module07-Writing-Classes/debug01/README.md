# Rectangle Class

**Course:** CSC110 &nbsp;|&nbsp; **Module 7:** Writing Classes &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`Rectangle` stores a width and a height set by its constructor and provides getters plus `area()`
and `perimeter()` methods. The test program reads two dimensions, builds a `Rectangle`, and prints
all four values.

## Expected Behavior

Sample run (the user types `4 6.5`):

```
Enter width and height: 4 6.5
Width:     4
Height:    6.5
Area:      26
Perimeter: 21
```

## How to Run

```bash
g++ -std=c++17 -Wall -o rectangle rectangle.cpp
./rectangle
```

(on Windows: `rectangle.exe` or `.\rectangle.exe`)

Type two numbers separated by a space, for example `4 6.5`, and press Enter. Read any compiler
messages carefully.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- Inside the constructor, how many different variables are named `width`? Which one does the name refer to?
- What value do you expect the object's `width` field to have after the constructor finishes?
- How can a method refer explicitly to the object's own field when a parameter has the same name?
