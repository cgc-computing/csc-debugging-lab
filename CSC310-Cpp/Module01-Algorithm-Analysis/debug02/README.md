# Counting Distinct Values in Linear Time

**Course:** CSC310 &nbsp;|&nbsp; **Module 1:** Algorithm Analysis &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`countDistinct` is supposed to count the distinct values in a vector with a single linear-time pass: each element is examined once and recorded if it has not been seen before. The driver generates pseudo-random data of sizes 20 000, 40 000, 80 000 and 160 000 (fixed seed, so the counts are reproducible), times each call, and prints the ratio between consecutive timings. Because n doubles each step, a Θ(n) routine should show ratios near 2.

## Expected Behavior

Distinct counts must be exactly as shown. Absolute times depend on your machine, but each size should finish in a few milliseconds and the ratios should hover around 2 (anything from about 1.5 to 2.7 is normal noise for such short timings):

```
n = 20000  distinct = 12654  time = 0.70 ms
n = 40000  distinct = 25310  time = 1.41 ms  (ratio to previous n: 2.01)
n = 80000  distinct = 50692  time = 2.88 ms  (ratio to previous n: 2.04)
n = 160000  distinct = 101140  time = 5.85 ms  (ratio to previous n: 2.03)
A linear-time routine should show a ratio near 2 each time n doubles.
```

## How to Run

```bash
g++ -std=c++17 -Wall -O2 -o distinct_count distinct_count.cpp
./distinct_count
```

(on Windows: `distinct_count.exe` or `.\distinct_count.exe`)

Run it two or three times so you can tell timing noise from a real trend.

## Your Task

Run the program and compare the timings and ratios with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The distinct counts are already correct; concentrate on the running-time claim in the header comment.

## Think About

- What does `std::vector::erase` at the front of a vector have to do to the remaining elements, and how much work is that as a function of the vector's current length?
- What is the cost of `std::find` on a vector that already holds k values? Roughly how large does k get during the pass?
- If every one of the n iterations does Θ(n) work, what ratio should you expect when n doubles? Does your measurement agree?
- Which standard containers give expected O(1) membership tests, and what would you have to change so the pass really touches each element once?
