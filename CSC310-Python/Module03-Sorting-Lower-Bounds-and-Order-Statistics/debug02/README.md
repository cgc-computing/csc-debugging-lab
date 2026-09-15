# Randomized Select

**Course:** CSC310 &nbsp;|&nbsp; **Module 3:** Sorting Lower Bounds and Order Statistics &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`randomized_select.py` implements RANDOMIZED-SELECT from CLRS Section 9.2: it finds the *i*-th
smallest element (counting from 1) of a list in expected linear time by partitioning around a random
pivot and recursing into one side only. The random generator is seeded so every run is identical.
`main` asks for every order statistic of a ten-element list and compares each with the sorted list.

## Expected Behavior

```
data  : [12, 3, 5, 7, 4, 19, 26, 1, 8, 15]
sorted: [1, 3, 4, 5, 7, 8, 12, 15, 19, 26]

   1-th smallest:   1   expected   1   ok
   2-th smallest:   3   expected   3   ok
   3-th smallest:   4   expected   4   ok
   4-th smallest:   5   expected   5   ok
   5-th smallest:   7   expected   7   ok
   6-th smallest:   8   expected   8   ok
   7-th smallest:  12   expected  12   ok
   8-th smallest:  15   expected  15   ok
   9-th smallest:  19   expected  19   ok
  10-th smallest:  26   expected  26   ok

all order statistics correct: True
median (i = (n+1)//2): 7
```

## How to Run

```bash
python3 randomized_select.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not sort the
list; the point is to select without sorting.

## Think About

- After partitioning `A[p..r]` around a pivot that lands at index `q`, how many elements are in
  `A[p..q]`, pivot included? Write the formula and test it with `p = 0, q = 0`.
- If the pivot turns out to be the *k*-th smallest of the current sub-list and you need the *i*-th
  smallest with `i > k`, what rank are you looking for in the right-hand side?
- Look at the pattern of wrong answers. Is each answer random, or is there a consistent relationship
  between what you got and what you expected? What does that suggest?
