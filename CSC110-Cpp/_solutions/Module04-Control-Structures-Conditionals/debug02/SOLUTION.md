# Solution: Membership Discount

**Course/Module/Activity:** CSC110 · Module 4 Control Structures: Conditionals · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

Gold members receive the Silver discount:

```
Enter membership level (G/S/B): G
Enter the item price: 80
Discount rate: 10%
You pay: $72
```

`S`, `B`, and `X` all behave correctly. The program compiles with no warnings under `-Wall`.

## The Bug(s)

`member_discount.cpp`, `main`, the `switch`: `case 'G':` sets `discountRate = 0.20;` but has no
`break;`, so execution falls through into `case 'S':`.

## Why the Program Behaved Incorrectly

`case` labels are jump targets, not separate blocks. After `switch (level)` jumps to `case 'G'`
and executes `discountRate = 0.20;`, control simply continues to the next statement, which is
`discountRate = 0.10;` under `case 'S'`. That section does end with `break`, so the final value is
`0.10`. The other cases each end in `break` (or are last), so they are unaffected.

## The Concept This Illustrates

`switch` fall-through: every `case` section that should be independent must end with `break`.
Students often model `switch` as a list of exclusive branches like `if / else if`; C++ (like Java)
instead treats it as a labeled sequence of statements.

## The Correction

```cpp
// before
case 'G':
    discountRate = 0.20;
case 'S':
    discountRate = 0.10;
    break;

// after
case 'G':
    discountRate = 0.20;
    break;
case 'S':
    discountRate = 0.10;
    break;
```

## Instructor Notes

- Ask students to predict what would happen if the `break` after `case 'S'` were also removed
  (Gold and Silver would both become Bronze).
- Some students "fix" it by moving `case 'G'` to the bottom of the `switch`; that works only by
  accident. Ask them to explain the rule that makes it work.
- Follow-up: when is intentional fall-through useful (`case 'g': case 'G':` for accepting either
  case of the letter)? Mention that `[[fallthrough]];` documents it in modern C++.
