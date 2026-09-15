# Sum of Valid Entries

**Course:** CSC110 &nbsp;|&nbsp; **Module 13:** Exceptions &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program reads one line containing whole numbers separated by spaces and prints their sum. Any entry that is not a whole number is reported and skipped, and the program keeps going so that *all* the valid numbers are still added up.

## Expected Behavior

```
Enter whole numbers separated by spaces: 12 7 abc 30 x 5
  Skipping invalid entry: For input string: "abc"
  Skipping invalid entry: For input string: "x"

Sum of valid entries: 54
Entries skipped:      2
```

## How to Run

```bash
javac NumberSummer.java
java NumberSummer
```

Type the whole line and press Enter once. Use `12 7 abc 30 x 5` to reproduce the sample run.

## Your Task

Run the program with the sample line and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- When an exception is thrown inside a loop, where does execution go next? Does the loop continue?
- Which entries were added to the sum and which were never even looked at?
- After a bad entry is reported, where should execution resume so the remaining entries are still processed? Where does it actually resume in this program?
