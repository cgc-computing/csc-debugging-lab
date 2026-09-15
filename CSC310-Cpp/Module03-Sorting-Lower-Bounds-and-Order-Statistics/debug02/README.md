# Randomized Select

**Course:** CSC310 &nbsp;|&nbsp; **Module 3:** Sorting Lower Bounds and Order Statistics &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`randomizedSelect` implements RANDOMIZED-SELECT from CLRS 9.2: it finds the i-th smallest element (1-based, so i = 1 is the minimum) in expected linear time by partitioning around a random pivot and recursing into one side only. The driver checks its answers against a sorted copy of the data. The random generator uses a fixed seed, so every run is identical.

## Expected Behavior

```
data: 29 3 47 12 8 35 21 40 15 6 33 

i = 1:  select -> 3   (sorted[1] = 3)
i = 3:  select -> 8   (sorted[3] = 8)
i = 6:  select -> 21   (sorted[6] = 21)
i = 9:  select -> 35   (sorted[9] = 35)
i = 11:  select -> 47   (sorted[11] = 47)
```

## How to Run

```bash
g++ -std=c++17 -Wall -o randomized_select randomized_select.cpp
./randomized_select
```

(on Windows: `randomized_select.exe` or `.\randomized_select.exe`)

## Your Task

Run the program, compare the selected values with the sorted reference, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The partition routine is the same one used in quicksort and is fine.

## Think About

- After `partition` returns `q`, how many elements of `a[p..r]` are ≤ the pivot, counting the pivot itself? Express that in terms of `p` and `q`.
- If the answer lies in the right-hand part, what rank does it have *within* that part?
- The reported values are all a little too large. What single quantity would push every answer in the same direction?
- Why does the last query behave differently from the others?
