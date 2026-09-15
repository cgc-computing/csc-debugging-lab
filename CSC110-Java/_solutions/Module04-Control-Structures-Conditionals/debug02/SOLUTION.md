# Solution: Shipping Cost Calculator

**Course/Module/Activity:** CSC110 · Module 4 Control Structures: Conditionals · debug02
**Bug type(s):** logic
**Bug count:** 1 (missing `break` in each of the three cases; one misconception)

## Observed Behavior

Every zone, valid or not, prints the warning and uses the $8.50 default rate:

```
Shipping zone (1, 2, or 3): 1
Package weight in pounds: 3
Unknown zone; using the zone 2 rate.

Flat rate:   $8.50
Weight fee:  $1.50
Total:       $10.00
```

## The Bug(s)

`ShippingCost.java`, in `main`, the `switch` has no `break` statements:

```java
switch (zone) {
    case 1:
        flatRate = 5.00;
    case 2:
        flatRate = 8.50;
    case 3:
        flatRate = 12.00;
    default:
        System.out.println("Unknown zone; using the zone 2 rate.");
        flatRate = 8.50;
}
```

## Why the Program Behaved Incorrectly

A `switch` jumps to the matching label and then executes *every* statement that follows, through the later labels, until it hits a `break` or the end of the block. For zone 1, `flatRate` is set to 5.00, then 8.50, then 12.00, then the `default` code prints the warning and sets it back to 8.50. The last assignment wins, so all zones end up identical.

## The Concept This Illustrates

Fall-through in the classic `switch` statement. Students coming from `if / else if` expect each `case` to be its own exclusive branch; in Java's traditional `switch`, exclusivity has to be requested with `break`.

## The Correction

```java
// after
switch (zone) {
    case 1:
        flatRate = 5.00;
        break;
    case 2:
        flatRate = 8.50;
        break;
    case 3:
        flatRate = 12.00;
        break;
    default:
        System.out.println("Unknown zone; using the zone 2 rate.");
        flatRate = 8.50;
}
```

## Instructor Notes

- Students who add a `break` only to `case 1` will see zone 1 work and may stop. Have them test zone 2.
- A `break` after `default` is harmless but unnecessary; discuss why.
- Java 14+ arrow-form `switch` (`case 1 -> flatRate = 5.00;`) has no fall-through. If a student rewrites in that form it is correct; ask them to explain what the arrow form does differently.
- Good discussion: is there ever a situation where fall-through is what you want? (Grouping several labels: `case 1: case 2: ...`.)
