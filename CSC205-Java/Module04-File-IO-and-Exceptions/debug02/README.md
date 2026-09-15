# Letter Grade Report Writer

**Course:** CSC205 &nbsp;|&nbsp; **Module 4:** File I/O and Exceptions &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`GradeReport` converts each student's score to a letter grade and writes one line per student to `report.txt`. A score outside 0–100 causes a custom `InvalidScoreException`; that student is reported on the console and skipped. After writing, the program reads `report.txt` back and prints its contents.

## Expected Behavior

```
Skipping Dana Whitfield: score 105 is out of range
Report saved to report.txt
Contents of report.txt:
Alice Chen: 88 (B)
Brianna Ortiz: 92 (A)
Carlos Diaz: 75 (C)
Evan Park: 64 (D)
```

Opening `report.txt` in an editor afterwards should show the same four lines.

## How to Run

```bash
javac *.java
java GradeReport
```

## Your Task

Run the program and compare its output with the Expected Behavior. Also open `report.txt` after the run. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The exception design (custom exception, skip-and-continue) is intentional and correct.

## Think About

- When `out.println(...)` runs, is the text guaranteed to be in the file on disk at that moment? Where might it be instead?
- What has to happen to a `PrintWriter` before another part of the program can rely on the file's contents?
- Which Java construct guarantees that a resource is released even if an exception is thrown partway through?
