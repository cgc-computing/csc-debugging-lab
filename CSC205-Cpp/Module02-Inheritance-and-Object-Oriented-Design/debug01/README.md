# Employee and Manager Pay

**Course:** CSC205 &nbsp;|&nbsp; **Module 2:** Inheritance and Object-Oriented Design &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`Employee` computes weekly pay as hours worked times an hourly rate. `Manager` inherits from `Employee` and overrides the hourly rate to add a per-hour bonus. The program prints each person's title, rate, and weekly pay.

## Expected Behavior

```
Employee Alice ($20/hr): $800
Manager Bob ($35/hr): $1400
Manager Cara ($30/hr): $900
```

## How to Run

```bash
g++ -std=c++17 -Wall -o employee_pay employee_pay.cpp
./employee_pay
```
(on Windows: `employee_pay.exe` or `.\employee_pay.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not remove the `Manager` class or its override; the class design is fine.

## Think About

- When a `Manager` is constructed, in what order do the `Employee` and `Manager` parts get built?
- At the moment the pay is calculated, what kind of object exists so far? Which version of `hourlyRate()` can it possibly run?
- The printed rate is right but the printed pay is wrong. What does that tell you about *when* each value is computed?
