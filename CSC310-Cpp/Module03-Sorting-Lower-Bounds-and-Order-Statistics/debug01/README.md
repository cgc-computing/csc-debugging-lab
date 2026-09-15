# LSD Radix Sort

**Course:** CSC310 &nbsp;|&nbsp; **Module 3:** Sorting Lower Bounds and Order Statistics &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program sorts non-negative integers with least-significant-digit radix sort. Each pass is a counting sort keyed on one decimal digit, and the passes run from the ones digit up to the highest digit present. The program prints the array after each pass so you can watch the order develop.

## Expected Behavior

```
input:         170 45 75 90 802 24 2 66 
after digit 1: 170 90 802 2 24 45 75 66 
after digit 10: 802 2 24 45 66 170 75 90 
after digit 100: 2 24 45 66 75 90 170 802 
sorted
```

## How to Run

```bash
g++ -std=c++17 -Wall -o radix_sort radix_sort.cpp
./radix_sort
```

(on Windows: `radix_sort.exe` or `.\radix_sort.exe`)

## Your Task

Run the program, compare each pass with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep counting sort as the per-digit routine.

## Think About

- After the ones-digit pass, 170 and 90 both have digit 0. In what order should they appear, and why does that order matter for the next pass?
- After the prefix sums, what does `count[d]` tell you about where elements with digit `d` belong? If two elements share a digit, which of them should take the higher slot?
- Radix sort is correct only if each digit pass is *stable*. Which line of the counting sort decides whether it is?
