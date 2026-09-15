# Quiz Average With a Sentinel

**Course:** CSC110 &nbsp;|&nbsp; **Module 5:** Control Structures: Loops &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program reads quiz scores one per line until the user enters `-1`. The `-1` is a sentinel
that means "no more scores"; it is not itself a score. The program then reports how many scores
were entered and their average.

## Expected Behavior

Sample run (the user types `90`, `80`, `70`, then `-1`, pressing Enter after each):

```
Enter quiz scores one at a time. Enter -1 when finished.
90
80
70
-1
Scores entered: 3
Average: 80
```

If the user types `-1` first, the program prints `Scores entered: 0` and `No scores were entered.`

## How to Run

```bash
g++ -std=c++17 -Wall -o quiz_average quiz_average.cpp
./quiz_average
```

(on Windows: `quiz_average.exe` or `.\quiz_average.exe`)

Type each score and press Enter; finish with `-1`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- What should be true about `score` before it is added to `sum`?
- Trace the loop by hand for the sample input. What are `sum` and `count` after each pass?
- When the user enters `-1`, which statements in the loop body still run before the condition is checked?
- Does the program behave correctly when `-1` is the very first thing entered?
