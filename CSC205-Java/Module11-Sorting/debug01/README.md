# Selection Sort

**Course:** CSC205 &nbsp;|&nbsp; **Module 11:** Sorting &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`SelectionSort.sort` sorts an `int[]` in ascending order. On each pass it finds the smallest value in the unsorted portion and moves it to the front of that portion. `isSorted` is a simple checker used by `main`.

## Expected Behavior

```
Before: [29, 10, 14, 37, 13, 5]
After:  [5, 10, 13, 14, 29, 37]
Sorted? true
Small:  [1, 2, 3]  sorted? true
```

## How to Run

```bash
javac SelectionSort.java
java SelectionSort
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep it a selection sort: one swap per pass of the outer loop.

## Think About

- In selection sort, how many swaps should happen for each value of `i`? Count how many the program actually performs for the three-element array.
- What is `minIndex` supposed to refer to at the moment the swap happens? What is it referring to when the swap happens in this code?
- Trace `[3, 1, 2]` by hand, writing down the array after every swap. Where does the 2 end up, and why?
- Why does the smallest value still land in the right place even though the rest of the array is scrambled?
