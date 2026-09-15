# Quicksort with Lomuto Partition

**Course:** CSC310 &nbsp;|&nbsp; **Module 2:** Heaps, Priority Queues, and Quicksort &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program implements QUICKSORT with the Lomuto PARTITION procedure from CLRS. For a subarray `a[p..r]`, the pivot is `a[r]`; after partitioning, elements ≤ pivot come first, then the pivot, then the larger elements, and the two sides are sorted recursively. The driver sorts five arrays and reports how many partition calls were made.

## Expected Behavior

```
input:  2 8 7 1 3 5 6 4 
output: 1 2 3 4 5 6 7 8 
sorted  (partition calls: 5)

input:  13 19 9 5 12 8 7 4 21 2 6 11 
output: 2 4 5 6 7 8 9 11 12 13 19 21 
sorted  (partition calls: 9)

input:  5 5 5 1 5 2 
output: 1 2 5 5 5 5 
sorted  (partition calls: 4)

input:  9 7 5 3 1 
output: 1 3 5 7 9 
sorted  (partition calls: 4)

input:  1 2 3 4 5 6 
output: 1 2 3 4 5 6 
sorted  (partition calls: 5)

```

## How to Run

```bash
g++ -std=c++17 -Wall -o quicksort quicksort.cpp
./quicksort
```

(on Windows: `quicksort.exe` or `.\quicksort.exe`)

## Your Task

Run the program, compare its output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the Lomuto scheme; do not switch to a different partition method.

## Think About

- What does the index `i` represent during the partition loop? What is true of `a[p..i]` and `a[i+1..j-1]` at the top of each iteration?
- Which positions should the loop variable `j` visit? Should the pivot itself be compared with the pivot?
- After the final swap, where is the pivot? What must PARTITION return so that the recursive calls cover every element except the pivot exactly once?
- Why might the program's behavior differ between the first test and the second?
