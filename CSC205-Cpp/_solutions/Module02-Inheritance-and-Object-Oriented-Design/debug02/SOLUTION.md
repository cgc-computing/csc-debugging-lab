# Solution: Savings Account Interest

**Course/Module/Activity:** CSC205 · Module 2 Inheritance and Object-Oriented Design · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

```
Dana opens a savings account with $1000
After deposit:  $1200
After interest: $1200
```

The deposit is recorded but the interest never appears.

## The Bug(s)

`SavingsAccount` declares its own `double balance;` member even though it already inherits a `protected` `balance` from `Account`. Its constructor body (`balance = initial;`) and `addInterest()` operate on this second, derived-class copy.

## Why the Program Behaved Incorrectly

Each `SavingsAccount` object contains two separate `balance` fields: `Account::balance` and `SavingsAccount::balance`. Inside `SavingsAccount` member functions the unqualified name `balance` refers to the derived class's own member, which *hides* the inherited one. So:

- The `Account` constructor sets `Account::balance = 1000`; the derived constructor sets `SavingsAccount::balance = 1000`.
- `deposit(200)` is an `Account` method, so it adds to `Account::balance` → 1200.
- `addInterest()` is a `SavingsAccount` method, so it grows `SavingsAccount::balance` → 1050.
- `getBalance()` is an `Account` method and returns `Account::balance`, still 1200.

The interest went into a field nobody reads.

## The Concept This Illustrates

`protected` exists precisely so a derived class can use the base class's data without redeclaring it. Redeclaring a member with the same name does not "reconnect" to the inherited one; it creates a second member that shadows it. Students often carry over a mental model where a subclass must list all its fields, or they think of the derived declaration as "making the field accessible."

## The Correction

```cpp
// before
class SavingsAccount : public Account {
private:
    double interestRate;
    double balance;
public:
    SavingsAccount(...) : Account(ownerName, initial), interestRate(rate) {
        balance = initial;
    }

// after
class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(...) : Account(ownerName, initial), interestRate(rate) {}
```

## Instructor Notes

- A frequent "fix" is to override `getBalance()` in `SavingsAccount` to return the derived copy. Then the deposit disappears instead of the interest. Use this to show that patching the symptom moves the problem.
- Ask students to sketch the memory layout of one `SavingsAccount` object before and after the fix. Seeing two boxes labelled `balance` usually settles it.
- Follow-up: change `protected` to `private` in `Account` (after the fix) and read the compiler error with the class. Discuss why the base class author gets to decide.
- Some compilers warn about the shadowing with `-Wshadow`; `-Wall` does not include it. This is a good opportunity to mention that extra warning flags exist.
