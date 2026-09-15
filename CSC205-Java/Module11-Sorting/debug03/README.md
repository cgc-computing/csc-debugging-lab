# Merge Sort

**Course:** CSC205 &nbsp;|&nbsp; **Module 11:** Sorting &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

`MergeSort.sort` sorts an `int[]` using top-down merge sort: split the range in half, sort each half recursively, then merge the two sorted halves through a shared scratch array and copy the result back. `main` sorts three arrays chosen to exercise different merge situations.

## Expected Behavior

```
Before: [38, 27, 43, 3, 9, 82, 10]
After:  [3, 9, 10, 27, 38, 43, 82]
Pair:   [1, 2]
Halves: [1, 2, 3, 5, 6, 7]
```

## How to Run

```bash
javac MergeSort.java
java MergeSort
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The recursive splitting is correct; study what happens when two sorted halves are combined.

## Think About

- When the main merge loop stops, what do you know about `i` and `j`? Is it possible that *both* halves still have elements left? That exactly one does? Which one?
- Where do the zeros in the output come from? Nothing in the input is zero.
- Trace the merge of `[5, 6, 7]` with `[1, 2, 3]` by hand. After the main loop ends, what is still sitting in the right half, and what does the code do with it?
- Why does `[2, 1]` sort correctly while `[5, 6, 7, 1, 2, 3]` does not?
