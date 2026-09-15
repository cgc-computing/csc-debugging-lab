# Letter Grade Converter

**Course:** CSC110 &nbsp;|&nbsp; **Module 4:** Control Structures: Conditionals &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads a score from 0 to 100 and prints the matching letter grade: 90 and above is A,
80–89 is B, 70–79 is C, 60–69 is D, and anything below 60 is F.

## Expected Behavior

Sample run (the user types `85`):

```
Enter a score from 0 to 100: 85
Score: 85
Letter grade: B
```

Other checks: `93` gives `A`, `71` gives `C`, `64` gives `D`, `42` gives `F`.

## How to Run

```bash
g++ -std=c++17 -Wall -o letter_grade letter_grade.cpp
./letter_grade
```

(on Windows: `letter_grade.exe` or `.\letter_grade.exe`)

Type a whole number such as `85` and press Enter. Run it several times with different scores.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- In an `if / else if` chain, how many branches can run? Which one runs when several conditions are true?
- For a score of 85, list every condition in the chain that is true. Which one does the program reach first?
- Does the order of the branches matter here? Would it matter if each test checked a range with two comparisons?
