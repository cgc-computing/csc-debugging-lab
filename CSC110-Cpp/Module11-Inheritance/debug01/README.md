# Employees and Managers

**Course:** CSC110 &nbsp;|&nbsp; **Module 11:** Inheritance &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`Employee` stores a name and salary. `Manager` inherits from `Employee` and adds a department.
The program creates one of each and prints a summary line for both, then looks up the manager's
name through the inherited getter.

## Expected Behavior

The program takes no input. A correct run prints:

```
Ana Ruiz earns $52000
Ben Okafor manages Engineering and earns $78000
Manager's name on file: Ben Okafor
```

## How to Run

```bash
g++ -std=c++17 -Wall -o employee_manager employee_manager.cpp
./employee_manager
```

(on Windows: `employee_manager.exe` or `.\employee_manager.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Keep `name` and
`salary` private to `Employee`; do not move them into `Manager`.

## Think About

- When a `Manager` is constructed, which constructors run, and in what order?
- The `Manager` constructor receives a name and a salary. Where do those values go?
- If a derived-class constructor says nothing about the base class, which base constructor does C++ call?
