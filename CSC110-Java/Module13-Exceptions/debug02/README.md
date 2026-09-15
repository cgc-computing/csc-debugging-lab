# Safe Integer Division

**Course:** CSC110 &nbsp;|&nbsp; **Module 13:** Exceptions &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

The program reads two whole numbers as text, converts them to `int`, and prints the quotient and remainder. If either entry is not a whole number it prints `Both entries must be whole numbers.`; if the divisor is zero it prints `Cannot divide by zero.`; any other unexpected problem prints a generic message. In every case the program finishes by printing `Done.`

## Expected Behavior

```
Dividend: 17
Divisor:  5
17 / 5 = 3 remainder 2
Done.
```

With a divisor of `0`:

```
Dividend: 17
Divisor:  0
Cannot divide by zero.
Done.
```

With a divisor of `five`:

```
Dividend: 17
Divisor:  five
Both entries must be whole numbers.
Done.
```

## How to Run

```bash
javac SafeDivider.java
java SafeDivider
```

Type each value and press Enter. Try the three sample pairs above: `17` and `5`, `17` and `0`, `17` and `five`.

## Your Task

Compile and run the program, and read carefully anything the compiler or the program tells you. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not remove any of the three handlers; each of the three messages must still be reachable.

## Think About

- Read the compiler message carefully. What does it mean for an exception to have "already been caught"?
- `NumberFormatException` and `ArithmeticException` are both kinds of `Exception`. When Java looks for a matching `catch` block, in what order does it check them, and when does it stop?
- If a handler for a general type comes first, can a handler for a more specific type ever run?
