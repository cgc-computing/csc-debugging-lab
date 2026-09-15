# Money

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** C++ STL and Operator Overloading &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`Money` is a small value type that stores an amount as whole cents and overloads `+`, `*`, `<`, and `<<` so that a receipt can be written with ordinary arithmetic and printed with `std::cout`. `main` prices a coffee and a bagel, adds tax, and compares two coffees against the total.

## Expected Behavior

```
Coffee:      $3.75
Bagel:       $2.50
Subtotal:    $6.25
Tax:         $0.47
Total:       $6.72
Two coffees: $7.50
Two coffees cost at least as much as the whole order.
```

## How to Run

```bash
g++ -std=c++17 -Wall -o money money.cpp
./money
```

(on Windows: `money.exe` or `.\money.exe`)

No input is required. Read the compiler output carefully; the first problem shows up there.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `main` exactly as it is; the operators must make that code work.

## Think About

- For an expression like `left OP right`, when the operator is a member function, which operand becomes `*this` and which becomes the parameter? Now look at `std::cout << coffee`: which operand is on the left?
- After `Money subtotal = coffee + bagel;`, what should `coffee` hold? What does `int a = 3, b = 4; int c = a + b;` do to `a`?
- One of the operators is `const` and one is not. Is that difference a clue, or a coincidence?
