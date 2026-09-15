# Sum From 1 to N

**Course:** CSC110 &nbsp;|&nbsp; **Module 5:** Control Structures: Loops &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program reads a whole number `n` and adds every integer from 1 through `n` inclusive,
printing the running total after each addition and the final sum at the end.

## Expected Behavior

Sample run (the user types `5`):

```
Add the numbers from 1 up to what value? 5
After adding 1, the sum is 1
After adding 2, the sum is 3
After adding 3, the sum is 6
After adding 4, the sum is 10
After adding 5, the sum is 15
The sum of 1 through 5 is 15
```

## How to Run

```bash
g++ -std=c++17 -Wall -o sum_to_n sum_to_n.cpp
./sum_to_n
```

(on Windows: `sum_to_n.exe` or `.\sum_to_n.exe`)

Type a whole number such as `5` and press Enter.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- How many times should the loop body execute for `n = 5`? How many times does it actually execute?
- What is the value of `i` the last time the body runs? What is `i` when the loop stops?
- What single input value would make the program's answer correct? What does that tell you?
