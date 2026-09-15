# Simple Receipt

**Course:** CSC110 &nbsp;|&nbsp; **Module 2:** Data and Expressions &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

The program reads an item price and a quantity, then prints a small receipt showing the subtotal, the 8% sales tax, and the total due (subtotal plus tax).

## Expected Behavior

With a price of 12.50 and a quantity of 2, the subtotal is 25.0, the tax is 2.0, and the total due is 27.0:

```
Item price: 12.50
Quantity: 2

Subtotal:  $25.0
Tax (8%):  $2.0
Total due: $27.0
```

## How to Run

```bash
javac Receipt.java
java Receipt
```

Type the price, press Enter, then type the quantity and press Enter. Use `12.50` and `2` to reproduce the sample run.

## Your Task

Run the program with the sample values and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- Read the last line of output carefully. What number is it actually showing you?
- When Java evaluates an expression with several `+` operators, in what order does it work through them?
- What does `+` mean when one of its operands is a `String`? What does it mean when both operands are numbers?
