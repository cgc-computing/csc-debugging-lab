# LSD Radix Sort on Counting Sort

**Course:** CSC310 &nbsp;|&nbsp; **Module 3:** Sorting Lower Bounds and Order Statistics &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`radix_sort.py` sorts non-negative integers with least-significant-digit radix sort. Each pass is a
counting sort keyed on one decimal digit, built exactly as in CLRS Chapter 8 (count, prefix sums,
place). `main` shows the first pass on the textbook example, the fully sorted result, and a second
list of student ID numbers.

## Expected Behavior

```
input : [329, 457, 657, 839, 436, 720, 355]
pass 1: [720, 355, 436, 457, 657, 329, 839]
sorted: [329, 355, 436, 457, 657, 720, 839]
correct: True

student ids sorted: [1011, 1043, 1049, 2011, 2043, 2087, 3011, 3087]
correct: True
```

## How to Run

```bash
python3 radix_sort.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
counting-sort structure (count, prefix sums, place); do not replace it with `sorted(key=...)`.

## Think About

- After pass 1, 457 and 657 both have ones digit 7. In what relative order does the program
  place them, and in what relative order were they in the input?
- Radix sort only works if each pass is *stable*. Why does stability of the per-digit sort matter
  when you move on to the tens digit?
- After the prefix sums, `C[d]` is the number of elements with digit <= d. Which element with digit
  d should go into slot `C[d] - 1`, the first one you encounter in the input or the last one?
