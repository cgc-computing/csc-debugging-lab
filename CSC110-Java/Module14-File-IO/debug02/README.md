# Writing a Score Report

**Course:** CSC110 &nbsp;|&nbsp; **Module 14:** File I/O &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

The program reads the exam scores in `scores.txt` and writes a report to a new file `report.txt`: a heading, one line per score, and then the count and average. It prints one confirmation line to the screen.

## Expected Behavior

On the screen:

```
Report written to report.txt (6 scores).
```

And `report.txt` should contain:

```
Exam Score Report
=================
Score 1: 88
Score 2: 92
Score 3: 79
Score 4: 95
Score 5: 84
Score 6: 71

Scores:  6
Average: 84.83
```

## How to Run

```bash
javac ReportWriter.java
java ReportWriter
cat report.txt
```

(On Windows: `type report.txt`.) Run from this directory so that `scores.txt` is found. The program takes no keyboard input.

## Your Task

Run the program, then look at `report.txt` and compare it with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not edit `scores.txt`; the structure of the program is fine.

## Think About

- The confirmation message says six scores were processed, so the reading part worked. Where did the text that was "written" go?
- When you call `println` on a `PrintWriter`, does the text reach the disk immediately? What has to happen for it to get there?
- If a program writes text to a file and then ends, is the text guaranteed to be on disk? What could prevent it?
