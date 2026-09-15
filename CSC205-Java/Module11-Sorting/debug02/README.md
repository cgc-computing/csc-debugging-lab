# Insertion Sort of Daily Temperatures

**Course:** CSC205 &nbsp;|&nbsp; **Module 11:** Sorting &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`InsertionSort.sort` sorts an `int[]` of temperatures in ascending order by taking each value in turn and sliding it left past every larger value already sorted. `main` sorts two small arrays and prints them before and after.

## Expected Behavior

```
Before: [72, 65, 80, 71, 68]
After:  [65, 68, 71, 72, 80]
Before: [58, 61, 49, 55, 44, 60]
After:  [44, 49, 55, 58, 60, 61]
```

## How to Run

```bash
javac InsertionSort.java
java InsertionSort
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The overall structure of the sort is correct.

## Think About

- When a new value is smaller than *everything* already sorted, how far left does it need to slide? What is `j` when the sliding stops?
- Java evaluates `&&` left to right and stops as soon as the answer is known. Which part of the loop condition is checked first here, and does the order matter?
- Read the exception message carefully: which index is being accessed, and by which expression?
- Would the crash still happen if the first value in the array were also the smallest?
