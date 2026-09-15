# Launch Countdown

**Course:** CSC110 &nbsp;|&nbsp; **Module 5:** Control Structures: Loops &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads a starting number and counts down from it to 1, printing one `T-minus` line per
number, and then prints `Liftoff!`.

## Expected Behavior

Sample run (the user types `5`):

```
Start the countdown from: 5
T-minus 5
T-minus 4
T-minus 3
T-minus 2
T-minus 1
Liftoff!
```

## How to Run

```bash
g++ -std=c++17 -Wall -o countdown countdown.cpp
./countdown
```

(on Windows: `countdown.exe` or `.\countdown.exe`)

Type a whole number such as `5` and press Enter. Read any compiler messages carefully.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- What statement does the `for` loop actually repeat? How can you tell where a loop's body begins and ends?
- What value does `t` hold when the loop finishes?
- How many `T-minus` lines print, and what do they say? How does that relate to your answer above?
