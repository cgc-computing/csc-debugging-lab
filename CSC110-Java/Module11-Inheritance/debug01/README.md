# Payroll with Managers

**Course:** CSC110 &nbsp;|&nbsp; **Module 11:** Inheritance &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`Employee` has a name and a salary. `Manager` extends `Employee` and adds a department. `PayrollTester` creates one clerk and one manager, prints a payroll line for each, and prints the total payroll.

## Expected Behavior

```
Payroll
-------
Rosa Diaz earns $42,000.00
Terry Jeffords earns $78,500.00 and manages Operations
Total payroll: $120,500.00
```

## How to Run

```bash
javac *.java
java PayrollTester
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `Employee` and the tester are correct; look at the subclass.

## Think About

- When a `Manager` is created, which constructors run, and in what order?
- The `Manager` constructor receives a name and a salary. What does it do with them?
- If a subclass constructor does not say which superclass constructor to use, which one does Java call?
