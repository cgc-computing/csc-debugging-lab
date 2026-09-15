# One-Pass Duplicate Removal

**Course:** CSC310 &nbsp;|&nbsp; **Module 1:** Algorithm Analysis &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`unique_stream.py` removes duplicate sensor readings while preserving the order of first
appearance. The header comment claims the function runs in O(n) time because each reading is examined
once. The `main` block checks the result on a small list and then times the function on n = 10 000 and
n = 20 000 readings so the claim can be tested empirically.

## Expected Behavior

The small example is correct and the running time grows *linearly*: doubling n should roughly double
the time (timings are noisy on such short runs, so anything near 2x is consistent with O(n)).

```
unique_in_order([4, 7, 4, 1, 7, 9, 1, 4]) = [4, 7, 1, 9]

n =  10000: 9995 unique readings, 0.001 s
n =  20000: 19995 unique readings, 0.002 s
time ratio (n doubled): 2.1x
```

The exact seconds will differ on your machine; the unique counts and the roughly 2x ratio should not.

## How to Run

```bash
python3 unique_stream.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. The output values
are already correct; your job is to make the running time match the O(n) claim without changing what
the function returns.

## Think About

- Each *line* inside the `while` loop runs n times. Does that make the loop O(n)? What is the cost of
  each individual operation on a Python list?
- Which list operations are O(1) and which are O(n)? Where would you look that up?
- If a run of 20 000 readings takes about four times as long as 10 000, what growth rate does that
  suggest, and which loop body operation(s) could produce it?
- What data structures give O(1) removal from the front and O(1) membership testing?
