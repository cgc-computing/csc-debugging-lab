# Shape Area Totals

**Course:** CSC205 &nbsp;|&nbsp; **Module 3:** Polymorphism and Interfaces &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

An abstract `Shape` class is extended by `Circle`, `Rectangle`, and `Triangle`. `Main` stores the shapes in a single `Shape[]`, prints each shape's area polymorphically, and reports the total area.

## Expected Behavior

```
circle     area = 78.54
rectangle  area = 24.00
triangle   area = 6.00
Total area: 108.54
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the class hierarchy and the polymorphic loop in `Main`; also consider how `Shape` could be written so the compiler would have caught this.

## Think About

- When `Main` calls `s.area()` on the third element, which class's method actually runs, and why?
- What makes a subclass method an *override* of a superclass method rather than a brand-new method?
- What is the difference between an abstract method and a concrete method that returns a default value, from the compiler's point of view?
