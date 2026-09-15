# Class Sections

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** Functional Programming, Scheme Terminology, Data Types, and Lists &nbsp;|&nbsp; **Activity:** debug01
**Language:** Scheme (R5RS, DrRacket)

## Goal

Two lab sections are stored as lists of names. `merge-sections` should produce a single flat roster containing every name from the first section followed by every name from the second. `count-students` counts the names in a roster and `first-student` returns the first one.

## Expected Behavior

```scheme
> morning
(ana ben carlos)
> afternoon
(dee eli)
> (merge-sections morning afternoon)
(ana ben carlos dee eli)
> (count-students (merge-sections morning afternoon))
5
> (first-student (merge-sections morning afternoon))
ana
```

## How to Run

Open `class-sections.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (merge-sections morning afternoon)) (newline)` at the bottom of the file and run

```bash
plt-r5rs class-sections.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i class-sections.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine.

## Think About

- Draw the box-and-pointer picture of what `merge-sections` actually returns. How many elements does that list have, and what is its first element?
- `cons` takes two arguments. What kind of thing is each one supposed to be, and what does the result look like when the first argument is itself a list?
- `count-students` and `first-student` look correct. Why do they still give the "wrong" answers here?
