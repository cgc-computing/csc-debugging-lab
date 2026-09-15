# Sensor Report

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** C Preprocessor, User-Defined Types, and Modules &nbsp;|&nbsp; **Activity:** debug01
**Language:** C (C11)

## Goal

The program computes two things with the help of small preprocessor macros: the number of cells in a 2-cell-wide border around square plots of side 3, 5, and 10, and the peak value in a run of eight sensor readings delivered one at a time by `read_sensor()`.

## Expected Behavior

A border of width 2 around a side-3 plot is a 7-by-7 square minus the 3-by-3 interior, so 49 - 9 = 40 cells. The eight readings are 14, 27, 9, 31, 22, 18, 40, 5.

```
Border areas (width 2):
  side  3 ->  40 cells
  side  5 ->  56 cells
  side 10 ->  96 cells
Peak reading: 40
```

## How to Run

```bash
gcc -std=c11 -Wall -o sensor_report sensor_report.c
./sensor_report
```

(on Windows: `sensor_report.exe` or `.\sensor_report.exe`)

No input is required. To see what the preprocessor produces, try `gcc -E sensor_report.c | tail -40`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the macros as macros; do not turn them into functions.

## Think About

- A macro is not a function call. Write out, by hand, exactly what text `SQUARE(side + BORDER_WIDTH)` becomes after the preprocessor runs. Now apply C's precedence rules to that text.
- How many times does the text `read_sensor()` appear in the expansion of `peak = MAX(read_sensor(), peak);`? How many readings does one trip through the loop consume?
- Which readings does the buggy program actually compare, and why is its answer still a number that appears in the run?
