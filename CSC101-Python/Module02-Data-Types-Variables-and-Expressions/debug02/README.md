# Split the Bill

**Course:** CSC101 &nbsp;|&nbsp; **Module 2:** Data Types, Variables, and Expressions &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

The program reads a restaurant subtotal, a tip percentage, and the number of people at the table.
It prints the tip, the total including tip, and how much each person owes when the total is split
evenly.

## Expected Behavior

```
Bill subtotal: $60
Tip percentage (e.g., 18): 20
Number of people splitting the bill: 4

Tip amount:       $12.00
Total with tip:   $72.00
Each person pays: $18.00
```

## How to Run

```bash
python3 split_bill.py
```

Type `60`, `20`, and `4`, pressing Enter after each.

## Your Task

Run the program with the sample values and check every printed number against the Expected
Behavior. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not
rewrite the program; the structure is fine.

## Think About

* Work out each person's share by hand from the sample numbers. Which printed value disagrees?
* In an arithmetic expression with both `+` and `/`, which operation does Python perform first?
* How can you make Python perform an addition *before* a division when you need it to?
