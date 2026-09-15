# Score File Reader

**Course:** CSC110 &nbsp;|&nbsp; **Module 14:** File I/O &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The file `scores.txt` (provided in this folder) holds one student per line: a name and a
whole-number score. The program reads the file, prints each student, and reports how many
students there are and the class average.

## Expected Behavior

The program takes no keyboard input; it reads `scores.txt` from the current folder. With the
provided file, a correct run prints:

```
Ana: 88
Ben: 92
Chloe: 79
Dmitri: 95
Students: 4
Average: 88.5
```

## How to Run

Run the program from the folder that contains `scores.txt`:

```bash
g++ -std=c++17 -Wall -o score_reader score_reader.cpp
./score_reader
```

(on Windows: `score_reader.exe` or `.\score_reader.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not edit
`scores.txt`; the file is correct.

## Think About

- Open `scores.txt` in an editor and look at the very end of the file. What character comes after `95`?
- Exactly when does an input stream report that it has reached the end of the file: when the last value is read, or when a read *attempt* finds nothing?
- What happens to `name` and `score` when a read attempt fails? What values do they hold afterward?
- How many times should the loop body run for a four-line file? How many times does it actually run?
