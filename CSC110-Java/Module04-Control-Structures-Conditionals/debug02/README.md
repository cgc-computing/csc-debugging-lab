# Shipping Cost Calculator

**Course:** CSC110 &nbsp;|&nbsp; **Module 4:** Control Structures: Conditionals &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

The program computes the cost to ship a package. A flat rate depends on the shipping zone: zone 1 is $5.00, zone 2 is $8.50, and zone 3 is $12.00. Any other zone number prints a warning and uses the zone 2 rate. On top of the flat rate, the package costs $0.50 per pound.

## Expected Behavior

For a 3-pound package to zone 1:

```
Shipping zone (1, 2, or 3): 1
Package weight in pounds: 3

Flat rate:   $5.00
Weight fee:  $1.50
Total:       $6.50
```

For zone 2 the flat rate should be $8.50, for zone 3 it should be $12.00, and only an invalid zone such as 7 should produce the "Unknown zone" message.

## How to Run

```bash
javac ShippingCost.java
java ShippingCost
```

Type the zone number and press Enter, then the weight and press Enter. Use `1` and `3` to reproduce the sample run, then try zones 2, 3, and 7.

## Your Task

Run the program for each zone and compare the results with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- When a `switch` matches a `case` label, where does execution start, and where does it stop?
- For zone 1, which statements inside the `switch` actually run? Trace it by hand before you run it.
- Why does the "Unknown zone" message appear even for a valid zone?
