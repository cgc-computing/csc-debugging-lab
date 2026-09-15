# Solution: Array Stack

**Course/Module/Activity:** CSC205 · Module 9 Stacks and Queues · debug01
**Bug type(s):** boundary, logic
**Bug count:** 2 (the same off-by-one in `peek` and in `pop`)

## Observed Behavior

```
size after 3 pushes: 3
peek: 0
popping: 0 30 20
peek after pushing 7: 20
empty? no
```

The count is right, but the top is reported as 0, the value 10 never comes back out, and after pushing 7 the stack claims its top is 20.

## The Bug(s)

In `array_stack.cpp`, class `ArrayStack`:

1. `peek()` returns `items[top]`.
2. `pop()` reads `items[top]` and *then* decrements `top`.

`push` stores at `items[top]` and then increments, so `top` is the count of items and the topmost item lives at `items[top - 1]`. Both `peek` and `pop` read one slot too high — the first unused slot.

## Why the Program Behaved Incorrectly

After pushing 10, 20, 30, the array holds `[10, 20, 30, 0, 0, ...]` and `top == 3`. `peek()` reads `items[3]`, which the constructor zero-filled, so it prints 0. The popping loop reads `items[3]` (0), then `items[2]` (30), then `items[1]` (20) and stops when `top` reaches 0; `items[0]`, the 10, is never read. Pushing 7 writes `items[0] = 7` and sets `top = 1`, so `peek()` reads `items[1]`, which still holds the stale 20 from earlier.

The output is deterministic only because the constructor zero-fills the storage; without that loop the extra slot would hold an indeterminate value.

## The Concept This Illustrates

An array-based stack must pick one meaning for `top` — "number of items" or "index of the top item" — and every operation must honor the same convention. Here `push` uses the first meaning and `peek`/`pop` use the second. Students who hold this bug usually understand the stack's LIFO behavior fine; what they are missing is that the index arithmetic is part of the data structure's invariant and has to be checked in every method, not just the one they were thinking about when they wrote it.

## The Correction

```cpp
// before
int peek() const { return items[top]; }
int pop() { int value = items[top]; top--; return value; }

// after
int peek() const { return items[top - 1]; }
int pop() { top--; int value = items[top]; return value; }
```

## Instructor Notes

- Some students will instead change `push` to `top++; items[top] = value;` so that `peek`/`pop` "work." Ask them what `isEmpty()` (`top == 0`) now means, which slot is never used, and what `size()` reports after one push. The convention has to be fixed everywhere, not moved around.
- Ask why the first popped value is exactly 0 and not garbage. Then ask what would print if the zero-fill loop in the constructor were removed — a good moment to talk about indeterminate values and why `-fsanitize=address` would *not* catch this bug (the read is inside the allocation).
- Follow-up: "What should `pop` and `peek` do when the stack is empty?" The class documents a precondition; discuss precondition vs. defensive check vs. exception.
- Mention that `top` as a *count* makes `isEmpty`/`isFull`/`size` trivial, while `top` as an *index* starts at -1; both are valid, and the textbook may use either.
