# Solution: Checking Account With Overdraft

**Course/Module/Activity:** CSC205 · Module 2 Inheritance and Object-Oriented Design · debug02
**Bug type(s):** conceptual/design, logic
**Bug count:** 1

## Observed Behavior

The first withdrawal is approved but the reported balance never moves, and the second withdrawal (which the overdraft limit should allow) is declined:

```
Opening balance: $100.00
After deposit of $50.00: $150.00
Withdraw $80.00: approved
Balance now: $150.00
Withdraw $150.00: declined
Balance now: $150.00
```

## The Bug(s)

`CheckingAccount.java` declares its own field `private double balance;`, which *shadows* the `balance` inherited from `BankAccount`. The overridden `withdraw` reads and writes the subclass copy (which starts at `0.0`), while the constructor, `deposit`, and `getBalance` all use the superclass copy.

## Why the Program Behaved Incorrectly

A `CheckingAccount` object holds two independent `balance` fields. `super(owner, 100.00)` and `deposit(50.00)` put `150.0` in `BankAccount.balance`. `CheckingAccount.withdraw(80.00)` tests `80 <= 0.0 + 100.0` against the shadow copy, approves, and sets the shadow copy to `-80.0`; `getBalance()` still returns the untouched `150.0`. The second call tests `150 <= -80.0 + 100.0`, which is false, so a withdrawal that the real balance (`70 + 100` of headroom) would allow is declined.

## The Concept This Illustrates

Field shadowing versus method overriding. Methods are overridden through dynamic dispatch, but fields are not: a same-named field in a subclass is a second, unrelated variable. Students typically add such a field because the compiler rejected access to the superclass's `private` field. Module 2's lesson is that `protected` (or a protected setter) is how a superclass deliberately shares state with its subclasses.

## The Correction

```java
// BankAccount.java  (before)
private double balance;
// after
protected double balance;

// CheckingAccount.java: delete the line
private double balance;
```

## Instructor Notes

- Helpful experiment: temporarily make the superclass field `protected` and print `super.balance` and `this.balance` inside the subclass's `withdraw`. Students see the two copies side by side.
- Alternative acceptable fix: keep `balance` private and add `protected void setBalance(double b)` in `BankAccount`, with the subclass using `getBalance()`/`setBalance(...)`. Arguably better encapsulation; accept either as long as the shadow field is removed.
- A common non-fix is changing the *subclass* field to `protected`. Ask why that cannot help.
- Ask: "If you delete the subclass field without changing the superclass, what does the compiler say, and what is it telling you about the design?"
