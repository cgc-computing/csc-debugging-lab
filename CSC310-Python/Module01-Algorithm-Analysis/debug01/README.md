# Insertion Sort With a Comparison Counter

**Course:** CSC310 &nbsp;|&nbsp; **Module 1:** Algorithm Analysis &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`insertion_sort.py` implements INSERTION-SORT from CLRS Chapter 2 on a 0-based Python list, counts
the key comparisons it performs, and reports the counts for an already-sorted and a reverse-sorted
input of size 8 so they can be checked against the Θ(n) best case and Θ(n²) worst case.

## Expected Behavior

```
[5, 2, 4, 6, 1, 3] -> [1, 2, 3, 4, 5, 6]
   sorted correctly: True   comparisons: 12
[31, 41, 59, 26, 41, 58] -> [26, 31, 41, 41, 58, 59]
   sorted correctly: True   comparisons: 9
[3, 1, 2] -> [1, 2, 3]
   sorted correctly: True   comparisons: 3
[9, 8, 7, 6, 5, 4, 3, 2, 1] -> [1, 2, 3, 4, 5, 6, 7, 8, 9]
   sorted correctly: True   comparisons: 36

Comparison counts by input shape (n = 8):
   already sorted : 7   (expected n-1 = 7)
   reverse sorted : 28   (expected n(n-1)/2 = 28)
```

## How to Run

```bash
python3 insertion_sort.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
algorithm as insertion sort; do not call `sorted` or `list.sort` inside `insertion_sort`.

## Think About

- CLRS writes the loop for 1-based arrays. When you translate `A[1..n]` to a Python list, what is the
  smallest index the inner loop must be allowed to examine?
- Trace the run on `[3, 1, 2]` by hand. Which element never moves, and why?
- The loop invariant says that before each outer iteration, `A[0..j-1]` is sorted. Is that invariant
  actually maintained by the code as written? Where does it break?
