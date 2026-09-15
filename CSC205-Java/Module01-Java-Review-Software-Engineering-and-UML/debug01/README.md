# Course Roster Lookup

**Course:** CSC205 &nbsp;|&nbsp; **Module 1:** Java Review, Software Engineering, and UML &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program builds a small course roster from a comma-separated list of names, prints the roster, and then looks up students by name. The classes are supposed to implement the following UML design exactly.

```
+-----------------------------------+          +--------------------------+
|              Course               |          |         Student          |
+-----------------------------------+          +--------------------------+
| - title: String                   | 1      * | - name: String           |
| - students: Student[]             |--------->| - id: int                |
| - count: int                      |          +--------------------------+
+-----------------------------------+          | + Student(String, int)   |
| + Course(String, int)             |          | + getName(): String      |
| + enroll(Student): void           |          | + getId(): int           |
| + findStudent(String): Student    |          | + toString(): String     |
| + getCount(): int                 |          +--------------------------+
| + toString(): String              |
+-----------------------------------+
```

## Expected Behavior

```
Course: CSC205 (3 students)
  Alice Chen (1001)
  Brianna Ortiz (1002)
  Carlos Diaz (1003)
Looking up Brianna Ortiz: found -> Brianna Ortiz (1002)
Looking up Dmitri Volkov: not enrolled
```

In addition, every class should match the UML: the visibility of each member (`-` private, `+` public) and the set of methods listed.

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. Then compare each class with the UML diagram. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the overall structure is fine.

## Think About

- What does the UML say about who is allowed to read a student's name directly, and does the code agree?
- When two `String` values are produced by two different `split` calls, what does `==` actually compare?
- Which method should `Course` be calling to get at a student's name, and does it exist yet?
