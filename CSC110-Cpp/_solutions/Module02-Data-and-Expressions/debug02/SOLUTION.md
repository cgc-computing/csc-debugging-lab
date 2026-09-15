# Solution: Restaurant Receipt

**Course/Module/Activity:** CSC110 · Module 2 Data and Expressions · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

With input `52.40`:

```
Subtotal:  $52.4
Tip (15%): $7
Total:     $59.4
```

The tip is a whole dollar amount and the total is 86 cents short.

## The Bug(s)

`receipt.cpp`, `main`:

```cpp
int tip = subtotal * 0.15;
```

The tip is declared as `int`. The product `52.40 * 0.15 = 7.86` is a `double`, and storing it in an
`int` truncates it to `7`.

## Why the Program Behaved Incorrectly

Assigning a floating-point value to an `int` variable is an implicit narrowing conversion: the
fractional part is discarded (not rounded). Every later use of `tip` sees `7`, so
`total = 52.4 + 7 = 59.4`. The subtotal is unaffected because it was never converted.

## The Concept This Illustrates

Variable types constrain the values they can hold. Choosing `int` for a quantity that is naturally
fractional (money computed from a percentage) silently loses information. The module's lesson is
that conversions between numeric types happen at assignment and follow fixed rules (truncation
toward zero for floating to integer).

## The Correction

```cpp
// before
int tip = subtotal * 0.15;

// after
double tip = subtotal * 0.15;
```

## Instructor Notes

- Compile with `-Wall` and the program emits no warning; ask students why the compiler allowed this.
  (Implicit narrowing is legal C++; `-Wconversion` would flag it.)
- Some students will wrap the expression in `static_cast<int>(...)` or `round(...)`, believing the
  problem is the missing rounding rather than the type. Ask what a 15% tip on $52.40 "should" be.
- Follow-up: what if the requirement really were whole-dollar tips? Discuss `round` from `<cmath>`
  (arriving next module) versus truncation.
