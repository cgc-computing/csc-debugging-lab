# Solution: Linear-Probing Hash Table

**Course/Module/Activity:** CSC310 · Module 4 Hash Tables · debug01
**Bug type(s):** runtime (index out of range caused by a boundary error in the probe sequence)
**Bug count:** 1

## Observed Behavior

The first nine inserts print as expected, then the tenth crashes:

```
insert CHM130: home slot  8, stored in slot  8
Traceback (most recent call last):
  ...
  File ".../linear_probe_table.py", line 28, in insert
    if self.slots[j] is None or self.slots[j][0] == key:
IndexError: list index out of range
```

## The Bug(s)

`linear_probe_table.py`, method `_probe`:

```python
def _probe(self, key, i):
    return self._hash(key) + i
```

The i-th probe is the home slot plus `i`, with no reduction modulo the table size.

## Why the Program Behaved Incorrectly

`ENG101` hashes to slot 7. Slots 7, 8, 9 and 10 are already occupied, so the loop in `insert` asks
for probe number 4, which evaluates to 7 + 4 = 11. There is no slot 11 in an 11-slot list, so
indexing `self.slots[11]` raises `IndexError`. Every earlier key happened to find a free slot before
running off the end, which is why the crash appears only on the tenth insert. `search` has the same
flaw: a search for an absent key whose home slot is near the end would crash too.

## The Concept This Illustrates

Open addressing requires the probe sequence ⟨h(k,0), h(k,1), ..., h(k,m-1)⟩ to be a permutation of
all `m` slots (CLRS Section 11.4). Linear probing achieves this with h(k,i) = (h'(k) + i) mod m: the
`mod m` is what makes the sequence *wrap around* to the beginning of the table. Without it, the
sequence is a walk off the end of the array and slots before the home slot can never be reached, so
the table effectively shrinks for keys that hash near the end. Students holding this bug usually
picture probing as "keep moving right" rather than as a cyclic walk.

## The Correction

```python
# before
return self._hash(key) + i
# after
return (self._hash(key) + i) % self.m
```

## Instructor Notes

- Some students "fix" the crash by stopping the loop when `j >= self.m` and raising the overflow
  error. Ask them how many slots are actually free (one) and why a table with a free slot should
  ever report overflow.
- Others enlarge the table. Point out that a larger table hides the symptom for this data set but
  the probe sequence still fails to visit slots below the home slot.
- Ask what the probe sequence looks like *after* the fix for `ENG101` (7, 8, 9, 10, 0) and have
  students verify the "stored in slot 0" line by hand.
- Follow-up: why does the loop in `insert` run at most `m` times, and what would happen without
  that bound on a completely full table?
