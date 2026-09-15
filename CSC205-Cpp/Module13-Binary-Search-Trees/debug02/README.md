# Member ID Lookup

**Course:** CSC205 &nbsp;|&nbsp; **Module 13:** Binary Search Trees &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`MemberTree` stores member ID numbers in a binary search tree (duplicates are ignored). The driver adds eight IDs, prints the members in order with a count, and then checks six IDs to report whether each is a member.

## Expected Behavior

```
Members (7): 1200 2500 3300 5000 6100 7500 9000 
ID 5000: member
ID 3300: member
ID 9000: member
ID 1200: member
ID 4000: not a member
ID 8000: not a member
```

(The members line ends with a trailing space; that is fine.)

## How to Run

```bash
g++ -std=c++17 -Wall -o bst_contains bst_contains.cpp
./bst_contains
```
(on Windows: `bst_contains.exe` or `.\bst_contains.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did.

## Think About

- The in-order print proves all seven IDs are stored. What does that tell you about which part of the class to suspect?
- Trace `isMember(5000)` by hand: the root holds 5000. Which branch of the `if` / `else if` / `else` in `contains` runs, and where does the search go next?
- Under what condition can the final `else` branch of `contains` ever execute?
