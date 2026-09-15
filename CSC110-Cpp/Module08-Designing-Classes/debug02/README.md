# Student Record Summary

**Course:** CSC110 &nbsp;|&nbsp; **Module 8:** Designing Classes &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`Student` stores a name, ID number, and GPA, with getters and a range-checked `setGpa`. A free
function `printSummary` takes a `const Student&` and prints the student on one line. The program
creates two students, prints them, updates one GPA, and prints again.

## Expected Behavior

The program takes no input. A correct build compiles with no errors and prints:

```
Ana Ruiz (ID 1001) - GPA 3.7
Ben Okafor (ID 1002) - GPA 3.2
Ben Okafor (ID 1002) - GPA 3.5
```

## How to Run

```bash
g++ -std=c++17 -Wall -o student_record student_record.cpp
./student_record
```

(on Windows: `student_record.exe` or `.\student_record.exe`)

Read the compiler output carefully before trying to run.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not change
`printSummary`'s parameter; taking the student by `const` reference is the intended design.

## Think About

- What promise does `const Student& s` make about `s` inside `printSummary`?
- Which methods of `Student` is the compiler willing to call on a `const` object? How does it know?
- Compare the three getters. What do two of them say that the third does not?
