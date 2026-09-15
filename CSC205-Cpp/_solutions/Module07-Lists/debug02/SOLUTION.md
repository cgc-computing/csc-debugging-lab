# Solution: Linked List Insert at Index

**Course/Module/Activity:** CSC205 · Module 7 Lists · debug02
**Bug type(s):** boundary, logic
**Bug count:** 2 (related: both are off-by-one errors about positions in the list)

## Observed Behavior

```
[]
insert 7 at 1: rejected  []
insert 20 at 3: rejected  []
insert 99 at 9: rejected  []
size: 0
```

Every insertion is rejected, including the two `insertAt(0, ...)` calls that build the initial list, so the list stays empty. After fixing only the range check, a second symptom appears: `insert 7 at 1` produces `[5, 10, 7]` — the value lands one position too far to the right.

## The Bug(s)

1. The range check rejects `index == count`, which is the legal "append" position:
   ```cpp
   if (index < 0 || index >= count) return false;
   ```
   On an empty list (`count == 0`) even index 0 is rejected.
2. The walk to find the predecessor goes one hop too many:
   ```cpp
   for (int i = 0; i < index; i++) previous = previous->next;
   ```
   This leaves `previous` at the node currently *at* `index`, so the new node is linked after it — position `index + 1`.

## Why the Program Behaved Incorrectly

Bug 1 dominates the observed output. On the empty list `count == 0`, so the test `index >= count` is `0 >= 0`, true, and `insertAt(0, 10)` is rejected. `count` stays 0, so the second call is rejected the same way, and every later index is also `>= count`. Nothing ever gets in.

With bug 1 fixed, bug 2 shows: for `insertAt(1, 7)` on `[5, 10]`, the loop runs `index` = 1 time and `previous` becomes node 10 — the node currently *at* position 1. Linking the new node after it yields `[5, 10, 7]`. The predecessor of position `k` sits at position `k - 1`, which is `k - 1` hops from `head`.

## The Concept This Illustrates

Linked-list positions are counted in *hops*, and insertion needs the node *before* the target position, not the node at it. Separately, a list of n nodes has n + 1 insertion points (0 through n inclusive), unlike n *access* points (0 through n − 1). Students carry array-indexing intuition ("valid index < size") into insertion, where the range is one larger.

## The Correction

```cpp
// before
if (index < 0 || index >= count) return false;
...
for (int i = 0; i < index; i++) previous = previous->next;

// after
if (index < 0 || index > count) return false;
...
for (int i = 0; i < index - 1; i++) previous = previous->next;
```

## Instructor Notes

- Students who fix only the loop (bug 2) see all inserts still rejected and may assume their fix was wrong. Encourage them to test each hypothesis separately and read the `rejected` output as a separate clue.
- A common alternative fix for bug 2 is to start the loop at `i = 1` instead of changing the bound; that is fine. Another is to walk `current` and `previous` together; also fine but more code.
- Ask what happens with `insertAt(count, v)` after the fix: the loop stops at the last node and `previous->next` is `nullptr`, so the append works with no special case. Students often expect to need one.
- Follow-up: implement `removeAt(index)` and ask which positions are valid there (0 through n − 1, back to array-style).
