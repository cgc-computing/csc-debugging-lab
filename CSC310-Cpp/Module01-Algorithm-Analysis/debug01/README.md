# Insertion Sort with Comparison Counting

**Course:** CSC310 &nbsp;|&nbsp; **Module 1:** Algorithm Analysis &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

The program implements INSERTION-SORT from CLRS on a 0-based `std::vector<int>` and counts how many times a key is compared with an element of the array, so that the count can be compared with the Θ(n) best case and Θ(n²) worst case discussed in class.

## Expected Behavior

```
input:  5 2 4 6 1 3 
sorted: 1 2 3 4 5 6 
comparisons: 12

input:  31 41 59 26 41 58 
sorted: 26 31 41 41 58 59 
comparisons: 9

input:  9 8 7 6 5 4 3 2 1 
sorted: 1 2 3 4 5 6 7 8 9 
comparisons: 36

input:  1 2 3 4 5 
sorted: 1 2 3 4 5 
comparisons: 4

input:  42 
sorted: 42 
comparisons: 0

```

## How to Run

```bash
g++ -std=c++17 -Wall -o insertion_sort insertion_sort.cpp
./insertion_sort
```

(on Windows: `insertion_sort.exe` or `.\insertion_sort.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The overall structure of the sort is fine.

## Think About

- When the key is smaller than every element before it, which index should it end up at, and what value must the inner-loop index reach for that to happen?
- Trace the first test by hand for the key `1`. How many elements should shift right, and how many actually do?
- The reversed array of 9 elements should cost n(n−1)/2 = 36 comparisons. Which comparisons is the program failing to make, and does the missing count depend on n?
