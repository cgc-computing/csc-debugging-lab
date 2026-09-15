# Solution: Split the Bill

**Course/Module/Activity:** CSC101 · Module 2 Data Types, Variables, and Expressions · debug02  
**Bug type(s):** logic (operator precedence)  
**Bug count:** 1

## Observed Behavior

```
Tip amount:       $12.00
Total with tip:   $72.00
Each person pays: $63.00
```

Tip and total are right; each person's share is far too high (four people paying $63 each is $252
for a $72 bill).

## The Bug(s)

`split_bill.py`, line 10: `share = subtotal + tip / people`. Division binds tighter than
addition, so only the *tip* is divided by the number of people, and the whole subtotal is then
added to that.

## Why the Program Behaved Incorrectly

Python evaluates `tip / people` first (12 / 4 = 3.0), then `subtotal + 3.0` = 63.0. The
programmer meant "(subtotal plus tip), divided by people," but wrote the expression without the
parentheses that force that grouping.

## The Concept This Illustrates

Operator precedence in arithmetic expressions: `*` and `/` are evaluated before `+` and `-`, and
parentheses are how you override that order. Also: reuse of an already-computed value (`total`)
avoids the problem entirely.

## The Correction

```python
# before
share = subtotal + tip / people
# after
share = (subtotal + tip) / people      # or:  share = total / people
```

## Instructor Notes

* Ask students to compute the share by hand *before* they look at the code; it makes the $63
  jump out.
* Both corrections above are acceptable. Prefer `total / people` and ask why using the variable
  you already computed is less error-prone.
* Some students "fix" the output by changing `tip` or `total` lines; verify all three lines.
