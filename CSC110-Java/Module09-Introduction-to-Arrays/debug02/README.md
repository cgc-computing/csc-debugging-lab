# Tallest Student

**Course:** CSC110 &nbsp;|&nbsp; **Module 9:** Introduction to Arrays &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

Two parallel arrays hold students' names and their heights in inches. The program prints every student's height and then announces the tallest student by name.

## Expected Behavior

```
Class heights:
  Jordan: 66 in
  Ines: 71 in
  Malik: 69 in
  Sofia: 74 in
  Chen: 68 in

Tallest student: Sofia at 74 inches
```

## How to Run

```bash
javac TallestStudent.java
java TallestStudent
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- The program keeps track of two things while it searches: the tallest height seen so far and *where* it was seen. Does it keep both of them up to date?
- What relationship should always hold between `tallestHeight` and `heights[tallestIndex]` at the end of the loop?
- Why do parallel arrays make the *index* of the maximum more important than the maximum value itself?
