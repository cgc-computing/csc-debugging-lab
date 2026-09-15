# Prices With Sales Tax

**Course:** CSC110 &nbsp;|&nbsp; **Module 6:** User-Defined Static Methods &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads two item prices and uses a helper function, `addTax`, to compute each price with
8% sales tax added. It prints both taxed prices and their total.

## Expected Behavior

Sample run (the user types `10 25`):

```
Enter two item prices: 10 25
Item 1 with tax: 10.8
Item 2 with tax: 27
Total with tax:  37.8
```

## How to Run

```bash
g++ -std=c++17 -Wall -o price_with_tax price_with_tax.cpp
./price_with_tax
```

(on Windows: `price_with_tax.exe` or `.\price_with_tax.exe`)

Type two prices separated by a space, for example `10 25`, and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- What does `addTax` produce, and where does that result go after the function finishes?
- After the call `addTax(price1);`, what value do you expect `price1` to have in `main`? Why?
- Compare the call to how the program uses `cin >> price1`. How does a function "hand back" a value to its caller?
