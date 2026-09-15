# Solution: Test Score Average

**Course/Module/Activity:** CSC110 · Module 2 Data and Expressions · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

With input `88 90 91` the program prints:

```
Total points: 269
Average: 89
```

The fractional part of the average is lost.

## The Bug(s)

`test_average.cpp`, `main`:

```cpp
double average = total / 3;
```

`total` and `3` are both `int`, so `/` performs integer division and produces `89` *before* the
result is stored in the `double`.

## Why the Program Behaved Incorrectly

C++ chooses the kind of division from the operand types, not from the destination variable.
`269 / 3` with two `int` operands is `89` (remainder discarded). That `int` is then converted to
`89.0` when stored in `average`. The conversion happens too late to recover the `.6667`.

## The Concept This Illustrates

Integer division and implicit conversion order: the type of an expression is determined by its
operands, and casting (or making one operand floating-point) must happen *inside* the expression.
Students often believe "storing into a `double` makes the math floating-point."

## The Correction

```cpp
// before
double average = total / 3;

// after
double average = static_cast<double>(total) / 3;
// or:  double average = total / 3.0;
```

## Instructor Notes

- A common attempted fix is `double average = (double)(total / 3);`, which casts *after* the
  integer division and changes nothing. Ask the student to trace the parentheses.
- Another attempt is declaring `total` as `double`; that works, but ask why the printed total should
  still look like a whole number and whether `int` is the more honest type for a sum of `int`s.
- Follow-up: what happens with `3.0` vs `3`? Why does `89.6667` show only four decimals? (Default
  `cout` precision is six significant digits.)
