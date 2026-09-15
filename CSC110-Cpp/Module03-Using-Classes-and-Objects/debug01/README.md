# Name Formatter

**Course:** CSC110 &nbsp;|&nbsp; **Module 3:** Using Classes and Objects &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads a three-part name on one line, splits it into first, middle, and last names
using `std::string` methods, and prints each part plus a formal version and the initials.

## Expected Behavior

Sample run (the user types `Ada King Lovelace`):

```
Enter your full name (first middle last): Ada King Lovelace
First name:  Ada
Middle name: King
Last name:   Lovelace
Formal:      Lovelace, Ada King
Initials:    AKL
```

## How to Run

```bash
g++ -std=c++17 -Wall -o name_formatter name_formatter.cpp
./name_formatter
```

(on Windows: `name_formatter.exe` or `.\name_formatter.exe`)

When prompted, type a name with exactly three words, for example `Ada King Lovelace`, and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- For `Ada King Lovelace`, what index does `find(' ')` return? What does `rfind(' ')` return?
- Look up the two arguments of `std::string::substr`. What does each one mean?
- Which of the three parts come out correctly, and what is different about how they are extracted?
