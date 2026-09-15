# Student Enrollment

**Course:** CSC101 &nbsp;|&nbsp; **Module 11:** Classes and Objects &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

Each `Student` object keeps its own list of courses. `enroll` adds a course to that student,
`course_count` reports how many courses the student has, and printing a student shows the name,
count, and course list. The test code enrolls Ana in two courses and Ben in one.

## Expected Behavior

```
Ana is enrolled in 2 course(s): ['CSC101', 'MAT151']
Ben is enrolled in 1 course(s): ['ENG101']
```

## How to Run

```bash
python3 student.py
```

No input is required.

## Your Task

Run the program and compare with the Expected Behavior. This program contains one or more bugs.
Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original
version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

* Which attributes belong to *each* student object, and which belong to the `Student` class as a
  whole? Where is each kind created?
* Where in the class does `name` get attached to an individual student? Does `courses` get the
  same treatment?
* How many list objects does the original program create? Try `print(ana.courses is ben.courses)`.
