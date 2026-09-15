# Checking a Shuffle for Uniformity

**Course:** CSC310 &nbsp;|&nbsp; **Module 10:** Randomized Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`shuffle` is meant to implement RANDOMIZE-IN-PLACE (CLRS 5.3): rearrange a vector so that every one of the `n!` permutations is equally likely. Because a biased shuffle is invisible in any single run, the driver shuffles the sequence `0 1 2` 108 000 times with a fixed-seed `std::mt19937` and tallies how often each of the 6 permutations occurs. A uniform shuffle produces about 18 000 of each.

## Expected Behavior

Exact counts depend on the standard library's random-number distribution code, so they may differ slightly on another compiler; what matters is that all six counts are close to 18 000 (within a few hundred—the statistical noise for this many trials is about ±120).

```
shuffles of 3 elements: 108000   (expected per permutation: 18000)
  012:  17845  (-155)
  021:  17964  (-36)
  102:  18172  (+172)
  120:  18155  (+155)
  201:  17708  (-292)
  210:  18156  (+156)
largest deviation from expected: 292
permutations seen: 6 of 6
```

## How to Run

```bash
g++ -std=c++17 -Wall -O2 -o shuffle_tally shuffle_tally.cpp
./shuffle_tally
```

(on Windows: `shuffle_tally.exe` or `.\shuffle_tally.exe`)

## Your Task

Run the program and compare the tallies with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The tallying code is fine; concentrate on the shuffle itself.

## Think About

- How many equally likely sequences of random draws does the program as written make for `n = 3`? How many does a correct shuffle make, and how do those numbers compare with `3! = 6`?
- If `k` equally likely outcomes are each mapped to one of 6 permutations, what must be true of `k` for all 6 permutations to be equally likely?
- At step `i` of the loop, which positions of the vector are still "undecided"? Should the swap partner ever be drawn from a position that has already been settled?
