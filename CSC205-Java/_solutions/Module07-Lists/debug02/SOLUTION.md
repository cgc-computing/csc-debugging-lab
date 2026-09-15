# Solution: Linked List Insert at Index

**Course/Module/Activity:** CSC205 · Module 7 Lists · debug02
**Bug type(s):** boundary, runtime
**Bug count:** 1

## Observed Behavior

The middle insertion lands one position too far, and the end insertion crashes:

```
Start:            10 -> 20 -> 30 -> 40
insertAt(0, 5):   5 -> 10 -> 20 -> 30 -> 40
insertAt(2, 15):  5 -> 10 -> 20 -> 15 -> 30 -> 40
Exception in thread "main" java.lang.NullPointerException: Cannot read field "next" because "<local3>" is null
	at SinglyLinkedList.insertAt(SinglyLinkedList.java:51)
	at Main.main(Main.java:17)
```

## The Bug(s)

`SinglyLinkedList.java`, `insertAt`: the walk `for (int i = 0; i < index; i++) cur = cur.next;` advances `index` steps, stopping on the node currently *at* position `index`. The new node is then linked *after* `cur`, so it ends up at position `index + 1`. When `index == size`, the walk steps off the end (`cur` becomes `null`) and `cur.next` throws.

## Why the Program Behaved Incorrectly

In a singly linked list you can only insert *after* a node you hold a reference to. To make the new node position `index`, you must stop on its future predecessor, at position `index − 1` — i.e., take `index − 1` steps from `head`. For `insertAt(2, 15)` on `5 -> 10 -> 20 -> ...`, two steps reach node 20 (position 2); linking after it puts 15 at position 3. For `insertAt(6, 45)` on a six-node list, six steps from position 0 go past the last node to `null`.

## The Concept This Illustrates

The predecessor rule of singly linked lists: insertion and deletion always operate through the *previous* node's `next` field. Off-by-one confusion between "the node at index k" and "the node before index k" is the most common linked-list mistake, and the `index == 0` special case exists precisely because position 0 has no predecessor.

## The Correction

```java
// before
for (int i = 0; i < index; i++) {
// after
for (int i = 0; i < index - 1; i++) {
```

## Instructor Notes

- Some students keep the loop and change the relink to insert *before* `cur` by copying values (`n.value = cur.value; cur.value = value;`). That works for middles but not for the end case; ask them to run `insertAt(6, 45)`.
- Others add `if (index == size) { addLast(value); return; }`. Reasonable as a guard, but the middle insertion is still off by one — make sure they check line 3 of the output too.
- Good trace exercise: number the nodes 0..5 and have students tick off each `cur = cur.next` for `index = 2`.
- Ask: why is the `tail` update (`if (n.next == null) tail = n;`) needed at all, and does the corrected loop reach that case?
