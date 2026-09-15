# Shape Registry

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** OOP in C++ and Virtual Functions &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

Each shape announces itself when it is constructed and remembers the kind it registered as. `Circle` and `Rectangle` derive from `Shape` and override `kind()` and `area()`. `main` builds one of each and prints, through base-class pointers, the kind, the name it registered under, and the area.

## Expected Behavior

```
Registered a circle
Registered a rectangle
circle registered as "circle", area 12.57
rectangle registered as "rectangle", area 12.00
```

## How to Run

```bash
g++ -std=c++17 -Wall -o shape_registry shape_registry.cpp
./shape_registry
```

(on Windows: `shape_registry.exe` or `.\shape_registry.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the "Registered a ..." message in the `Shape` constructor; you may change constructor signatures.

## Think About

- `kind()` is virtual and clearly works in the loop at the end. Why does the very same call give a different answer earlier in the program?
- When the `Shape` part of a `Circle` is being constructed, does a `Circle` exist yet? What is the dynamic type of `*this` at that moment?
- In Java a constructor that calls an overridden method reaches the subclass version (and can see uninitialized fields). C++ makes a different choice. Which is safer, and what does it cost?
