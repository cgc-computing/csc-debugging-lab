# Randomized Quicksort

**Course:** CSC310 &nbsp;|&nbsp; **Module 10:** Randomized Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`quicksort` is randomized quicksort from CLRS 7.3: RANDOMIZED-PARTITION chooses a pivot position uniformly at random from the current subarray and then runs the usual Lomuto PARTITION, so that no particular input can force the O(n²) worst case. The driver sorts five arrays (including one with many duplicates and one already sorted) with a fixed-seed generator and checks each result.

## Expected Behavior

Every array must come out sorted. The partition-call counts below are from Apple's standard library and may differ on other compilers; they are printed only so you can see that randomization is happening.

```
input:  2 8 7 1 3 5 6 4
output: 1 2 3 4 5 6 7 8
sorted  (partition calls: 5)

input:  13 19 9 5 12 8 7 4 21 2 6 11
output: 2 4 5 6 7 8 9 11 12 13 19 21
sorted  (partition calls: 7)

input:  5 5 5 1 5 2
output: 1 2 5 5 5 5
sorted  (partition calls: 5)

input:  9 7 5 3 1
output: 1 3 5 7 9
sorted  (partition calls: 3)

input:  1 2 3 4 5 6 7 8 9 10
output: 1 2 3 4 5 6 7 8 9 10
sorted  (partition calls: 6)

```

## How to Run

```bash
g++ -std=c++17 -Wall -o randomized_quicksort randomized_quicksort.cpp
./randomized_quicksort
```

(on Windows: `randomized_quicksort.exe` or `.\randomized_quicksort.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the Lomuto partition scheme and the random pivot choice.

## Think About

- Lomuto's PARTITION assumes the pivot is sitting in one particular position when its loop starts. Which position, and does the program guarantee that after choosing a random pivot?
- At the end of `randomizedPartition`, the element at `a[hi]` is swapped into the middle and its index is returned as the pivot's final position. Which element is that in the program as written?
- The output is wrong, yet the recursion still terminates and never goes out of range. Why doesn't a faulty partition cause an infinite recursion here?
