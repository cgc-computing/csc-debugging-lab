# 0/1 Knapsack with a One-Dimensional Table

**Course:** CSC310 &nbsp;|&nbsp; **Module 9:** Dynamic Programming &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`knapsack` solves the 0/1 knapsack problem—each item may be taken at most once—using the space-saving version of the dynamic program: a single array `best[0..capacity]` where `best[w]` is the most value that fits in capacity `w` using only the items processed so far. After each item the driver prints the whole array so you can watch the table evolve, then reports the best value for two more instances.

## Expected Behavior

```
small items, capacity 5 (table shows best value for capacity 0..5)
  after pen: 0 2 2 2 2 2
  after book: 0 2 3 5 5 5
  after lamp: 0 2 3 5 6 7
  after radio: 0 2 3 5 6 7
best value: 7
small items, capacity 7
best value: 10
classic items, capacity 50
best value: 220
```

## How to Run

```bash
g++ -std=c++17 -Wall -o knapsack knapsack.cpp
./knapsack
```

(on Windows: `knapsack.exe` or `.\knapsack.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the one-dimensional table; do not switch to a two-dimensional one.

## Think About

- After only the pen (weight 1, value 2) has been considered, what is the most value you can carry with capacity 5 if you own exactly one pen? What does the printed table claim?
- When `best[w]` is updated for the current item, the formula reads `best[w - weight]`. Should that be the value from *before* this item was considered or the value *already updated* for this item? Which one does the program actually read, and why?
- The program is consistent—it solves *some* well-defined problem exactly. Which knapsack variant is it?
