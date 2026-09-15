# Class Score Report From CSV

**Course:** CSC205 &nbsp;|&nbsp; **Module 4:** File I/O and Exceptions &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`ScoreReport` reads `students.csv` (one header row, then `name,id,score` on each line), prints every student's id and score, and prints the class average. Lines whose numeric fields cannot be parsed should be reported and skipped rather than crashing the program.

## Expected Behavior

With the provided `students.csv`:

```
Alice Chen       1001   88
Brianna Ortiz    1002   92
Carlos Diaz      1003   75
Dana Whitfield   1004   95
Class average: 87.5
```

## How to Run

Run from the directory that contains `students.csv`:

```bash
javac ScoreReport.java
java ScoreReport
```

## Your Task

Run the program and compare its output with the Expected Behavior. Open `students.csv` in a text editor and look at it closely. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The program's structure (read, parse, accumulate, average) is fine.

## Think About

- When `Integer.parseInt` throws, which statements in the loop body still execute, and with what values?
- What does `" 92"` (with a leading space) parse to, and what should the program do about it?
- Is silently catching an exception ever the right choice? What should the user see when a line cannot be parsed?
