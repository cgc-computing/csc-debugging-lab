# Quarterly Rainfall Table

**Course:** CSC110 &nbsp;|&nbsp; **Module 10:** More About Arrays &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

A 2-D array holds three years of rainfall, one row per year and one column per quarter (Q1–Q4). The program prints the table with a total for each year and a grand total for all three years.

## Expected Behavior

```
Year    Q1    Q2    Q3    Q4   Total
2022   3.2   4.1   2.8   5.0     15.1
2023   2.9   3.7   3.3   4.6     14.5
2024   4.0   3.9   2.5   5.4     15.8

Three-year total: 45.4 inches
```

## How to Run

```bash
javac RainfallTable.java
java RainfallTable
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- How many rows does `rainfall` have? How many columns? Which of those numbers does `rainfall.length` give you?
- Does a 2-D array have just one length? Which lengths matter when you print a table?
- Would the program have produced the right answer if the table had the same number of rows as columns? Why is that a dangerous kind of luck?
