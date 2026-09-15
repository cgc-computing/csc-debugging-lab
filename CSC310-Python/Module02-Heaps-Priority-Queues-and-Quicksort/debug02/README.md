# Heapsort and a Max-Priority Queue

**Course:** CSC310 &nbsp;|&nbsp; **Module 2:** Heaps, Priority Queues, and Quicksort &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`heapsort_pq.py` implements HEAPSORT and a `MaxPriorityQueue` class (MAXIMUM, EXTRACT-MAX,
INCREASE-KEY, INSERT) that share one `max_heapify` function, following CLRS Chapter 6 on 0-based
lists. `main` heapsorts two lists in place and drains a priority queue after an insert and a key
increase.

## Expected Behavior

```
heapsort: [1, 2, 3, 4, 7, 8, 9, 10, 14, 16]
sorted correctly: True
heapsort: [2, 4, 5, 7, 8, 13, 17, 20, 25]
sorted correctly: True
priority queue drained: [15, 13, 12, 11, 10, 9, 7, 6, 5, 4, 2, 1, 0]
non-increasing: True
```

## How to Run

```bash
python3 heapsort_pq.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure and the shared `max_heapify` are fine.

## Think About

- During heapsort the list has two regions: the heap and the sorted tail. Which parameter tells
  `max_heapify` where the heap ends, and is that parameter actually used everywhere it should be?
- BUILD-MAX-HEAP relies on the fact that when it calls MAX-HEAPIFY on node *i*, both subtrees of *i*
  are already heaps. In what order must the internal nodes be visited for that to be true?
- The priority-queue part of the output looks fine. Why might a mistake in `max_heapify` or
  `build_max_heap` show up in heapsort but not in the queue?
