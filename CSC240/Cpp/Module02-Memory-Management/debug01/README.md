# Score List

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Memory Management &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`ScoreList` is a small class that owns a heap-allocated array of quiz scores: its constructor allocates the array and its destructor releases it. `main` fills a list with four scores, prints them, computes their average with a helper function, keeps a backup copy, applies a 5-point curve (capped at 100) to the original, and prints both the curved list and the untouched backup.

## Expected Behavior

```
Quiz 1: 88 92 75 100
Average: 88.75
Curved: 93 97 80 100
Backup: 88 92 75 100
```

The program should exit normally with no report from the address sanitizer.

## How to Run

This activity uses the address sanitizer so that memory mistakes are reported at the moment they happen instead of silently corrupting the heap. Compile **with** the extra flags:

```bash
g++ -std=c++17 -Wall -fsanitize=address -g -o score_list score_list.cpp
./score_list
```

(on Windows: `score_list.exe` or `.\score_list.exe`; if your compiler does not support `-fsanitize=address`, compile without it and expect a crash or garbage values rather than a tidy report.)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not change `main` or the signature of `average`; the fix belongs in the class.

## Think About

- How many `ScoreList` objects exist over the life of this program? How many times is `new int[]` executed, and how many times is `delete[]` executed?
- When a `ScoreList` is passed to `average` by value, what exactly gets copied into the parameter? Which member is a pointer, and where does the copy's pointer point?
- In Java, `ScoreList backup = quiz;` makes two references to one object. What does C++ do with that statement by default, and what would you *want* it to do for a class like this one?
