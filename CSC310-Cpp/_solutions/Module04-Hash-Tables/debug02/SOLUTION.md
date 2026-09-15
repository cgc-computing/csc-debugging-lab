# Solution: Deleting from an Open-Addressing Hash Set

**Course/Module/Activity:** CSC310 · Module 4 Hash Tables · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

```
after inserts:   [0]=7 [1]=14 [2]=21 [3]=3 [4]=10 [5]=- [6]=- 
contains(21) = true
contains(10) = true
after removals:  [0]=7 [1]=- [2]=21 [3]=- [4]=10 [5]=- [6]=- 
contains(21) = false
contains(10) = false
contains(14) = false
after insert 28: [0]=7 [1]=28 [2]=21 [3]=- [4]=10 [5]=- [6]=- 
contains(28) = true
contains(21) = true
```

After the removals, keys 21 and 10 are still in the table but are reported absent; inserting 28 into the vacated slot makes 21 findable again.

## The Bug(s)

`open_addressing_delete.cpp`, `ProbingSet::remove`:

```cpp
if (slots_[idx] == key) {
    slots_[idx] = EMPTY;      // needs a distinct DELETED marker
    return true;
}
```

Removing a key resets its slot to EMPTY, the same state as a never-used slot, and `contains`/`insert` treat EMPTY as "end of probe sequence".

## Why the Program Behaved Incorrectly

7, 14, 21 collide at slot 0 and occupy slots 0, 1, 2; 3 sits in slot 3 and 10 (home 3) is pushed to slot 4. `contains(21)` probes 0 → 1 → 2. After `remove(14)` sets slot 1 to EMPTY, the probe for 21 stops at slot 1 and returns false, even though 21 is one slot further on. Likewise removing 3 empties slot 3 and hides 10. When 28 (home 0) is inserted it lands in slot 1, refilling the hole, so 21 becomes reachable again—an inconsistency that would confuse anyone testing the table.

## The Concept This Illustrates

In open addressing a probe sequence is a chain through the table, and a search may stop only at a slot that has *never held a key*. Deletion therefore cannot simply empty a slot: it must leave a tombstone (DELETED) that search passes through but insert may reuse. This is why CLRS notes that deletion is awkward in open addressing and why chaining is often preferred when deletes are frequent. Students holding this bug are treating the table like an array of independent cells rather than a set of overlapping probe chains.

## The Correction

```cpp
static constexpr int DELETED = -2;
...
// remove:
slots_[idx] = DELETED;
// contains: unchanged (a DELETED slot is neither EMPTY nor the key, so probing continues)
// insert: remember the first DELETED slot seen, keep probing for a duplicate,
//         and store at the remembered slot if the key is not already present.
```

The corrected `print` shows tombstones as `x`.

## Instructor Notes

- A common half-fix marks DELETED but lets `insert` treat DELETED like EMPTY immediately; that permits duplicates when the key exists further along the chain. Ask: after fixing, insert 21 again—should the size change?
- Another "fix" is to re-insert every key after the removed one (backward-shift deletion). It works for linear probing but not for quadratic or double hashing; a good discussion of why.
- Follow-up: what happens to search cost as tombstones accumulate, and when should the table be rebuilt?
