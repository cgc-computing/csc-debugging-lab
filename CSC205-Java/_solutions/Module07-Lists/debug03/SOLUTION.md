# Solution: Linked List Remove by Value

**Course/Module/Activity:** CSC205 · Module 7 Lists · debug03
**Bug type(s):** boundary, logic
**Bug count:** 2

## Observed Behavior

```
Start:      10 -> 20 -> 30 -> 40   size 4
remove(30): removed   -> 10 -> 20 -> 40   size 4
remove(10): not found   -> 10 -> 20 -> 40   size 4
remove(99): not found   -> 10 -> 20 -> 40   size 4
remove(40): removed   -> 10 -> 20   size 4
addLast(50): 10 -> 20 -> 50   size 5
```

The head value can never be removed, and `size` never decreases.

## The Bug(s)

Both in `SinglyLinkedList.java`, `remove`:

1. The walk starts with `prev = head; cur = head.next;`, so the head node itself is never compared. There is no special case for removing the first node (which has no predecessor and requires reassigning `head`).
2. `size--` is missing from the successful-removal path, so the count drifts upward from the true node count.

## Why the Program Behaved Incorrectly

`remove(30)` and `remove(40)` are middle/tail removals, which the `prev`/`cur` loop handles (including the `tail` update). `remove(10)` looks only at nodes 20 and 40, finds no match, and reports "not found" — the head is simply outside the search. Meanwhile each successful removal unlinks a node but leaves `size` at 4, so the report and the printed list disagree, and after `addLast(50)` the count is 5 for a three-node list.

## The Concept This Illustrates

Two linked-list disciplines. First, *the head is special*: it has no predecessor, so any operation expressed through `prev.next` needs a separate branch (or a dummy header node) for position 0. Second, a data structure's state is the *whole set* of its fields — `head`, `tail`, `size` — and every mutator must update all of them; a correct pointer surgery with stale bookkeeping is still a broken structure.

## The Correction

```java
// added before the walk
if (head.value == value) {
    head = head.next;
    if (head == null) {
        tail = null;
    }
    size--;
    return true;
}
// inside the loop's match branch
prev.next = cur.next;
if (cur == tail) {
    tail = prev;
}
size--;          // added
return true;
```

## Instructor Notes

- Students often start the walk at `prev = null; cur = head;` and then write `if (prev == null) head = cur.next; else prev.next = cur.next;`. That is an equally good single-loop fix — accept it, and point out it is the same special case expressed differently.
- Ask: "If the list has exactly one node and it is removed, what should `tail` be?" Many fixes forget this.
- Some will decrement `size` at the top of the method (before knowing whether anything is found). Run `remove(99)` to show the problem.
- A dummy/sentinel head node eliminates the special case entirely; worth a five-minute discussion for a strong group.
