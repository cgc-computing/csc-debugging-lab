# High Score Entry

**Course:** CSC110 &nbsp;|&nbsp; **Module 3:** Using Classes and Objects &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program asks for a new high score and then the player's full name (first and last, with a
space between). It prints a banner announcing the score and reports how many characters are in
the player's name.

## Expected Behavior

Sample run (the user types `1200`, presses Enter, then types `Maria Santos` and presses Enter):

```
Enter the new high score: 1200
Enter the player's full name: Maria Santos

*** NEW HIGH SCORE ***
Maria Santos scored 1200 points!
Name length: 12 characters
```

## How to Run

```bash
g++ -std=c++17 -Wall -o high_score high_score.cpp
./high_score
```

(on Windows: `high_score.exe` or `.\high_score.exe`)

Type `1200` and press Enter, then type `Maria Santos` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- After you type `1200` and press Enter, exactly what characters are waiting in the input stream?
- What does `cin >> score` consume from the stream, and what does it leave behind?
- What does `getline` read up to, and what would it read if a line break were already waiting?
