# Quicksort With Lomuto Partition

**Course:** CSC310 &nbsp;|&nbsp; **Module 2:** Heaps, Priority Queues, and Quicksort &nbsp;|&nbsp; **Activity:** debug03
**Language:** Python 3

## Goal

`quicksort.py` implements QUICKSORT and PARTITION from CLRS Chapter 7 using inclusive indices `p`
and `r` and the last element as pivot. `main` sorts four lists and then shows the result of a single
partition on the textbook example so the pivot's final position can be inspected.

## Expected Behavior

```
[13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11]
  -> [2, 4, 5, 6, 7, 8, 9, 11, 12, 13, 19, 21]   correct: True
[2, 8, 7, 1, 3, 5, 6, 4]
  -> [1, 2, 3, 4, 5, 6, 7, 8]   correct: True
[10, 80, 30, 90, 40, 50, 70]
  -> [10, 30, 40, 50, 70, 80, 90]   correct: True
[3, 3, 1, 2, 3, 1]
  -> [1, 1, 2, 3, 3, 3]   correct: True

partition of [2, 8, 7, 1, 3, 5, 6, 4] with pivot 4:
  array [2, 1, 3, 4, 7, 5, 6, 8], pivot index 3, A[q] = 4
```

## How to Run

```bash
python3 quicksort.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the Lomuto
scheme; do not switch to Hoare partitioning or to `sorted`.

## Think About

- After PARTITION returns `q`, what must be true about `A[q]` relative to `A[p..q-1]` and
  `A[q+1..r]`? Check that claim against the partition output the program prints.
- Which element is deliberately *excluded* from both recursive calls, and why is it safe to exclude
  it? What happens if the excluded element is not the pivot?
- Two of the four lists sort correctly. Can you explain from the trace why those inputs are lucky?
