# Class Rosters

**Course:** CSC101 &nbsp;|&nbsp; **Module 4:** Lists, Tuples, Sets, and Dictionaries &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

Section B of a course starts with the same roster as Section A. The program makes a copy of
Section A's roster, replaces the first student in Section B with a transfer student, adds one more
student to Section B, and prints both rosters. Section A must be unchanged.

## Expected Behavior

```
Name of the student transferring into Section B: Maya

Section A: ['Ana', 'Ben', 'Chloe', 'Dev']
Section B: ['Maya', 'Ben', 'Chloe', 'Dev', 'Eli']
Section A has 4 students.
Section B has 5 students.
```

## How to Run

```bash
python3 roster.py
```

Type `Maya` and press Enter.

## Your Task

Run the program and compare both rosters with the Expected Behavior. This program contains one or
more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the
original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

* After `section_b = section_a`, how many list objects exist in memory? How many names refer to
  them?
* When you change `section_b[0]`, which list object is being changed?
* What are two different ways to create a *separate* list with the same contents as an existing
  one?
