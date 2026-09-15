# Solution: Linked List Append

**Course/Module/Activity:** CSC205 · Module 7 Lists · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
List: 10 -> 40
Size: 4
List: 5 -> 10 -> 50
Size: 6
```

## The Bug(s)

`SinglyLinkedList.java`, `addLast`, non-empty branch: `tail.next = n;` links the new node after the current tail but never moves `tail` forward (`tail = n;` is missing).

## Why the Program Behaved Incorrectly

After `addLast(10)` head and tail both refer to node 10. `addLast(20)` sets `10.next = 20` but tail still refers to 10. `addLast(30)` then sets `10.next = 30`, replacing the link to 20 — node 20 is now unreachable. `addLast(40)` overwrites again, so the list is `10 -> 40`. `size` is incremented every time, so it reports 4 even though only two nodes are reachable. The same thing happens after `addFirst(5)`: `addLast(50)` overwrites `10.next` once more.

## The Concept This Illustrates

Maintaining an *invariant* on auxiliary references. `tail` is only useful if "tail refers to the last node" holds after every mutating operation; each method that changes the end of the list is responsible for restoring it. Students who think of `tail.next = n` as "append" have not yet separated *linking the node* from *updating the bookkeeping reference*.

## The Correction

```java
// before
} else {
    tail.next = n;
}
// after
} else {
    tail.next = n;
    tail = n;
}
```

## Instructor Notes

- Have students draw three boxes and the `head`/`tail` arrows after each call; the overwrite of `10.next` becomes obvious on paper.
- Some students "fix" `addLast` by walking from `head` to the end. It produces the right output but throws away the O(1) guarantee; ask why `tail` exists at all.
- Ask what `addFirst` must do about `tail` when the list is empty (it already does — good contrast).
- Follow-up: if `size` had been computed by walking the list, would the bug have been easier or harder to notice?
