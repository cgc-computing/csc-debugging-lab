# Book Catalog

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** C++ STL and Operator Overloading &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

A library catalog is kept in a `std::set<Book>` so that duplicate titles are rejected automatically and the books come out sorted by publication year. `Book` supplies its own `operator<` so the set knows how to order it. `main` adds six books (one of them twice) and prints the catalog.

## Expected Behavior

```
Added   The C Programming Language (1978)
Added   The Little Schemer (1974)
Added   Programming in Prolog (1981)
Added   Effective C++ (2005)
Added   Learn Prolog Now (2005)
Skipped The Little Schemer (1974): already in catalog

Catalog by year (5 titles):
  1974  The Little Schemer
  1978  The C Programming Language
  1981  Programming in Prolog
  2005  Effective C++
  2005  Learn Prolog Now
```

## How to Run

```bash
g++ -std=c++17 -Wall -o book_catalog book_catalog.cpp
./book_catalog
```

(on Windows: `book_catalog.exe` or `.\book_catalog.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep using `std::set<Book>` and keep `operator<` as the set's ordering; do not switch containers.

## Think About

- `std::set` never calls `==`. Given only `operator<`, how does the set decide that two elements are "the same"? Write the rule down as a boolean expression.
- Apply that rule to the two books from 2005. What does the set conclude about them?
- In Java, `TreeSet` has the same behavior with `compareTo`. What does a correct comparison have to guarantee when two *different* books share a year?
