# Solution: Simple Receipt

**Course/Module/Activity:** CSC110 · Module 2 Data and Expressions · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

Subtotal and tax are correct, but the total line shows the two numbers glued together instead of their sum:

```
Subtotal:  $25.0
Tax (8%):  $2.0
Total due: $25.02.0
```

## The Bug(s)

`Receipt.java`, in `main`, the final output statement:

```java
System.out.println("Total due: $" + subtotal + tax);
```

## Why the Program Behaved Incorrectly

The `+` operators are evaluated left to right. The first `+` has a `String` on its left, so it performs string concatenation, producing the string `"Total due: $25.0"`. The second `+` now also has a `String` on its left, so it concatenates again, appending `"2.0"`. Numeric addition never happens.

## The Concept This Illustrates

The `+` operator is overloaded: it is addition for two numbers but concatenation as soon as either operand is a `String`. Combined with left-to-right evaluation, this means the *position* of a number within a concatenation expression decides whether it gets added or appended.

## The Correction

```java
// before
System.out.println("Total due: $" + subtotal + tax);

// after
System.out.println("Total due: $" + (subtotal + tax));
```

## Instructor Notes

- Students who introduce a `double total = subtotal + tax;` variable have fixed it correctly and arguably more readably; accept it.
- Ask: what would `System.out.println(subtotal + tax + " is the total")` print? (Numeric addition happens first because the left operand is not yet a `String`.)
- Follow-up: why does `"Total due: $" + subtotal` work as intended in the `Subtotal:` line but not when a second number is appended?
