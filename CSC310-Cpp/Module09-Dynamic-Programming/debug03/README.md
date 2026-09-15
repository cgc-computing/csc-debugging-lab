# Rod Cutting with Memoization

**Course:** CSC310 &nbsp;|&nbsp; **Module 9:** Dynamic Programming &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

`cutRod` solves the rod-cutting problem from CLRS 14.1 with top-down memoization: given a price for each piece length 1 through 10, find the maximum revenue obtainable from a rod of length `n` by cutting it into pieces (or not cutting it at all). It also records the first piece of an optimal cut so the full decomposition can be printed, and counts recursive calls to show that memoization keeps the work polynomial.

## Expected Behavior

Prices for lengths 1..10 are 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 (the textbook table). Rods longer than 10 must be cut.

```
length 1: revenue 1, pieces: 1   (2 calls)
length 2: revenue 5, pieces: 2   (4 calls)
length 3: revenue 8, pieces: 3   (7 calls)
length 4: revenue 10, pieces: 2 2   (11 calls)
length 7: revenue 18, pieces: 1 6   (29 calls)
length 10: revenue 30, pieces: 10   (56 calls)
length 13: revenue 38, pieces: 3 10   (86 calls)
```

## How to Run

```bash
g++ -std=c++17 -Wall -o rod_cutting rod_cutting.cpp
./rod_cutting
```

(on Windows: `rod_cutting.exe` or `.\rod_cutting.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the top-down memoized structure.

## Think About

- The memo table needs a value that means "not computed yet". What values can a revenue legitimately take, and can the program tell its sentinel apart from them?
- Every query reports exactly one call. What must have happened during that single call?
- Once the memo is working, check length 3 by hand: the options are one piece of 3, a 1 and a 2, or three 1s (the recurrence sees only the first cut and recurses on the rest). Which first-piece lengths should the loop try for `n = 3`, and how many does it actually try?
