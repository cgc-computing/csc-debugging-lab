# Solution: Circular Array Queue

**Course/Module/Activity:** CSC205 · Module 9 Stacks and Queues · debug02
**Bug type(s):** runtime, logic
**Bug count:** 1

## Observed Behavior

```
queued:   [1, 2, 3, 4, 5]
finished: 1
finished: 2
queued:   [3, 4, 5]
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 5 out of bounds for length 5
	at CircularQueue.enqueue(CircularQueue.java:27)
	at Main.main(Main.java:14)
```

## The Bug(s)

`CircularQueue.java`, `enqueue`: `rear = rear + 1;` never wraps around. `dequeue` correctly uses `(front + 1) % data.length`, but `rear` marches straight past the end of the array.

## Why the Program Behaved Incorrectly

After five enqueues `rear == 5`. Two dequeues free slots 0 and 1 (and `size` drops to 3, so `isFull()` is false). The next `enqueue` writes to `data[5]`, which does not exist in a length-5 array, so the JVM throws. The queue *has* room — the free slots are at the beginning — but `rear` does not know how to get back there.

## The Concept This Illustrates

The whole point of a circular queue is that both indices wrap modulo the capacity, so that freed slots at the front are reused without shifting elements. Keeping an explicit `size` (as this class does) is what avoids the classic full/empty ambiguity when `front == rear`; the wrap-around is the other half of the design, and it must be applied symmetrically to `front` and `rear`.

## The Correction

```java
// before
rear = rear + 1;
// after
rear = (rear + 1) % data.length;
```

## Instructor Notes

- Some students "fix" it by making the array bigger or by shifting all elements left on each dequeue. Ask what the O(1) enqueue/dequeue promise of a ring buffer means and whether their fix keeps it.
- Ask them to draw the five slots as a ring and place `front`/`rear` after each operation in `Main`.
- Follow-up: remove the `size` field and try to define `isEmpty`/`isFull` using only `front` and `rear`. Students discover the `front == rear` ambiguity, which motivates either the `size` counter or the "one slot wasted" convention.
- `toString` already uses the modulo idiom — a useful "the answer is already in the file" moment.
