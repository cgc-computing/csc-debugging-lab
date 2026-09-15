# Honor Roll

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Memory Management &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program adds six students one at a time to a `std::vector<Student>`, announcing each addition. While it builds the roster it remembers which student has the highest GPA so far. At the end it prints everyone with a GPA of 3.5 or better and then names the top student.

## Expected Behavior

```
Added Aisha (roster size 1)
Added Marcus (roster size 2)
Added Priya (roster size 3)
Added Diego (roster size 4)
Added Sofia (roster size 5)
Added Ken (roster size 6)
Honor roll (GPA >= 3.5):
  Marcus 3.9
  Priya 3.6
  Sofia 3.7
Top student: Marcus with GPA 3.9
```

The program should exit normally with no report from the address sanitizer.

## How to Run

This activity uses the address sanitizer, because the mistake here can otherwise go unnoticed for a long time. Compile **with** the extra flags:

```bash
g++ -std=c++17 -Wall -fsanitize=address -g -o honor_roll honor_roll.cpp
./honor_roll
```

(on Windows: `honor_roll.exe` or `.\honor_roll.exe`; without sanitizer support the program may appear to work, print garbage, or crash, depending on the day.)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the single pass over the incoming students; the roster must still be built with `push_back`.

## Think About

- Where does a `std::vector` keep its elements? What has to happen to that storage when you `push_back` onto a vector that is already full?
- `top` is a pointer to an element *inside* the vector. After the storage moves, what does `top` point at? Is there anything at that address now?
- The sanitizer report names the line that freed the memory and the line that later read it. Which library operation did the freeing, and which line of *your* code asked for it?
- In Java, a reference to an object in an `ArrayList` stays valid when the list grows. Why does the same idea not carry over to a `std::vector<Student>` of objects?
