# Class Roster

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** Imperative Control Structures, Data Types, Structures, and Functions &nbsp;|&nbsp; **Activity:** debug02
**Language:** C (C11)

## Goal

The program stores three course sections as `struct class_t` records (course code, students enrolled, capacity). It prints the sections, adds students to each one through a helper function, refuses an addition that would exceed capacity, and prints the sections again.

## Expected Behavior

```
--- Before ---
CSC110   18/24 enrolled,  6 seats open
CSC205   12/20 enrolled,  8 seats open
CSC240    9/16 enrolled,  7 seats open

--- Enrolling ---
Added 4 to CSC110
Cannot add 10 to CSC205: only 8 seats open
Added 5 to CSC240

--- After ---
CSC110   22/24 enrolled,  2 seats open
CSC205   12/20 enrolled,  8 seats open
CSC240   14/16 enrolled,  2 seats open
```

## How to Run

```bash
gcc -std=c11 -Wall -o class_roster class_roster.c
./class_roster
```

(on Windows: `class_roster.exe` or `.\class_roster.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the helper functions; you may change their signatures.

## Think About

- The "Enrolling" messages look right. What does that tell you about where the problem is *not*?
- In Java, passing an object to a method lets the method change that object. What exactly is copied when a `struct` is passed to a C function?
- How could a C function communicate an updated `struct` back to its caller using only what this module has covered?
