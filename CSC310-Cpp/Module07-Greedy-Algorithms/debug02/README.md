# Making Change with the Fewest Coins

**Course:** CSC310 &nbsp;|&nbsp; **Module 7:** Greedy Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`fewestCoins` takes a set of coin denominations (always including a 1-unit coin) and an amount, and reports the *minimum* number of coins that make that amount, together with one combination that achieves it. The driver tries several denomination sets, including the familiar {1, 5, 10, 25} and some unusual ones.

## Expected Behavior

```
amount 63 with {1, 5, 10, 25}: 6 coins -> 25 25 10 1 1 1
amount 30 with {1, 5, 10, 25}: 2 coins -> 25 5
amount 6 with {1, 3, 4}: 2 coins -> 3 3
amount 10 with {1, 3, 4}: 3 coins -> 4 3 3
amount 8 with {1, 4, 5}: 2 coins -> 4 4
amount 88 with {1, 2, 5, 10, 20, 50}: 6 coins -> 50 20 10 5 2 1
```

## How to Run

```bash
g++ -std=c++17 -Wall -o coin_change coin_change.cpp
./coin_change
```

(on Windows: `coin_change.exe` or `.\coin_change.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. You may restructure `fewestCoins` as much as you need; keep the driver and the output format.

## Think About

- For {1, 3, 4} and amount 6, list every way to make 6 and count the coins in each. Which is best? Which does the program produce, and what decision led it there?
- The program is right for {1, 5, 10, 25} on both amounts tried. What is special about that denomination set that {1, 3, 4} and {1, 4, 5} lack? Can you say precisely when "take the largest coin that fits" is safe?
- Suppose you already knew the fewest coins for every amount smaller than 6. How could you combine those answers to get the answer for 6?
