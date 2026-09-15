# Solution: Queue Built from Two Stacks

**Course/Module/Activity:** CSC310 · Module 0 Course Introduction and Data Structures Review · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
dequeue -> 1
peek    -> 4
draining: 4 5 2 3 
dequeue -> 10
dequeue -> 11
dequeue -> 13
remaining size: 2
draining: 14 12 
```

The first dequeue is right, but after new elements are enqueued the queue starts returning the newest elements before older ones that are still waiting.

## The Bug(s)

`two_stack_queue.cpp`, private member `TwoStackQueue::shift()`. It unconditionally moves everything from `inbox_` to `outbox_`:

```cpp
void shift() {
    while (!inbox_.empty()) {
        outbox_.push(inbox_.top());
        inbox_.pop();
    }
}
```

The transfer is only valid when `outbox_` is empty.

## Why the Program Behaved Incorrectly

After `enqueue(1,2,3)` and one `dequeue`, the outbox holds `2` (top) and `3`. Then `4` and `5` are enqueued into the inbox. The next `peek`/`dequeue` calls `shift()`, which pushes `5` and then `4` on top of the outbox, so the outbox is now `4, 5, 2, 3` from top to bottom. Elements 4 and 5 are newer than 2 and 3 but sit above them, so they come out first. Every later interleaving of enqueue/dequeue repeats the mistake (`13` comes out before `12`).

## The Concept This Illustrates

The two-stack queue works because the outbox, once filled, contains elements in exactly the reverse of their arrival order, with the oldest on top. That invariant is only preserved if the outbox is refilled *after it has been completely drained*. Students who see the transfer as "just move the data over" have not identified the invariant the structure depends on. This is also the amortized-analysis argument from the course: each element is moved at most once, which is only true when transfers happen at outbox-empty moments.

## The Correction

```cpp
void shift() {
    if (!outbox_.empty()) {
        return;
    }
    while (!inbox_.empty()) {
        outbox_.push(inbox_.top());
        inbox_.pop();
    }
}
```

## Instructor Notes

- Some students "fix" it by draining the outbox back into the inbox before every transfer. That produces correct output but destroys the amortized O(1) bound; ask them how many times element 2 gets moved in the sample run.
- Ask students to state the invariant in one sentence ("if the outbox is non-empty, its top is the oldest element in the queue") and check it after each operation in the sample.
- A good follow-up: why does `peek` need to call `shift()` at all, and could `empty()` ever be wrong?
