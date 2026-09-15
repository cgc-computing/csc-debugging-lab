# Course Roster

**Course:** CSC110 &nbsp;|&nbsp; **Module 8:** Designing Classes &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

A `Course` object contains a `Roster` object (a "has-a" relationship). The program asks how many
students to enroll, reads each name, adds it to the course's roster, and finally prints the course
title, the enrollment count, and the list of names.

## Expected Behavior

Sample run (the user types `3`, then `Ana`, `Ben`, `Chloe`):

```
How many students to enroll? 3
Student name: Ana
Student name: Ben
Student name: Chloe

CSC110 - Introduction to C++
Enrolled: 3
Roster:   Ana, Ben, Chloe
```

## How to Run

```bash
g++ -std=c++17 -Wall -o course_roster course_roster.cpp
./course_roster
```

(on Windows: `course_roster.exe` or `.\course_roster.exe`)

Type `3` and press Enter, then type one name per line: `Ana`, `Ben`, `Chloe`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- When `getRoster()` is called, exactly what does it hand back to the caller — the course's roster, or something else?
- Which object actually receives the `add(name)` call? What happens to that object after the statement ends?
- How many `Roster` objects exist by the time the program prints its results?
- Whose responsibility should enrolling a student be: `main`, `Course`, or `Roster`?
