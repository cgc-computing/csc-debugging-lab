# Quiz Average with a Sentinel

**Course:** CSC110 &nbsp;|&nbsp; **Module 5:** Control Structures: Loops &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

The program reads quiz scores one per line until the user types `-1`. The `-1` is a sentinel that means "no more scores" and is not itself a score. The program then reports how many scores were entered, their total, and their average.

## Expected Behavior

```
Enter quiz scores one per line. Enter -1 to finish.
Score: 80
Score: 90
Score: 100
Score: -1

Scores entered: 3
Total points:   270
Average:        90.00
```

If the very first entry is `-1`, the program should print `No scores were entered.`

## How to Run

```bash
javac SentinelAverage.java
java SentinelAverage
```

Type each score and press Enter; type `-1` and press Enter to finish. Use `80`, `90`, `100`, `-1` to reproduce the sample run.

## Your Task

Run the program with the sample scores and compare the report with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. You may restructure the loop if you need to.

## Think About

- After the user types `-1`, which statements in the loop body still execute before the loop condition is tested?
- What should be true about a value *before* it is added to the running total?
- What is the difference between testing a condition at the top of a loop and testing it at the bottom? Which one fits sentinel-controlled input?
