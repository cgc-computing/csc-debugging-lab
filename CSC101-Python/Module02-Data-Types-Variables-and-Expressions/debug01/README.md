# Quiz Average Calculator

**Course:** CSC101 &nbsp;|&nbsp; **Module 2:** Data Types, Variables, and Expressions &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program asks for three quiz scores (whole numbers), adds them up, and prints the total and
the average rounded to two decimal places.

## Expected Behavior

```
Quiz Average Calculator
-----------------------
Enter the first quiz score: 85
Enter the second quiz score: 88
Enter the third quiz score: 92

Total points: 265
Average score: 88.33
```

## How to Run

```bash
python3 quiz_average.py
```

Type `85`, `88`, and `92`, pressing Enter after each.

## Your Task

Run the program with the sample scores and compare its output with the Expected Behavior. This
program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be
ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* What *type* of value does `input()` give back, no matter what the user types?
* What does the `+` operator do when both of its operands are that type?
* At what point in the program should a value be converted, and what happens if you convert it
  too late?
