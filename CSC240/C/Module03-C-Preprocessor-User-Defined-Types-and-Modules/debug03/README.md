# Expense Report

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** C Preprocessor, User-Defined Types, and Modules &nbsp;|&nbsp; **Activity:** debug03
**Language:** C (C11)

## Goal

The program stores a month of expenses as an array of `expense_t` records. Each record carries a category from an `enum`, which is used directly as an index into a `totals` array. The report prints every category with its total and a grand total.

## Expected Behavior

```
Category        Total
Food           260.00
Rent          1150.00
Travel          82.50
Utilities      119.35
Other           55.00
ALL           1666.85
```

## How to Run

```bash
gcc -std=c11 -Wall -o expense_report expense_report.c
./expense_report
```

(on Windows: `expense_report.exe` or `.\expense_report.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- What integer value does each enumerator have? Write them next to the `enum` and next to each element of the `category_names` array.
- The report is arithmetically consistent with itself in one way and inconsistent in another. Which totals are right, and which labels are attached to them?
- How many categories are there, and how many rows does the loop print? What is `CATEGORY_COUNT` for, and what does its value depend on?
- If someone later adds a `HEALTH` category, which lines of this file must change so that everything stays lined up?
