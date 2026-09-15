# Payroll With Manager Bonuses

**Course:** CSC205 &nbsp;|&nbsp; **Module 2:** Inheritance and Object-Oriented Design &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`Employee` stores a name and base salary. `Manager` extends `Employee` and adds a bonus, overriding `computePay()` so a manager's annual pay is base salary plus bonus. `Main` prints each staff member's pay and the payroll total.

## Expected Behavior

```
Ana    $52,000.00
Ben    $82,000.00
Cleo   $96,000.00
Payroll total: $230,000.00
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the three classes; the design (a `Manager` overriding `computePay()`) is intended.

## Think About

- In what order do the `Employee` and `Manager` constructors run, and what is the value of `bonus` at each moment?
- When `Employee`'s constructor calls `computePay()`, which class's version actually executes for a `Manager` object?
- Is it safe for a superclass constructor to call a method that a subclass might override? What would you do instead?
