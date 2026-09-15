# Race Time Merge Sort

**Course:** CSC205 &nbsp;|&nbsp; **Module 11:** Sorting &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program sorts eight race finishing times (in seconds) into ascending order using top-down merge sort: split the range in half, sort each half recursively, then merge the two sorted halves. It prints the result of every merge so the recursion can be followed, then prints the fully sorted list.

## Expected Behavior

```
Before: 301 412 350 377 388 520 399 455
  merged [0..1]: 301 412
  merged [2..3]: 350 377
  merged [0..3]: 301 350 377 412
  merged [4..5]: 388 520
  merged [6..7]: 399 455
  merged [4..7]: 388 399 455 520
  merged [0..7]: 301 350 377 388 399 412 455 520
After:  301 350 377 388 399 412 455 520
```

Every value from the input appears exactly once in the output, and each `merged` line contains exactly the values that were in that range before the merge.

## How to Run

```bash
g++ -std=c++17 -Wall -o merge_sort merge_sort.cpp
./merge_sort
```
(on Windows: `merge_sort.exe` or `.\merge_sort.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The recursive splitting is correct; study what happens when two sorted halves are combined.

## Think About

- When the main loop in `merge` stops, what do you know about `i` and `j`? Is it possible that *both* halves still have elements left? That exactly one does? Which one can it be?
- Compare the input with the output: one value is missing and another appears twice. Where did the missing value go, and where did the extra copy come from?
- Trace the merge of `301 412` with `350 377` by hand, writing down `i`, `j`, and the contents of `merged` after each step. How many values should `merged` hold when it is copied back, and how many does it actually hold?
- The two-element merges all come out right. What is different about the ranges whose `merged` line does not match the Expected Behavior?
