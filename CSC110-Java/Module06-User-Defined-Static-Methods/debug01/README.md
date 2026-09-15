# Price with Sales Tax

**Course:** CSC110 &nbsp;|&nbsp; **Module 6:** User-Defined Static Methods &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program reads the sticker price of an item and prints the price before and after 8% sales tax. A helper method `addTax` computes the price with tax, and a second helper `formatDollars` formats an amount as dollars and cents.

## Expected Behavior

```
Sticker price: 50.00
Before tax: $50.00
After tax:  $54.00
```

## How to Run

```bash
javac PriceCalculator.java
java PriceCalculator
```

Type a price and press Enter. Use `50.00` to reproduce the sample run.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- What does `addTax` compute, and what happens to that value after the method returns?
- Look at how `formatDollars` is called and compare it with how `addTax` is called. What is different?
- Can a method change the value stored in a variable that belongs to `main`? How does information get back from a method to its caller?
