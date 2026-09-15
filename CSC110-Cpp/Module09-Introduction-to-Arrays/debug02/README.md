# Highest Bowling Score

**Course:** CSC110 &nbsp;|&nbsp; **Module 9:** Introduction to Arrays &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads six bowling scores into an array, finds the highest score, and reports both the
score and the game number (1 through 6) in which it was bowled.

## Expected Behavior

Sample run (the user types `142 168 155 201 177 190`):

```
Enter 6 game scores: 142 168 155 201 177 190
Highest score: 201
Bowled in game 4
```

## How to Run

```bash
g++ -std=c++17 -Wall -o highest_score highest_score.cpp
./highest_score
```

(on Windows: `highest_score.exe` or `.\highest_score.exe`)

Type six whole numbers separated by spaces, for example `142 168 155 201 177 190`, and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- The program tracks two facts about the best game. What relationship should always hold between them?
- Trace the loop for the sample input. Each time a new best score is found, what changes?
- For what input would the original program happen to give the right game number?
