# Savings Account Interest

**Course:** CSC205 &nbsp;|&nbsp; **Module 2:** Inheritance and Object-Oriented Design &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`Account` stores an owner and a balance and supports deposits. `SavingsAccount` extends it with an interest rate and an `addInterest()` operation that grows the balance by one period of interest.

## Expected Behavior

```
Dana opens a savings account with $1000
After deposit:  $1200
After interest: $1260
```

## How to Run

```bash
g++ -std=c++17 -Wall -o savings_account savings_account.cpp
./savings_account
```
(on Windows: `savings_account.exe` or `.\savings_account.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did.

## Think About

- How many `double` values does a single `SavingsAccount` object actually store? Draw the object.
- When `addInterest()` writes to `balance`, which storage does it change? When `getBalance()` reads `balance`, which storage does it read?
- What does `protected` give a derived class that `private` does not? Does this derived class take advantage of it?
