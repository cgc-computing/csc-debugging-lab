# Fibonacci Timing

**Course:** CSC205 &nbsp;|&nbsp; **Module 5:** Recursion and Analysis of Algorithms &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program computes `fib(30)` and `fib(40)` and prints each result with the time it took in milliseconds. The header comment claims `fib` runs in O(n) time — linear in `n`. Your job is to check that claim experimentally and make the program live up to it.

## Expected Behavior

Both results are correct and both computations are essentially instantaneous. For a linear-time algorithm, `fib(40)` should take at most a small multiple of the time for `fib(30)` — never hundreds of times longer.

```
fib(30) = 832040   (0 ms)
fib(40) = 102334155   (0 ms)
```

(Times of a few milliseconds are fine. The important thing is that the two times are of the same order of magnitude.)

## How to Run

```bash
g++ -std=c++17 -Wall -o fibonacci_timing fibonacci_timing.cpp
./fibonacci_timing
```
(on Windows: `fibonacci_timing.exe` or `.\fibonacci_timing.exe`)

Write down both times. Then change `main` to time `fib(35)` as well and see where it falls between the other two. If a run takes more than about half a minute, stop it with Ctrl+C and use smaller values.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The results are correct; the problem is the growth of the running time.

## Think About

- Draw the call tree for `fib(5)`. How many times is `fib(2)` computed? How many times would `fib(2)` be computed inside `fib(30)`?
- If going from n = 30 to n = 40 multiplies the time by a large factor, roughly what function of n is the running time? What would a truly O(n) algorithm do to the time when n grows by 10?
- What work is being repeated, and how could the program remember it instead?
