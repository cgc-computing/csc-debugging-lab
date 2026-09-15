# Checking Account With Overdraft

**Course:** CSC205 &nbsp;|&nbsp; **Module 2:** Inheritance and Object-Oriented Design &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`BankAccount` supports deposits and withdrawals that may not exceed the balance. `CheckingAccount` extends it and relaxes the rule: a withdrawal is approved as long as the balance would not fall below the negative of the overdraft limit. Every withdrawal, approved or declined, should be reflected in `getBalance()`.

## Expected Behavior

```
Opening balance: $100.00
After deposit of $50.00: $150.00
Withdraw $80.00: approved
Balance now: $70.00
Withdraw $150.00: approved
Balance now: $-80.00
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `CheckingAccount` as a subclass of `BankAccount`.

## Think About

- How many `balance` values does a single `CheckingAccount` object actually hold? Draw the object.
- Which `balance` does `deposit` update, and which one does the overridden `withdraw` update?
- Why did the author of `CheckingAccount` declare a field at all? What access modifier in the superclass would make that unnecessary?
