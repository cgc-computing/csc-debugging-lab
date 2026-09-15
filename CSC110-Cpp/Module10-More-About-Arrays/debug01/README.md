# Theater Seating Chart

**Course:** CSC110 &nbsp;|&nbsp; **Module 10:** More About Arrays &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program stores a 3-row by 5-column seating chart in a 2-D array, where `1` means the seat is
taken and `0` means it is open. It prints a map of the room and then counts how many seats are
open.

## Expected Behavior

The program takes no input. A correct run prints:

```
Seating map (X = taken, . = open):
X . . X .
. . X X X
X X . . .
Open seats: 8 of 15
```

## How to Run

```bash
g++ -std=c++17 -Wall -o seating_chart seating_chart.cpp
./seating_chart
```

(on Windows: `seating_chart.exe` or `.\seating_chart.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- Count the open seats on the printed map by hand. Which seats does the program appear to miss?
- In a nested loop over a 2-D array, how many times should the inner body run in total? What bound controls each loop?
- The map prints correctly. What is different between the two nested loops in the program?
