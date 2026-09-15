# Temperature Statistics

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** Imperative Control Structures, Data Types, Structures, and Functions &nbsp;|&nbsp; **Activity:** debug01
**Language:** C (C11)

## Goal

The program asks how many temperature readings there are, reads that many whole-degree values, and prints the count, the minimum, the maximum, and the average of the readings.

## Expected Behavior

```
How many readings? 5
Enter 5 readings: 72 65 80 58 91
Count:   5
Minimum: 58
Maximum: 91
Average: 73.2
```

If the count is not between 1 and 100 the program prints a short message and exits.

## How to Run

```bash
gcc -std=c11 -Wall -o temperature_stats temperature_stats.c
./temperature_stats
```

(on Windows: `temperature_stats.exe` or `.\temperature_stats.exe`)

When prompted, type `5`, press Enter, then type `72 65 80 58 91` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- Read the compiler's output carefully before you run the program. Does it say anything you would not have seen from a Java compiler?
- `scanf` has to change the value of a variable that lives in `main`. How can a function you call possibly modify one of *your* variables in C?
- What does `scanf` receive as its second argument in this program, and what does it do with it?
