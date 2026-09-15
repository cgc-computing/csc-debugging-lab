# Part Number Lookup

**Course:** CSC205 &nbsp;|&nbsp; **Module 10:** Searching &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program keeps a sorted array of ten part numbers and uses binary search to look up six requested parts. For each request it prints the index where the part was found (or "not found") and how many array elements the search examined.

## Expected Behavior

All six requests finish immediately:

```
part 522: found at index 4 (1 comparisons)
part 104: found at index 0 (3 comparisons)
part 1073: found at index 9 (4 comparisons)
part 741: found at index 6 (4 comparisons)
part 300: not found (3 comparisons)
part 2000: not found (4 comparisons)
```

(A correct binary search over 10 elements never needs more than 4 comparisons.) If the program stops printing before all six lines appear and does not return to the prompt, it is stuck; stop it with Ctrl+C.

## How to Run

```bash
g++ -std=c++17 -Wall -o binary_search binary_search.cpp
./binary_search
```
(on Windows: `binary_search.exe` or `.\binary_search.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not replace the binary search with a linear scan.

## Think About

- After each comparison, write down the range of indices `[low, high]` that could still contain the target. Does the range get strictly smaller every time?
- For a `while` loop to finish, something in its condition has to change. Which variables change on each path through this loop body, and is there a path where nothing changes?
- The four successful searches behave normally. What is different about the path taken by a search for a value that is *not* in the array?
