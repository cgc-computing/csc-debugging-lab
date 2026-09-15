# Day-to-Day Temperature Changes

**Course:** CSC205 &nbsp;|&nbsp; **Module 6:** Arrays, ArrayLists, Collections, and Iterators &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`printChanges` takes a week's temperature readings in a `vector<int>` and prints the change between each pair of consecutive days. A week with fewer than two readings has no changes to report and should simply print nothing.

## Expected Behavior

```
Week 1 changes:
  day 1 -> day 2: +3
  day 2 -> day 3: +4
  day 3 -> day 4: -1
  day 4 -> day 5: -4
  day 5 -> day 6: -4
  day 6 -> day 7: +3
Week 2 changes:
Week 3 changes:
Done.
```

## How to Run

Build with the address sanitizer enabled so that any invalid memory access is reported clearly:

```bash
g++ -std=c++17 -Wall -fsanitize=address -o daily_changes daily_changes.cpp
./daily_changes
```
(on Windows: `daily_changes.exe` or `.\daily_changes.exe`; if your compiler does not support `-fsanitize=address`, omit that flag)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did.

## Think About

- What type does `size()` return? Can a value of that type ever be negative?
- Evaluate the loop condition by hand for a vector with 7 elements, then 1 element, then 0 elements. What is the value of `temps.size() - 1` in each case?
- How could you write "for every pair of neighbors" so that the arithmetic can never go below zero?
