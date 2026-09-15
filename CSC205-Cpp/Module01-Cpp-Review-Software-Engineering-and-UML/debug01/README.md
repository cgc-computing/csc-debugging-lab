# Class Roster Lookup

**Course:** CSC205 &nbsp;|&nbsp; **Module 1:** C++ Review, Software Engineering, and UML &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

This program implements the two classes shown in the UML diagram below. A `Roster` holds any number of `Student` objects and can report whether a student with a given name is enrolled.

```
+-----------------------------+            +----------------------------------+
|           Student           |            |              Roster              |
+-----------------------------+            +----------------------------------+
| - name : char[32]           |   1..*     | - students : vector<Student>     |
| - id : int                  |<>----------+                                  |
+-----------------------------+            +----------------------------------+
| + Student(name, id)         |            | + add(s : Student) : void        |
| + getName() : const char*   |            | + find(name : const char*) : bool|
| + getId() : int             |            | + size() : int                   |
+-----------------------------+            +----------------------------------+
```

## Expected Behavior

```
Roster size: 3
Bob Chen: found
Carla Diaz: found
Zed Nobody: not found
```

## How to Run

```bash
g++ -std=c++17 -Wall -o roster roster.cpp
./roster
```
(on Windows: `roster.exe` or `.\roster.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The class declarations should also match the UML diagram exactly, including each member's visibility.

## Think About

- In the UML, what does the `-` in front of a member mean, and why does the diagram author care?
- What *type* of value does `getName()` return? What does it mean to compare two values of that type with `==`?
- Two students could have the same name written in two different places in memory. What should "the same name" mean in this program?
