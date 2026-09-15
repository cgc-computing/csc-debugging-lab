# Star Box

**Course:** CSC110 &nbsp;|&nbsp; **Module 5:** Control Structures: Loops &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

The program draws a solid rectangle of asterisks. The user chooses the number of rows and the number of columns.

## Expected Behavior

```
Rows: 3
Columns: 5

*****
*****
*****

Drew a 3 x 5 box.
```

## How to Run

```bash
javac StarBox.java
java StarBox
```

Type the number of rows and press Enter, then the number of columns and press Enter. Use `3` and `5` to reproduce the sample run.

## Your Task

Run the program and compare the drawing with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- How many stars should be printed on each row? How many actually are?
- What exactly is the *body* of the inner loop? Which statement(s) does Java consider to belong to it?
- Java lets you write a block `{ ... }` almost anywhere a statement is allowed. Does a block have to be attached to a loop or an `if`?
