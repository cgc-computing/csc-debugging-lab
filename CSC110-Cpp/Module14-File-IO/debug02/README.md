# Grade Report Writer

**Course:** CSC110 &nbsp;|&nbsp; **Module 14:** File I/O &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads names and scores from `scores.txt` (provided in this folder), assigns each
student a letter grade, and writes a report to a new file `report.txt`: a header line followed by
one line per student. When it finishes, it displays the contents of `report.txt` on the screen so
you can check the result without opening the file.

## Expected Behavior

The program takes no keyboard input; it reads `scores.txt` from the current folder and creates
(or replaces) `report.txt` in the same folder. A correct run prints:

```
Report written to report.txt

--- report.txt ---
Name Score Grade
Ana 88 B
Ben 92 A
Chloe 79 C
Dmitri 95 A
```

Running the program a second time produces exactly the same report.

## How to Run

Run the program from the folder that contains `scores.txt`:

```bash
g++ -std=c++17 -Wall -o grade_report grade_report.cpp
./grade_report
```

(on Windows: `grade_report.exe` or `.\grade_report.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not edit
`scores.txt`; the file is correct.

## Think About

- What happens to a file's existing contents when a program opens it for output? Is that always what you want?
- How many times is `report.txt` opened during one run of the program? What is in the file after each of those opens?
- The header line is written first. Why does it not appear in the finished report?
- After you fix the program, run it twice in a row. Does the report still match the Expected Behavior? Why should it?
