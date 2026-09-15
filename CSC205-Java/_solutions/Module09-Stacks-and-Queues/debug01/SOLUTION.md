# Solution: Array-Based Stack

**Course/Module/Activity:** CSC205 · Module 9 Stacks and Queues · debug01
**Bug type(s):** boundary, logic
**Bug count:** 2 (same misconception in `pop` and `peek`)

## Observed Behavior

```
size after 3 pushes: 3
peek: 0
pop:  0
pop:  30
pop:  20
empty: true
```

## The Bug(s)

`ArrayStack.java`:

1. `pop`: `int value = data[top]; top--;` reads the slot *above* the top item, then decrements.
2. `peek`: `return data[top];` reads the same empty slot.

With the convention "`top` = number of items", the top item lives at `data[top - 1]`; `data[top]` is the next free slot.

## Why the Program Behaved Incorrectly

After three pushes the array is `[10, 20, 30, 0, ...]` and `top == 3`. `peek` returns `data[3]`, which is the never-written `0`. `pop` returns `data[3]` (0) and sets `top` to 2; the next `pop` returns `data[2]` (30), then `data[1]` (20). The 10 is never returned — the values are shifted by one and the last one is lost. `size` and `isEmpty` are correct, which is why the loop still terminates after three pops.

## The Concept This Illustrates

A consistent index convention is the entire design of an array stack. `push` does *store, then increment* (`data[top++] = v`), so `pop` must do the mirror image: *decrement, then read* (`return data[--top]`). Mixing "top is the count" with "top is the index of the top item" by one operation produces exactly this off-by-one.

## The Correction

```java
// pop, before
int value = data[top];
top--;
return value;
// after
top--;
return data[top];

// peek, before
return data[top];
// after
return data[top - 1];
```

## Instructor Notes

- Some students change the constructor to `top = -1` and the `push` to `data[++top]`. That is the *other* consistent convention; accept it if `isEmpty`, `size`, `pop`, and `peek` are all updated to match (`isEmpty` becomes `top == -1`, `size` becomes `top + 1`). Half-converted versions are a good discussion.
- Ask why `peek` returned 0 rather than crashing: Java arrays are zero-initialized, so this bug is silent in Java but would read garbage in C++.
- Ask: "After pushing 8 values into a capacity-8 stack, what does the original `peek` do?" (`data[8]` → `ArrayIndexOutOfBoundsException` — the bug is not always silent.)
