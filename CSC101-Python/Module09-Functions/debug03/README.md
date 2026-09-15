# Bake Sale Tracker

**Course:** CSC101 &nbsp;|&nbsp; **Module 9:** Functions &nbsp;|&nbsp; **Activity:** debug03  
**Language:** Python 3

## Goal

The program records a series of bake-sale transactions. A helper function adds each sale to the
day's running total and prints a receipt line; after all sales are entered, the program prints the
total for the day.

## Expected Behavior

```
Bake Sale Tracker
How many sales to record? 3
Sale 1 amount: $2.50
  Recorded $2.50  (total so far: $2.50)
Sale 2 amount: $4.00
  Recorded $4.00  (total so far: $6.50)
Sale 3 amount: $1.25
  Recorded $1.25  (total so far: $7.75)

Total for the day: $7.75
```

## How to Run

```bash
python3 bake_sale.py
```

Type `3`, then `2.50`, `4.00`, and `1.25`, pressing Enter after each.

## Your Task

Run the program with the sample values and compare with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. You may change what the function takes
in and gives back, but keep a function that records one sale.

## Think About

* When a function assigns to a variable name, where does that variable live: inside the function
  or in the rest of the program?
* Inside `record_sale`, Python has to look up `total_sales` on the right-hand side of the
  assignment. Which `total_sales` does it find, and has that one been given a value yet?
* If a function needs to produce an updated total, how should that total get back out to the
  code that called it?
