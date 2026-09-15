# CSV Grade Report

**Course:** CSC205 &nbsp;|&nbsp; **Module 4:** File I/O and Exceptions &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads `students.csv` (one header row, then `name,exam1,exam2,exam3` per line), prints each student's exam average, and prints a warning for any record whose scores cannot be parsed. A bad record must not appear in the report or be counted.

## Expected Behavior

With the provided `students.csv` (Dana's row has an empty second score):

```
Alice: 91.6667
Bob: 75
Carol: 86.3333
Warning: bad record for Dana, skipping.
Evan: 70
4 students reported.
```

## How to Run

Run from the directory that contains `students.csv`.

```bash
g++ -std=c++17 -Wall -o grade_report grade_report.cpp
./grade_report
```
(on Windows: `grade_report.exe` or `.\grade_report.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The data file is correct as given; do not edit it.

## Think About

- After a `catch` block finishes, where does execution go next?
- Which exam scores are in the `scores` array at the moment Dana's average is printed? Where did they come from?
- What does "handling" an exception mean for this loop: recovering and continuing with *this* record, or moving on to the *next* one?
