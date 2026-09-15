# Making Change With the Fewest Coins

**Course:** CSC310 &nbsp;|&nbsp; **Module 7:** Greedy Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`coin_change.py` makes change for an amount using the fewest possible coins from a given set of
denominations. The `main` block runs two denomination systems: ordinary US coins {1, 5, 10, 25} and
a three-coin system {1, 3, 4}. For each amount it prints the minimum coin count and one list of coins
that achieves it.

## Expected Behavior

```
denominations [25, 10, 5, 1]
  amount 63 -> 6 coins: [25, 25, 10, 1, 1, 1]
  amount 30 -> 2 coins: [25, 5]
denominations [4, 3, 1]
  amount  6 -> 2 coins: [3, 3]
  amount 10 -> 3 coins: [4, 3, 3]
  amount  7 -> 2 coins: [4, 3]
```

Every printed count must be the true minimum for that amount and denomination set.

## How to Run

```bash
python3 coin_change.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. You may add code;
the question to settle is under what conditions the program's strategy is guaranteed to be correct,
and what to do when those conditions do not hold.

## Think About

- For US coins, every amount in the sample comes out right. Why is taking the largest coin first
  always safe when the coins are 1, 5, 10 and 25? Try to state the property of those denominations
  that makes it safe.
- With coins {1, 3, 4} and amount 6, what does the program do on its first step, and what does that
  first step commit the rest of the solution to?
- The header comment argues that reducing the amount as much as possible at each step minimizes the
  number of coins. Which word in that argument is doing unjustified work?
- If you could not trust the largest-coin rule for a denomination set, what would you have to do
  instead to be sure of the minimum? How expensive is that, and for which amounts would you need it?
