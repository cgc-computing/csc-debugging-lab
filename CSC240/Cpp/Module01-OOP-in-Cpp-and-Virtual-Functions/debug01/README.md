# Staff Payroll

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** OOP in C++ and Virtual Functions &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

Three kinds of staff (`Employee`, `Manager`, `Intern`) share a base class. `main` stores them in an array of base-class pointers, prints each person's title, name, and monthly pay, and totals the payroll. A manager's monthly pay adds a bonus; an intern is paid hourly.

## Expected Behavior

```
Employee Priya Shah: 5000.00
Manager Tom Reyes: 8000.00
Intern Lee Chen: 1440.00
Total monthly payroll: 14440.00
```

## How to Run

```bash
g++ -std=c++17 -Wall -o staff_payroll staff_payroll.cpp
./staff_payroll
```

(on Windows: `staff_payroll.exe` or `.\staff_payroll.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- The title column is right for every person but the pay column is not. Both are called the same way through the same pointer. What is different about how the two methods are declared?
- In Java, every instance method is dispatched on the object's runtime class. What does C++ do by default when you call a method through a base-class pointer?
- The intern's pay comes out as 0.00. Which class's `monthly_pay` produced that number, and from which field?
