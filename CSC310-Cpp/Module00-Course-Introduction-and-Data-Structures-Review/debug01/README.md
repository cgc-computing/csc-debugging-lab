# Queue Built from Two Stacks

**Course:** CSC310 &nbsp;|&nbsp; **Module 0:** Course Introduction and Data Structures Review &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`TwoStackQueue` implements a first-in, first-out queue using two `std::stack` objects: an inbox that receives new elements and an outbox that hands them back out in arrival order. Every element should be dequeued in exactly the order it was enqueued, no matter how enqueues and dequeues are interleaved.

## Expected Behavior

```
dequeue -> 1
peek    -> 2
draining: 2 3 4 5 
dequeue -> 10
dequeue -> 11
dequeue -> 12
remaining size: 2
draining: 13 14 
```

## How to Run

```bash
g++ -std=c++17 -Wall -o two_stack_queue two_stack_queue.cpp
./two_stack_queue
```

(on Windows: `two_stack_queue.exe` or `.\two_stack_queue.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior above. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the two-stack design is fine.

## Think About

- Which of the two stacks should hold the oldest element at any moment, and where in that stack should it be?
- Draw both stacks after `enqueue(1..3)`, one `dequeue`, then `enqueue(4)` and `enqueue(5)`. What must be true before you move anything from the inbox to the outbox?
- The first dequeue is correct and the queue never loses an element. Why does that make this kind of defect easy to miss in a quick test?
