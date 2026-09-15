# Circular Array Queue

**Course:** CSC205 &nbsp;|&nbsp; **Module 9:** Stacks and Queues &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`CircularQueue` is a FIFO queue of `int` values in a fixed-size array that reuses slots freed by `dequeue` (a ring buffer). `Main` fills a 5-slot queue, removes two jobs, adds two more, and then drains it.

## Expected Behavior

```
queued:   [1, 2, 3, 4, 5]
finished: 1
finished: 2
queued:   [3, 4, 5]
queued:   [3, 4, 5, 6, 7]
finished: 3
finished: 4
finished: 5
finished: 6
finished: 7
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the array at capacity 5; do not resize it.

## Think About

- After five enqueues and two dequeues, which array slots are free? What is the value of `rear`?
- When `rear` reaches the end of the array, where should the next item go, and what arithmetic expresses that?
- Compare how `front` advances in `dequeue` with how `rear` advances in `enqueue`. Should they differ?
