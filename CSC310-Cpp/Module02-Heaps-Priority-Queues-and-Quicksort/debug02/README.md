# Heapsort

**Course:** CSC310 &nbsp;|&nbsp; **Module 2:** Heaps, Priority Queues, and Quicksort &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program implements HEAPSORT from CLRS on a 0-based `std::vector<int>`: BUILD-MAX-HEAP turns the array into a max-heap in place, then the maximum is swapped to the end, the heap shrinks by one, and MAX-HEAPIFY repairs the root. Each test array must come out in nondecreasing order.

## Expected Behavior

```
input:  4 1 3 2 16 9 10 14 8 7 
output: 1 2 3 4 7 8 9 10 14 16 
sorted

input:  5 13 2 25 7 17 20 8 4 
output: 2 4 5 7 8 13 17 20 25 
sorted

input:  3 3 1 2 3 1 
output: 1 1 2 3 3 3 
sorted

input:  1 2 3 4 5 6 7 
output: 1 2 3 4 5 6 7 
sorted

```

## How to Run

```bash
g++ -std=c++17 -Wall -o heapsort heapsort.cpp
./heapsort
```

(on Windows: `heapsort.exe` or `.\heapsort.exe`)

## Your Task

Run the program, compare its output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not replace the algorithm with `std::sort`; the heapsort structure is fine.

## Think About

- BUILD-MAX-HEAP relies on MAX-HEAPIFY's precondition that both child subtrees are already heaps. In which order must the internal nodes be processed for that precondition to hold?
- During the sorting phase the array has two regions: the heap and the already-sorted suffix. Which region is MAX-HEAPIFY allowed to look at, and how does it know where the boundary is?
- Trace the last test (already sorted input): after the first swap, where does the 7 go, and what stops it from being pulled back into the heap?
