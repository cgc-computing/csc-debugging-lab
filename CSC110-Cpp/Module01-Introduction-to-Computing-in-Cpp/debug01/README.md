# Quote of the Day Printer

**Course:** CSC110 &nbsp;|&nbsp; **Module 1:** Introduction to Computing in C++ &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program prints a decorated banner, a short quotation split across two lines, and the
person who said it. It takes no input.

## Expected Behavior

A correct run prints exactly this, with each part of the quotation on its own line:

```
===============================
       Quote of the Day
===============================
The most dangerous phrase in the language is,
'We've always done it this way.'
        -- Grace Hopper

Have a great lab session!
```

## How to Run

```bash
g++ -std=c++17 -Wall -o quote_printer quote_printer.cpp
./quote_printer
```

(on Windows: `quote_printer.exe` or `.\quote_printer.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- What does `cout` do when one output statement ends and the next one begins?
- Where does a line break come from in C++ output? Does the compiler ever add one for you?
- Count the lines in the Expected Behavior. How many line breaks does the program need to produce?
