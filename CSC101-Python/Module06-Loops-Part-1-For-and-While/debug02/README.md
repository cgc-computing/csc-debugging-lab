# Savings Goal Countdown

**Course:** CSC101 &nbsp;|&nbsp; **Module 6:** Loops Part 1: For and While &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

The program reads a current balance, a savings goal, and a set monthly deposit. It counts how
many monthly deposits are needed until the balance reaches or passes the goal, then reports the
number of months and the ending balance.

## Expected Behavior

```
Current balance: $100
Savings goal: $1000
Monthly deposit: $150

You will reach $1000.00 in 6 month(s).
Ending balance: $1000.00
```

The answer should appear immediately after the third value is entered.

## How to Run

```bash
python3 savings_goal.py
```

Type `100`, `1000`, and `150`, pressing Enter after each. If the program does not finish, press
`Ctrl+C` to stop it.

## Your Task

Run the program with the sample values and compare with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* For a `while` loop to end, something in its condition has to change. Which variables appear in
  this loop's condition, and where in the body does each one change?
* Trace the first two trips through the loop by hand, writing down `balance` and `months` after
  each trip.
* Find every line in the loop body that is supposed to change a variable. For each one, ask: does
  this line actually *store* a new value anywhere?
