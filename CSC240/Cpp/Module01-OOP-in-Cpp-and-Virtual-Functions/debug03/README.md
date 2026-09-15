# Session Log

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** OOP in C++ and Virtual Functions &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

A `Session` logs when it opens and closes. A `FileSession` is a `Session` that also allocates a buffer on the heap when it opens and releases it when it closes, logging both. `main` creates three sessions, describes them through base-class pointers, and then logs everyone out by deleting each pointer. Every `[alloc]` line must be matched by a `[free]` line.

## Expected Behavior

```
[open]  session for guest
[open]  session for maria
[alloc] 4096-byte buffer for maria
[open]  session for devin
[alloc] 1024-byte buffer for devin
Active sessions:
  plain session (guest)
  file session (maria, 4096 bytes)
  file session (devin, 1024 bytes)
Logging everyone out...
[close] session for guest
[free]  buffer for maria
[close] session for maria
[free]  buffer for devin
[close] session for devin
```

## How to Run

```bash
g++ -std=c++17 -Wall -o session_log session_log.cpp
./session_log
```

(on Windows: `session_log.exe` or `.\session_log.exe`)

No input is required. Read any compiler warnings; they are part of the evidence.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- `describe()` picks the right version for each session. `delete s` does not. What decides which destructor runs when you delete through a base-class pointer?
- In what order do the destructors of a derived object run, and which one is responsible for `buffer_`?
- Java has no destructors and a garbage collector. Which part of this program's job would Java do for you, and which part (the `[free]` log line, closing a real file) would it still leave to you?
