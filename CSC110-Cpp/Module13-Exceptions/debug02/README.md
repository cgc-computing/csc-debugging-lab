# Bank Withdrawals

**Course:** CSC110 &nbsp;|&nbsp; **Module 13:** Exceptions &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program processes three withdrawal requests against a starting balance of $120. A request
that is not a positive amount is reported as an invalid amount. A request larger than the balance
is declined, and the message says how far short the account is. Any other problem is reported as
a generic transaction failure.

## Expected Behavior

The program takes no input. A correct run prints:

```
Starting balance: $120
Withdraw $40: OK, balance is now $80
Withdraw $-5: Invalid amount: Amount must be positive
Withdraw $500: Declined: Insufficient funds (short by $420)
Final balance: $80
```

## How to Run

```bash
g++ -std=c++17 -Wall -o bank_withdrawals bank_withdrawals.cpp
./bank_withdrawals
```

(on Windows: `bank_withdrawals.exe` or `.\bank_withdrawals.exe`)

Read any compiler messages carefully before running.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Keep all three
handlers; each one has a job to do.

## Think About

- When an exception is thrown, how does the program decide which `catch` block runs? Does it look at all of them, or stop at the first one that fits?
- `InsufficientFunds` inherits from `runtime_error`, which inherits from `exception`. Which of the three handlers is *able* to catch an `InsufficientFunds` object?
- The compiler printed a warning. What is it telling you about the two handlers that never run?
