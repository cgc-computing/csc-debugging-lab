# Honor Roll Ordering

**Course:** CSC205 &nbsp;|&nbsp; **Module 3:** Polymorphism and Interfaces &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`Student` implements `Comparable<Student>` so that `Arrays.sort` orders students from highest GPA to lowest. `Main` sorts a small roster and prints it with ranks.

## Expected Behavior

```
Honor roll order:
1. Ben   3.90
2. Eli   3.85
3. Dev   3.50
4. Ana   3.20
5. Cleo  2.80
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `Main` is fine; the ordering rule belongs in `Student`.

## Think About

- What does the `Comparable` contract say `compareTo` must return when `this` should come *before* `other`, *after* `other`, or is *equal*?
- For two students whose GPAs are 3.85 and 3.50, what integer does the current `compareTo` return? What does that tell `Arrays.sort`?
- Is there a library method that compares two `double` values correctly?
