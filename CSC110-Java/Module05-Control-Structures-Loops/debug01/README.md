# Sum of the First n Numbers

**Course:** CSC110 &nbsp;|&nbsp; **Module 5:** Control Structures: Loops &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program reads a positive whole number *n* and adds up 1 + 2 + ... + *n* with a loop. As a check, it also computes the same sum with the formula *n*(*n*+1)/2 and reports whether the two agree.

## Expected Behavior

```
Enter a positive whole number: 10
Loop total:    55
Formula total: 55
The two totals agree.
```

For `1` both totals are 1; for `100` both are 5050.

## How to Run

```bash
javac SumToN.java
java SumToN
```

Type a whole number and press Enter. Use `10` to reproduce the sample run.

## Your Task

Run the program with a few values and compare the results with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- How many times should the loop body execute for n = 10? Count the actual iterations by hand.
- What is the value of the loop variable during the *last* iteration? What should it be?
- How much is the loop total off by, and what does that number tell you?
