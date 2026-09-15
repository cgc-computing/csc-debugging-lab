# Queue Built From Two Stacks

**Course:** CSC310 &nbsp;|&nbsp; **Module 0:** Course Introduction and Data Structures Review &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`two_stack_queue.py` implements a FIFO queue using only two LIFO stacks (Python lists used with
`append` and `pop`). Every operation should be amortized O(1), and elements must come out in exactly
the order they went in. The `main` block simulates a print server whose jobs arrive in bursts and are
dequeued between bursts, then runs a second check against a plain list.

## Expected Behavior

```
Jobs printed, in order:
  1. report.pdf
  2. photo.png
  3. notes.txt
  4. slides.pptx
  5. invoice.pdf
  6. resume.docx
Integer test matches FIFO order: True
Dequeued: [10, 20, 21, 30, 31, 32, 40, 41, 42, 43]
```

## How to Run

```bash
python3 two_stack_queue.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not replace
the two stacks with a `deque`; the two-stack design is the point of the exercise.

## Think About

- Draw both stacks after the first three `enqueue` calls and the first `dequeue`. Which element is on
  top of each stack?
- Now draw them again after the next two `enqueue` calls. When more jobs are moved from the inbox to
  the outbox, where do they land relative to the jobs already waiting there?
- Under what condition is it *safe* to move elements from the inbox to the outbox? What is the
  amortized-cost argument that says each element is moved at most once?
