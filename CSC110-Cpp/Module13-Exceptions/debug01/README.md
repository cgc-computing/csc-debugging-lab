# Sum of Typed Numbers

**Course:** CSC110 &nbsp;|&nbsp; **Module 13:** Exceptions &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program asks how many entries the user will type, reads that many entries, and adds up the
ones that are whole numbers. Any entry that is not a whole number is reported and skipped, and
the program keeps going with the rest.

## Expected Behavior

Sample run (the user types `5`, presses Enter, then types `12 7 x 30 4` and presses Enter):

```
How many entries? 5
Enter 5 entries: 12 7 x 30 4
Skipping 'x' (not a whole number)
Valid entries: 4
Sum: 53
```

## How to Run

```bash
g++ -std=c++17 -Wall -o number_sum number_sum.cpp
./number_sum
```

(on Windows: `number_sum.exe` or `.\number_sum.exe`)

Type `5` and press Enter, then type `12 7 x 30 4` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- When `stoi` throws an exception, which statements are skipped, and where does execution resume?
- How many times should the loop body run for the sample input? How many times does it actually run?
- After an entry is skipped, what should happen to the entries that come after it?
