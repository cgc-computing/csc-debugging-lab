# Balanced Brackets Checker

**Course:** CSC205 &nbsp;|&nbsp; **Module 9:** Stacks and Queues &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program decides whether the brackets `( ) [ ] { }` in a string are balanced: every opening bracket is closed by the matching kind, in the correct nesting order, and nothing is left open. It uses a stack of characters implemented as a linked list. Characters that are not brackets are ignored.

## Expected Behavior

```
"(a + b) * [c - d]" -> balanced
"{[()]}" -> balanced
"[(])" -> NOT balanced
"((a + b)" -> NOT balanced
"a + b)" -> NOT balanced
"no brackets here" -> balanced
```

## How to Run

Build with the address sanitizer enabled so that any invalid memory access is reported clearly:

```bash
g++ -std=c++17 -Wall -fsanitize=address -o bracket_checker bracket_checker.cpp
./bracket_checker
```
(on Windows: `bracket_checker.exe` or `.\bracket_checker.exe`; if your compiler does not support `-fsanitize=address`, omit that flag)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The `CharStack` class is correct as written; concentrate on how `isBalanced` uses it.

## Think About

- For each of the six test strings, write down what is on the stack at the moment the `for` loop finishes. What should be true of the stack for the string to count as balanced?
- Which test string has more closing brackets than opening ones? Walk through the loop on that string one character at a time and watch the stack.
- `pop()` documents a precondition. Whose job is it to make sure that precondition holds before the call?
