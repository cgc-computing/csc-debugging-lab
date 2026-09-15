# Bank Account

**Course:** CSC101 &nbsp;|&nbsp; **Module 11:** Classes and Objects &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

`BankAccount` stores an owner and a balance. `deposit` adds money, `withdraw` removes money if
there is enough, and printing the account shows the owner and current balance. The test code opens
an account with $50, deposits $25, and withdraws $60.

## Expected Behavior

```
Jordan: $50.00
Deposited $25.00
Withdrew $60.00
Jordan: $15.00
```

## How to Run

```bash
python3 bank_account.py
```

No input is required.

## Your Task

Run the program and compare with the Expected Behavior. This program contains one or more bugs.
Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original
version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

* Inside a method, what is the difference between a plain variable and an attribute written with
  `self.`? Where does each one live, and how long does it last?
* After `deposit` finishes, what should `account.balance` be? Add a temporary `print` after the
  deposit to check.
* Compare how `deposit` and `withdraw` update the balance. What is different about the two?
