# Solution: Print Job Queue

**Course/Module/Activity:** CSC205 · Module 9 Stacks and Queues · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

```
add job 101: queued
...
add job 105: queued
size: 5
Printing two jobs:
  nothing to print
  nothing to print
add job 106: rejected (full)
add job 107: rejected (full)
size: 5
Printing everything:
  nothing to print
  (repeated six times)
```

The queue fills correctly and reports size 5, but from then on it insists it is empty when asked to dequeue and full when asked to enqueue. It is wedged.

## The Bug(s)

`circular_queue.cpp`, class `CircularQueue`:

```cpp
bool isEmpty() const { return front == rear; }
```

`front == rear` is true both when the queue is empty *and* when it is full.

## Why the Program Behaved Incorrectly

`enqueue` advances `rear` with `(rear + 1) % capacity`. After five enqueues into a 5-slot array, `rear` wraps from 4 back to 0, which is exactly where `front` is. The queue is full, `count == 5`, yet `isEmpty()` sees `front == rear` and answers true. Every `dequeue` therefore returns false without touching anything, `count` never drops, `isFull()` (which correctly uses `count`) keeps rejecting new jobs, and the program can never make progress again.

## The Concept This Illustrates

In a circular buffer the two indices alone cannot distinguish "empty" from "full": both states have `front == rear`. Implementations resolve this either by tracking a separate count (as this class already does) or by sacrificing one slot so that "full" is `(rear + 1) % capacity == front`. This program does half of each — `isFull` trusts `count`, `isEmpty` trusts the indices — and the inconsistency is only exposed when the queue actually fills, which is why a small-capacity test is essential for circular structures.

## The Correction

```cpp
// before
bool isEmpty() const { return front == rear; }
// after
bool isEmpty() const { return count == 0; }
```

## Instructor Notes

- A common alternative "fix" is to change `isFull` to `(rear + 1) % capacity == front`. Point out that this makes `isEmpty` and `isFull` disagree in the other direction and silently reduces usable capacity to 4 — job 105 would be rejected. The README's "all 5 slots must be usable" rules this out; ask students to explain why.
- Another attempt: remove the `%` so `rear` never wraps. Ask what `items[5]` is, and what happens after a few hundred jobs.
- Ask students to state the class invariant in one sentence ("`count` items are stored in slots `front`, `front+1`, ..., wrapping, and `rear == (front + count) % capacity`"). Once they can say it, ask which of the three fields is *derivable* from the other two — it is a good design discussion: redundancy is fine if every method maintains it.
- Follow-up: have them add a `peek()` and decide which field it should check.
