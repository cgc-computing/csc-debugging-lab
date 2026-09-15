# Solution: Queue Built From Two Stacks

**Course/Module/Activity:** CSC310 · Module 0 Course Introduction and Data Structures Review · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

The program runs without error but the jobs are served out of order and the integer check fails:

```
Jobs printed, in order:
  1. report.pdf
  2. slides.pptx
  3. invoice.pdf
  4. resume.docx
  5. photo.png
  6. notes.txt
Integer test matches FIFO order: False
Dequeued: [10, 20, 30, 40, 41, 42, 43, 31, 32, 21]
```

## The Bug(s)

`two_stack_queue.py`, method `_shift`. The method unconditionally moves every element from
`_inbox` to `_outbox`:

```python
while self._inbox:
    self._outbox.append(self._inbox.pop())
```

It is called by every `dequeue` and `peek`, even when `_outbox` already holds elements that
are waiting to be served.

## Why the Program Behaved Incorrectly

After the first burst, `_outbox` is `[notes.txt, photo.png]` (top is `photo.png`) and
`report.pdf` has been served. The next burst puts `slides.pptx, invoice.pdf` in the inbox. The
following `dequeue` shifts them onto the outbox, producing `[notes.txt, photo.png, invoice.pdf,
slides.pptx]`. Newer jobs are now *above* older ones, so `pop()` returns `slides.pptx` before
`photo.png`. The two-stack invariant, "the outbox, read top to bottom, is the front of the queue and
the inbox, read bottom to top, is the back of the queue", is violated as soon as a shift happens
while the outbox is non-empty.

## The Concept This Illustrates

The two-stack queue works because a stack reverses order and the *whole* pending sequence is
reversed exactly once. Refilling the outbox is legal only when it is empty; otherwise elements are
reversed relative to elements that have already been reversed. This is also where the amortized O(1)
argument lives: each element is pushed to the inbox once, moved once, and popped once, which is only
true if a shift never re-mixes elements.

## The Correction

```python
# before
def _shift(self):
    while self._inbox:
        self._outbox.append(self._inbox.pop())

# after
def _shift(self):
    if not self._outbox:
        while self._inbox:
            self._outbox.append(self._inbox.pop())
```

## Instructor Notes

- Some students propose "fix" `dequeue` by moving elements back to the inbox after each pop. That
  restores FIFO order but makes every dequeue O(n) and destroys the amortized bound; ask them to count
  moves for n enqueues followed by n dequeues.
- Others propose inserting at index 0 of the outbox (`insert(0, x)`). That is also O(n) per element
  and misses the point of using stacks.
- The first burst in `main` deliberately looks correct (one dequeue after three enqueues) so students
  must reason about the second burst to see the failure.
- Good follow-up: ask how `peek` and `dequeue` share the same guard, and whether `is_empty` needs to
  know about the guard at all.
