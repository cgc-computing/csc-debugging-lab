# Quiz Score Selection Sort

**Course:** CSC205 &nbsp;|&nbsp; **Module 11:** Sorting &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program sorts seven quiz scores into ascending order using selection sort, reports how many swaps the sort performed, and checks the result.

## Expected Behavior

```
Before: 72 45 91 60 88 45 30
After:  30 45 45 60 72 88 91
Swaps:  4
Sorted correctly.
```

Selection sort performs at most one swap per pass, so for 7 values it can never report more than 6 swaps.

## How to Run

```bash
g++ -std=c++17 -Wall -o selection_sort selection_sort.cpp
./selection_sort
```
(on Windows: `selection_sort.exe` or `.\selection_sort.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep it a selection sort.

## Think About

- In selection sort, what is the inner loop's only job? What should happen *after* the inner loop finishes, and how many times per pass?
- Trace the first pass by hand on `72 45 91 60 88 45 30`. Each time `minIndex` changes, write down what `a[minIndex]` holds immediately afterward. Is it still the smallest value seen so far?
- Why does the program report 15 swaps for seven values? What does that number tell you about where the swap happens?
