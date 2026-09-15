# Print Job Queue

**Course:** CSC205 &nbsp;|&nbsp; **Module 9:** Stacks and Queues &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`CircularQueue` stores print-job IDs in a fixed-size array used circularly, with `front` and `rear` indices that wrap around. The driver fills a 5-slot queue, prints two jobs, adds two more (which must wrap around to the start of the array), and then prints everything that is left.

## Expected Behavior

```
add job 101: queued
add job 102: queued
add job 103: queued
add job 104: queued
add job 105: queued
size: 5
Printing two jobs:
  printed job 101
  printed job 102
add job 106: queued
add job 107: queued
size: 5
Printing everything:
  printed job 103
  printed job 104
  printed job 105
  printed job 106
  printed job 107
  nothing to print
```

## How to Run

```bash
g++ -std=c++17 -Wall -o circular_queue circular_queue.cpp
./circular_queue
```
(on Windows: `circular_queue.exe` or `.\circular_queue.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The capacity must stay 5 and all 5 slots must be usable.

## Think About

- On a 5-slot circular queue, write down `front`, `rear`, and `count` after each of the first five `enqueue` calls. Where are `front` and `rear` relative to each other when the queue is completely full? When it is completely empty?
- The class stores three pieces of bookkeeping. Which of them can answer "is there anything waiting?" without any ambiguity?
- Why are jobs 106 and 107 rejected even though two jobs were supposedly just removed?
