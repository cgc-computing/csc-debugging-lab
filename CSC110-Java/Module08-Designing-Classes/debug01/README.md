# Course Rosters

**Course:** CSC110 &nbsp;|&nbsp; **Module 8:** Designing Classes &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

A `Course` object has a `Roster` object (aggregation: a course *has a* roster). `Roster` keeps the enrolled names and a count. `CourseTester` creates two course sections, enrolls three students in CSC110 and two in CSC205, and prints both rosters and the total enrollment.

## Expected Behavior

```
CSC110 Intro to Programming -- 3 student(s): Ada, Grace, Linus
CSC205 Data Structures -- 2 student(s): Dennis, Barbara

Total enrollment across both sections: 5
```

## How to Run

```bash
javac *.java
java CourseTester
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the classes; the design is fine.

## Think About

- How many `Roster` objects exist while this program runs? How many *should* exist?
- When a `Roster` is passed to the `Course` constructor, what exactly is copied into the course's field: the roster's contents, or something else?
- Draw a picture of the objects and the arrows (references) between them just before the first `enroll` call.
