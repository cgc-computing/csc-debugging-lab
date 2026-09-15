# Solution: Bank Account

**Course/Module/Activity:** CSC101 · Module 11 Classes and Objects · debug01  
**Bug type(s):** conceptual/design (instance attribute vs. local variable) / logic  
**Bug count:** 1

## Observed Behavior

```
Jordan: $50.00
Deposited $25.00
Insufficient funds.
Jordan: $50.00
```

The deposit is announced but never takes effect; the withdrawal is then refused.

## The Bug(s)

`bank_account.py`, line 11: `balance = self.balance + amount` assigns to a *local variable*
named `balance` instead of the attribute `self.balance`. The local disappears when `deposit`
returns; the object's balance is unchanged.

## Why the Program Behaved Incorrectly

`self.balance` is read correctly (50.0), 25.0 is added, and the result 75.0 is stored in a
variable that exists only during this call. Nothing writes back to the object. `withdraw` then
sees `self.balance == 50.0`, and 60 > 50, so it prints "Insufficient funds."

## The Concept This Illustrates

Object state lives in attributes accessed through `self`. A bare name inside a method is a
temporary local, exactly as in an ordinary function. Forgetting `self.` is the object-oriented
version of the Module 9 scope lesson.

## The Correction

```python
# before
        balance = self.balance + amount
# after
        self.balance = self.balance + amount      # or: self.balance += amount
```

## Instructor Notes

* Ask students to add `print(self.balance)` at the end of `deposit` in the original. Seeing
  50.0 there while the message said "Deposited $25.00" is the aha moment.
* Point out that `withdraw` is written correctly and sits right below; comparing the two methods
  is usually enough for students to find it.
* Follow-up: should `deposit` reject negative amounts? Where would that check go?
