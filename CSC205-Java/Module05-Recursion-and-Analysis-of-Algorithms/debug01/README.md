# Recursive Factorial

**Course:** CSC205 &nbsp;|&nbsp; **Module 5:** Recursion and Analysis of Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`factorial(n)` computes n! recursively using the definition n! = n × (n−1)! with 0! = 1. `main` prints the factorial of several small values.

## Expected Behavior

```
5! = 120
3! = 6
1! = 1
0! = 1
```

## How to Run

```bash
javac Factorial.java
java Factorial
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the solution recursive.

## Think About

- Trace `factorial(0)` by hand: what is the sequence of calls, and when does it stop?
- What is the mathematical definition of 0!, and does the code's stopping condition include it?
- What is the first sign, in the program's output, that a recursion is not reaching its base case?
