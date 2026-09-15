# Weekly Temperature Statistics

**Course:** CSC110 &nbsp;|&nbsp; **Module 9:** Introduction to Arrays &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads seven daily high temperatures into an array, then adds them up and prints the
total and the average.

## Expected Behavior

Sample run (the user types `72 75 71 68 70 74 77`):

```
Enter 7 daily high temperatures: 72 75 71 68 70 74 77
Total of highs: 507
Average high:   72.4286
```

## How to Run

For this activity, compile with the address sanitizer turned on. It makes the program report
memory mistakes clearly instead of printing unpredictable numbers:

```bash
g++ -std=c++17 -Wall -fsanitize=address -g -o temperature_stats temperature_stats.cpp
./temperature_stats
```

(on Windows: `temperature_stats.exe` or `.\temperature_stats.exe`; if your compiler does not
support `-fsanitize=address`, compile without it and expect the total to be off by an
unpredictable amount.)

Type seven whole numbers separated by spaces, for example `72 75 71 68 70 74 77`, and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- An array declared with size 7 has which valid index values? What is the largest one?
- How many times does each loop in the program execute? Should they execute the same number of times?
- What is stored in memory just past the end of an array, and what happens when a program reads it?
