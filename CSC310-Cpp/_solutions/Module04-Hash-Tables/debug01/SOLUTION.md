# Solution: Hash Table with Linear Probing

**Course/Module/Activity:** CSC310 · Module 4 Hash Tables · debug01
**Bug type(s):** runtime, boundary
**Bug count:** 1 (the same omission in `insert` and `contains`)

## Observed Behavior

```
inserting into a table of capacity 11
  insert 5 -> slot 5 after 0 probe(s)
  insert 27 -> slot 6 after 1 probe(s)
  insert 16 -> slot 7 after 2 probe(s)
  insert 10 -> slot 10 after 0 probe(s)
libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
```

Inserting 21 (home slot 10, already occupied) aborts with `std::out_of_range`; exit status 134.

## The Bug(s)

`linear_probing.cpp`, `LinearProbingTable::insert` and `LinearProbingTable::contains`:

```cpp
int idx = home + i;          // should be (home + i) % capacity_
```

The probe index is never reduced modulo the capacity, so probing past the last slot leaves the table instead of wrapping to slot 0.

## Why the Program Behaved Incorrectly

Key 21 has home slot 10, which holds 10. The next probe computes index 11, and `slots_.at(11)` on an 11-element vector throws. Had the code used `operator[]`, this would have been an out-of-bounds write (undefined behavior) that might appear to work; `.at()` makes the mistake visible immediately. `contains` has the identical flaw, so even a table that happened to fill without wrapping would fail lookups for keys whose probe sequence crosses the end.

## The Concept This Illustrates

Open addressing treats the table as a *circular* sequence of slots: the probe sequence h(k, 0), h(k, 1), ..., h(k, m−1) must be a permutation of 0..m−1, which for linear probing means (h'(k) + i) mod m. Without the modulus the probe sequence is a straight line that runs off the table, so slots before the home slot are unreachable and the table can report "full" or crash while empty slots remain. The rule also explains why insert and search must compute identical sequences.

## The Correction

```cpp
int idx = (home + i) % capacity_;
```

in both `insert` and `contains`.

## Instructor Notes

- Students who fix `insert` but not `contains` will see all inserts succeed and then `contains(21)` throw; use that to stress that every operation shares one probe sequence.
- Some students bound the loop with `if (idx >= capacity_) break;` instead of wrapping. Ask what happens to key 21 then (it is reported as not insertable while slots 0–4 are empty).
- Follow-up: what load factor does this table reach, and why does linear probing degrade as it fills (primary clustering)?
