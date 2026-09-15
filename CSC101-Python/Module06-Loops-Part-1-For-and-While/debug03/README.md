# Shopping Total with Tax

**Course:** CSC101 &nbsp;|&nbsp; **Module 6:** Loops Part 1: For and While &nbsp;|&nbsp; **Activity:** debug03  
**Language:** Python 3

## Goal

The program asks how many items were bought, reads each item's price, and prints the subtotal,
the 8% sales tax, and the grand total.

## Expected Behavior

```
How many items did you buy? 3
Price of item 1: $4.50
Price of item 2: $2.25
Price of item 3: $10.00

Subtotal: $16.75
Tax:      $1.34
Total:    $18.09
```

## How to Run

```bash
python3 shopping_total.py
```

Type `3`, then `4.50`, `2.25`, and `10.00`, pressing Enter after each.

## Your Task

Run the program with the sample prices and compare the three printed amounts with the Expected
Behavior. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not
rewrite the program; the structure is fine.

## Think About

* Trace the value of `total` after each price is entered. Write down its value at the top of the
  loop body and at the bottom.
* A variable that accumulates a sum over a loop is often called an accumulator. Where should an
  accumulator be given its starting value, and how many times should that happen?
* Which of the three sample prices does the printed subtotal match, and why that one?
