# Class Roster With a Vector

**Course:** CSC110 &nbsp;|&nbsp; **Module 10:** More About Arrays &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program asks how many students there are, reads each student's name and score, stores them
as `Student` objects in a `vector`, and then prints a numbered roster and the class average.

## Expected Behavior

Sample run (the user types `3`, then `Ana 90`, `Ben 84`, `Chloe 96`):

```
How many students? 3
Name and score: Ana 90
Name and score: Ben 84
Name and score: Chloe 96

Roster (3 students)
1. Ana - 90
2. Ben - 84
3. Chloe - 96
Class average: 90
```

## How to Run

```bash
g++ -std=c++17 -Wall -o class_roster class_roster.cpp
./class_roster
```

(on Windows: `class_roster.exe` or `.\class_roster.exe`)

Type `3` and press Enter, then type one student per line as a name and a score, for example
`Ana 90`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Keep using a `vector`.

## Think About

- What does `vector<Student> roster(count);` create? How many elements does the vector hold right after that line?
- What does `push_back` do to a vector's size? Does every way of putting an element into a vector change its size?
- Where do the extra roster entries come from, and which constructor produced them?
