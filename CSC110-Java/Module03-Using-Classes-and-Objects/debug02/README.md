# Two-Dice Showdown

**Course:** CSC110 &nbsp;|&nbsp; **Module 3:** Using Classes and Objects &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

Two players each roll a pair of ordinary six-sided dice. The program uses a `Random` object to roll the dice, prints each player's two rolls and total, and reminds the players that the higher total wins. The random generator is seeded so every run produces the same rolls.

## Expected Behavior

Every die must show a value from 1 to 6, so each player's total must be between 2 and 12. With the seed used in the program, a correct run prints:

```
=== Two-Dice Showdown ===

Player 1 rolls: 1 and 3
Player 1 total: 4

Player 2 rolls: 1 and 5
Player 2 total: 6

Higher total wins. Possible totals range from 2 to 12.
```

## How to Run

```bash
javac DiceGame.java
java DiceGame
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not change the seed; the structure of the program is fine.

## Think About

- Look at the individual dice values printed. Are all of them values a real die could show?
- Read the documentation (or recall from class) what range of values `Random`'s `nextInt(int bound)` produces. Is the bound included?
- The last line says totals range from 2 to 12. What is the smallest total this program could actually print? Work it out from the code, not from the sample run.
