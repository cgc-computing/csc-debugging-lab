# Ticket Block

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Memory Management &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

A box office reserves a block of three seats for a group by allocating an array of `Ticket` objects on the heap, prints the tickets, and then releases the block. Every `Ticket` prints a `[returned]` line from its destructor, so a correct run shows one `[returned]` line per seat before the final confirmation.

## Expected Behavior

```
Tickets issued:
  seat 14 -> Omar
  seat 15 -> Lena
  seat 16 -> Chris
Returning the block...
[returned] seat 16 (Chris)
[returned] seat 15 (Lena)
[returned] seat 14 (Omar)
All seats returned.
```

(The three `[returned]` lines appear in reverse seat order; that is normal for an array of objects.) The program should exit normally with no report from the address sanitizer.

## How to Run

This activity uses the address sanitizer so that heap mistakes produce a readable report. Compile **with** the extra flags:

```bash
g++ -std=c++17 -Wall -fsanitize=address -g -o ticket_block ticket_block.cpp
./ticket_block
```

(on Windows: `ticket_block.exe` or `.\ticket_block.exe`; without sanitizer support you will see a crash or an allocator error message instead of a report.)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- How many `Ticket` objects are created by `reserve_block`? How many `[returned]` lines did you actually see, and what does that tell you about how many destructors ran?
- C++ has two forms of `new` and two forms of `delete`. Which form created this block? Which form is releasing it? Why does the language need two?
- The sanitizer says the address being freed is a few bytes *inside* an allocated region rather than at its start. Where might an array-of-objects allocation keep the element count?
