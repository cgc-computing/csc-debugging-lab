# Solution: Open Addressing With Deletion

**Course/Module/Activity:** CSC310 · Module 4 Hash Tables · debug02
**Bug type(s):** conceptual/design (deletion in open addressing)
**Bug count:** 1

## Observed Behavior

The deletes appear to work, but keys that live *beyond* a deleted slot in their probe sequence can
no longer be found:

```
after deletes : 0:22 1:- 2:44 3:- 4:- 5:5 6:- 7:27 8:38 9:9 10:-

search 22: Ana
search 33: None
search 44: None
search  5: Dev
search 16: None
search 27: None
search 38: None
search  9: Hal
```

Keys 44, 27 and 38 are still physically in the table (visible in the printed row) yet `search`
returns `None` for them. The later insert of 55 happens to land in slot 1, after which 44 becomes
findable again.

## The Bug(s)

`open_addressing_delete.py`, method `delete`:

```python
self.slots[j] = EMPTY
```

Deletion resets the slot to the same `EMPTY` marker used for never-occupied slots. There is no
distinct "deleted" marker anywhere in the program.

## Why the Program Behaved Incorrectly

`_find_slot` stops probing as soon as it meets an `EMPTY` slot, on the reasoning that if the key had
been inserted it would have stopped at that free slot. That reasoning is only valid if the slot was
free *at the time the key was inserted*. Key 44 was inserted when slots 0 and 1 were occupied, so it
sits in slot 2. Deleting 33 empties slot 1; a later search for 44 probes 0 (22, no), then 1 (`EMPTY`)
and gives up before reaching slot 2. Deleting 16 from slot 6 cuts off 27 and 38 the same way.

## The Concept This Illustrates

In open addressing, the empty slots encode information about every probe sequence that passed
through them. Deleting by "just emptying the slot" destroys that information. CLRS Section 11.4
introduces a special `DELETED` value: `search` must treat it as occupied (keep probing) while
`insert` treats it as available. This is why open-addressing tables are awkward to delete from, why
their search time depends on the history of insertions rather than the current load factor, and why
chaining is preferred when deletions are frequent.

## The Correction

```python
# before
DELETED did not exist; delete() wrote EMPTY.

# after
DELETED = "<deleted>"

def insert(...):        # DELETED slots are available
    if self.slots[j] is EMPTY or self.slots[j] is DELETED:
        ...

def _find_slot(...):    # DELETED slots do not stop a search
    if self.slots[j] is EMPTY:
        return None
    if self.slots[j] is not DELETED and self.slots[j][0] == key:
        return j

def delete(...):
    self.slots[j] = DELETED
```

The corrected file also prints `X` for a deleted slot.

## Instructor Notes

- A common partial fix is to add the tombstone but leave `insert` treating it as occupied. The
  program then still passes the search checks but the "after insert 55" line changes (55 lands in
  slot 3). Ask whether a table full of tombstones can ever accept an insert.
- Another partial fix marks the slot but forgets to guard `self.slots[j][0]` against the string
  marker in `_find_slot`; that raises `TypeError` on the first search that crosses a tombstone. Let
  students discover it and explain why.
- Some students propose "re-insert everything after the hole" (backward-shift deletion). That
  is a legitimate technique for linear probing; ask why it does *not* work for quadratic or double
  hashing.
- The keys were chosen so that two clusters (22-33-44 and 5-16-27-38) each lose a middle element.
