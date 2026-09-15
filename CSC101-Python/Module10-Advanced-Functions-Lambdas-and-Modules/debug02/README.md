# Shopping Carts

**Course:** CSC101 &nbsp;|&nbsp; **Module 10:** Advanced Functions, Lambdas, and Modules &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

A helper function `add_item` adds an item to a shopping cart and returns the cart. When it is
called without a cart, it should start a brand-new empty cart. The program uses it to build two
independent carts, one for Alice and one for Bob.

## Expected Behavior

```
Alice's cart: ['apples', 'bread']
Bob's cart:   ['cereal', 'milk']
```

## How to Run

```bash
python3 shopping_cart.py
```

No input is required.

## Your Task

Run the program and compare both carts with the Expected Behavior. This program contains one or
more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the
original version behaved the way it did. Keep the `cart` parameter optional so that
`add_item("apples")` still works.

## Think About

* When is the expression for a default argument value evaluated: every time the function is
  called, or only once?
* A list is mutable. If the same list object is used as the default more than once, what happens
  to items appended to it?
* Bob's very first call does not pass a cart. Which list does his `"cereal"` go into?
