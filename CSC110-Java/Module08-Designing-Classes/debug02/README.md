# Duplicate Student Checker

**Course:** CSC110 &nbsp;|&nbsp; **Module 8:** Designing Classes &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`Student` stores a name and a numeric ID and defines `equals` so that two students are equal when both the name and the ID match. `DuplicateChecker` reads two student records from the keyboard and reports whether they describe the same student.

## Expected Behavior

```
First student's name: Ada Lovelace
First student's ID: 1815
Second student's name: Ada Lovelace
Second student's ID: 1815

Record A: Ada Lovelace (#1815)
Record B: Ada Lovelace (#1815)
These records describe the SAME student.
```

If either the name or the ID differs, the program should report `DIFFERENT students`.

## How to Run

```bash
javac *.java
java DuplicateChecker
```

Type each value and press Enter. Enter `Ada Lovelace`, `1815`, `Ada Lovelace`, `1815` to reproduce the sample run.

## Your Task

Run the program with the sample input and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The tester is correct; look at the class.

## Think About

- What does it mean for two `String` variables to be "equal"? Is there more than one kind of equality for objects?
- The two names were typed separately by the user. Where in memory does each one live?
- `Student` has two fields of different types. Should a comparison of two students treat both fields the same way?
