# Exam Scores from a File

**Course:** CSC110 &nbsp;|&nbsp; **Module 14:** File I/O &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The file `scores.txt` in this directory contains exam scores, one per line. The program reads every score and prints how many there are, the highest, and the average.

## Expected Behavior

`scores.txt` contains six scores: 88, 92, 79, 95, 84, 71. A correct run prints:

```
Scores read: 6
Highest:     95
Average:     84.83
```

## How to Run

```bash
javac ScoreReader.java
java ScoreReader
```

Run from this directory so that `scores.txt` is found. The program takes no keyboard input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not edit `scores.txt`; the structure of the program is fine.

## Think About

- Read the exception and its stack trace. Which `Scanner` method threw, and what was it asked to do?
- The loop condition asks the `Scanner` one question, and the loop body asks it for something else. Are those two things the same?
- After the last number in the file has been read, what (if anything) is left in the file for the `Scanner` to see? Open `scores.txt` in an editor and press Ctrl+End.
