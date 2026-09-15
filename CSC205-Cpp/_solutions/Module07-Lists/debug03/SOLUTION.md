# Solution: Linked List Remove by Value

**Course/Module/Activity:** CSC205 · Module 7 Lists · debug03
**Bug type(s):** runtime (use-after-free), boundary (head case)
**Bug count:** 2 (related: both are mistakes in the unlink step of `remove`)

## Observed Behavior

With `-fsanitize=address`, the very first removal is reported:

```
[10, 20, 30, 40, 50]  size=5
=================================================================
==...==ERROR: AddressSanitizer: heap-use-after-free on address 0x6020000000f8 ...
READ of size 8 at 0x6020000000f8 thread T0
    #0 ... in LinkedList::remove(int)
    #1 ... in main
0x6020000000f8 is located 8 bytes inside of 16-byte region ...
freed by thread T0 here:
    #0 ... in operator delete(void*)
    #1 ... in LinkedList::remove(int)
previously allocated by thread T0 here:
    ...
    #1 ... in LinkedList::addFirst(int)
```

(The partial line `remove 30: ` may not appear because the process is aborted before `cout` is flushed. The report says the freed 16-byte region is a `Node` allocated in `addFirst`, and the bad read happens 8 bytes in — the `next` field.)

Without the sanitizer, the middle removals may appear to work (the freed memory often still holds the old `next` pointer), and the program then crashes with a segmentation fault on `remove 10`, the head node, because `previous` is `nullptr`.

## The Bug(s)

1. `remove` frees the node *before* reading its `next` field:
   ```cpp
   delete current;
   previous->next = current->next;   // reads freed memory
   ```
2. `remove` assumes the node has a predecessor. When the match is the head node, `previous` is `nullptr` and `previous->next = ...` dereferences null; `head` is never updated.

## Why the Program Behaved Incorrectly

Bug 1: after `delete current`, the node's memory belongs to the allocator. Reading `current->next` is undefined behavior. AddressSanitizer poisons freed memory and reports the read immediately. On an ordinary build the stale bytes are usually still there, so the program *seems* to work — the classic reason use-after-free bugs survive into production.

Bug 2: the search loop keeps `previous` one step behind `current`. If the first node matches, the loop body never runs and `previous` stays `nullptr`. Unlinking the head is a different operation (`head = current->next`), and the code has no branch for it.

## The Concept This Illustrates

Two invariants of pointer-based structures. First, *unlink, then free*: a node must be fully disconnected from the structure (and everything you need from it read) before it is destroyed; the order of those two lines is the whole lesson. Second, the *head has no predecessor*: any operation that redirects "the previous node's next" must handle the case where the previous node is the `head` variable itself. Students often test removal from the middle, see it work, and never try the ends.

## The Correction

```cpp
// before
delete current;
previous->next = current->next;

// after
if (previous == nullptr) {
    head = current->next;
} else {
    previous->next = current->next;
}
delete current;
```

## Instructor Notes

- Without the sanitizer some students will report "remove 30 works, remove 10 crashes" and fix only the head case. Insist on the ASan build so the use-after-free is visible; then ask why the unsanitized run "worked" and whether that is acceptable.
- Some students swap the two lines but keep a single `previous->next` assignment; the head removal still crashes. Others add the head branch but keep `delete` first. Each fix removes one symptom — a good illustration of confirming *all* the expected output, not just the first line.
- Ask: "Why does `remove 50` (the tail) not need a special case?" (`current->next` is `nullptr`, which is exactly what the predecessor should now point to.) Contrast with a list that maintains a `tail` pointer, where it *would* need one.
- Follow-up: a dummy/sentinel head node eliminates the special case; have students sketch it.
