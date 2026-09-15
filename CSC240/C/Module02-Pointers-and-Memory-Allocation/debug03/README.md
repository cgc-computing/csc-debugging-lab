# Grade Book

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Pointers and Memory Allocation &nbsp;|&nbsp; **Activity:** debug03
**Language:** C (C11)

## Goal

`main` starts with an empty score list. It calls `load_scores`, which allocates an array on the heap, fills it with seven exam scores, and reports how many there are. `main` then prints the scores, their average, and how many meet the passing mark of 70, and frees the array.

## Expected Behavior

```
Loaded 7 scores
Scores: 88 62 95 74 70 59 81
Average: 75.57
Passing: 5 of 7
```

## How to Run

```bash
gcc -std=c11 -Wall -o grade_book grade_book.c
./grade_book
```

(on Windows: `grade_book.exe` or `.\grade_book.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `load_scores` as a function that fills in both results for its caller; you may change its parameter types.

## Think About

- The count comes back correctly but the scores do not. What is different about how the two results are handed back to `main`?
- `scores` in `main` is a pointer. If a function is supposed to *change that pointer*, what must the function receive?
- After `load_scores` returns, what value does `main`'s `scores` variable hold? What happens when the program then indexes it?
