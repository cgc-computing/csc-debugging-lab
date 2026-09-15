# Help-Desk Ticket Numbers

**Course:** CSC110 &nbsp;|&nbsp; **Module 7:** Writing Classes &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The `Ticket` class hands out sequential ID numbers: the first ticket created is #1, the second #2,
and so on. The class also keeps a count of how many tickets have been issued in total. The test
program creates three tickets and prints their IDs, subjects, and the running count.

## Expected Behavior

The program takes no input. A correct run prints:

```
#1: Printer jam in room 204
#2: Password reset
#3: Monitor flickers
Tickets issued so far: 3
```

## How to Run

```bash
g++ -std=c++17 -Wall -o ticket ticket.cpp
./ticket
```

(on Windows: `ticket.exe` or `.\ticket.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- How many copies of `ticketsIssued` exist while the program runs? How many copies of `subject`?
- Which pieces of information belong to *each ticket*, and which belong to *the class as a whole*?
- When `t2` is constructed, what value does `ticketsIssued` have before the increment, and why?
