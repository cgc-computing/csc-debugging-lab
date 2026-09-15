# Test Score Average

**Course:** CSC110 &nbsp;|&nbsp; **Module 2:** Data and Expressions &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program reads three whole-number test scores from the keyboard and prints the total points and the average score. The average should be shown with its decimal part.

## Expected Behavior

With the scores 88, 91, and 95, the total is 274 and the average is 91.333... A correct run looks like this (the user's typing is shown after each prompt):

```
Enter the first test score: 88
Enter the second test score: 91
Enter the third test score: 95

Total points: 274
Average score: 91.33333333333333
```

## How to Run

```bash
javac TestAverage.java
java TestAverage
```

Type three whole numbers, pressing Enter after each one. Use `88`, `91`, and `95` to reproduce the sample run.

## Your Task

Run the program with the sample scores and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- What is the type of each value in the expression that computes the average? What type is the result?
- Does storing a result in a `double` variable change how the arithmetic itself is performed?
- What would the program print if the three scores were 90, 90, and 91? Try it.
