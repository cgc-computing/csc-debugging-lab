# Solution: Prices With Sales Tax

**Course/Module/Activity:** CSC110 · Module 6 User-Defined Static Methods · debug01
**Bug type(s):** conceptual/design (return value ignored)
**Bug count:** 2 (the same misconception twice)

## Observed Behavior

With input `10 25`, no tax is ever applied:

```
Item 1 with tax: 10
Item 2 with tax: 25
Total with tax:  35
```

The program compiles with no warnings.

## The Bug(s)

`price_with_tax.cpp`, `main`:

```cpp
addTax(price1);
addTax(price2);
```

Each call computes the taxed price and returns it, but the caller discards the returned value.
`price1` and `price2` are never updated.

## Why the Program Behaved Incorrectly

`addTax` receives a *copy* of its argument, computes `price * 1.08`, and returns that number. A
call used as a bare statement evaluates the function and throws the result away, exactly like
writing `10.8;` on a line by itself. The variables in `main` are untouched, so the output shows the
original prices.

## The Concept This Illustrates

A function that `return`s a value communicates with its caller *only* through that value; the
caller must capture it (assign it, print it, or use it in an expression). Students who think of a
function as "doing something to" its argument expect `addTax(price1)` to modify `price1`. This is
the return-value half of the call-by-value story (the other half is Module 6 debug02).

## The Correction

```cpp
// before
addTax(price1);
addTax(price2);

// after
price1 = addTax(price1);
price2 = addTax(price2);
```

## Instructor Notes

- Students sometimes "fix" this by moving the `cout` inside `addTax` (printing instead of
  returning). Ask how the total line could then be computed.
- Others change `addTax` to take a reference (`double& price`) and assign inside. That works, and
  it is a fine moment to contrast the two designs; ask which is easier to reason about.
- Ask why the compiler did not complain. (Ignoring a return value is legal; mention `[[nodiscard]]`
  as a modern tool if the group is curious.)
