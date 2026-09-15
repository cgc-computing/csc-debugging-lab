# Solution: Price with Sales Tax

**Course/Module/Activity:** CSC110 · Module 6 User-Defined Static Methods · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

The after-tax price equals the before-tax price:

```
Sticker price: 50.00
Before tax: $50.00
After tax:  $50.00
```

## The Bug(s)

`PriceCalculator.java`, in `main`:

```java
addTax(price);
```

The method's return value is discarded. `addTax` itself is correct.

## Why the Program Behaved Incorrectly

`addTax` receives a *copy* of `price`, computes 54.00, and returns it. Nothing in `main` receives the returned value, so it is thrown away. `main`'s own `price` variable was never touched (a method cannot modify its caller's local variables) and still holds 50.00 when it is printed the second time.

## The Concept This Illustrates

Methods communicate results back to the caller through their return value, and the caller must *use* that value (assign it, print it, pass it along). The call `formatDollars(price)` in the same program shows the correct pattern: its result is used directly in the `println`. Students often believe that a method "does something to" the argument.

## The Correction

```java
// before
addTax(price);

// after
price = addTax(price);
```

## Instructor Notes

- An alternative correct fix: `double finalPrice = addTax(price);` and print `finalPrice`. Arguably clearer; accept it.
- A tempting wrong fix is to change `addTax` to a `void` method that prints the result itself. It produces the right text but breaks the separation between computing and printing; ask why `formatDollars` is more useful as a returning method.
- Pair this with debug02 in the same module, which shows the mirror-image confusion (trying to change the caller's variable through the parameter).
