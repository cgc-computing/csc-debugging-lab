# Solution: Linked List Add at Both Ends

**Course/Module/Activity:** CSC205 · Module 7 Lists · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
[5 -> 10 -> 40]  (size 5)
```

The count says 5 but only three nodes print; the values 20 and 30 never appear.

## The Bug(s)

`addLast` links the new node after `tail` but never moves `tail` to the new node:

```cpp
} else {
    tail->next = node;
    // tail still points at the old last node
}
```

## Why the Program Behaved Incorrectly

After `addLast(10)` the list is `[10]` with `head == tail == 10`. `addLast(20)` sets `10->next = 20` but `tail` stays on 10. `addLast(30)` then sets `10->next = 30`, *overwriting* the link to 20 — node 20 is now unreachable (leaked). `addFirst(5)` works. `addLast(40)` sets `10->next = 40`, orphaning 30. The traversal from `head` therefore sees 5, 10, 40. `count` is incremented every time, so it reports 5, which is the mismatch that gives the bug away.

## The Concept This Illustrates

A tail pointer is a cached invariant: "tail always refers to the last node." Every operation that changes the last node must re-establish that invariant, or the cache silently lies. Students often think of `tail->next = node` as "appending" and forget that the *pointer variable* is a separate piece of state from the *link*. The orphaned nodes also give a first taste of memory leaks in hand-built structures: nothing points to 20 and 30, so the destructor can never free them.

## The Correction

```cpp
// before
} else {
    tail->next = node;
}
// after
} else {
    tail->next = node;
    tail = node;
}
```

## Instructor Notes

- Some students "fix" it by walking from `head` to find the end in `addLast`. It produces the right output but makes `addLast` O(n) and leaves the tail pointer meaningless; the README rules this out, so ask them what `tail` is for.
- Have students add a temporary `cout` in `addLast` printing `tail->data` before and after; the pointer never changing is very visible.
- Ask: "Does `addFirst` need to touch `tail`?" (Only when the list was empty — and the code already does that. Good contrast with `addLast`, which must *always* update it.)
- Follow-up: run the fixed program under `-fsanitize=address` and, if available, `leaks`/`valgrind` to confirm no leaks; then re-run the buggy one to show the leaked nodes.
