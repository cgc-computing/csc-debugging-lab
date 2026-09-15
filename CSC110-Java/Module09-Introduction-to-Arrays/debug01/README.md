# Quiz Score Statistics

**Course:** CSC110 &nbsp;|&nbsp; **Module 9:** Introduction to Arrays &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program stores five quiz scores in an array and prints how many scores there are, their total, and their average.

## Expected Behavior

```
Number of scores: 5
Total:   438
Average: 87.6
```

## How to Run

```bash
javac ScoreStats.java
java ScoreStats
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- If an array has 5 elements, what are the valid index values? What is `scores.length`?
- Read the exception message carefully. Which index did the program try to use, and why is that a problem?
- How many times should the loop body run for this array? How many times does it try to run?
