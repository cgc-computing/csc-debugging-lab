# Honor Roll

**Course:** CSC110 &nbsp;|&nbsp; **Module 10:** More About Arrays &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`HonorRoll` builds an array of four `Student` objects from parallel arrays of names and GPAs, prints all students, and then lists those with a GPA of 3.5 or higher. `Student` is a simple class with a default constructor, setters, getters, and `toString`.

## Expected Behavior

```
All students:
  Ava      GPA 3.90
  Ben      GPA 3.20
  Cleo     GPA 3.60
  Dmitri   GPA 2.80

Honor roll (GPA 3.5 or higher):
  Ava
  Cleo
```

## How to Run

```bash
javac *.java
java HonorRoll
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The `Student` class is correct; look at `HonorRoll`.

## Think About

- Right after `new Student[4]` executes, what is stored in each of the four slots?
- How many `Student` objects exist at that moment? How many `Student` *references* exist?
- What is the difference between creating an array and creating the objects the array is meant to hold?
