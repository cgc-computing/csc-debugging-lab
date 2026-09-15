# Solution: Word Counter on a Chained Hash Map

**Course/Module/Activity:** CSC310 · Module 4 Hash Tables · debug03
**Bug type(s):** logic, conceptual/design (dictionary invariant: a key appears at most once)
**Bug count:** 1 misconception with two visible consequences (duplicate pairs, over-counted size)

## Observed Behavior

```
words processed : 24
distinct words  : 24
buckets         : 32
rehashes        : 2
longest chain   : 8

count['the'] = 1
count['dog'] = 1
count['fox'] = 1
count['quick'] = 1
count['over'] = 1
count['hill'] = 1
count['cat'] = 0

remove 'the'   : True
count['the']   : 2
distinct words : 23
```

Every word counts as 1, the table thinks it holds 24 distinct keys, the longest chain is 8, and
removing `the` leaves a count of 2 behind.

## The Bug(s)

`chained_hash_map.py`, method `put`:

```python
def put(self, key, value):
    bucket = self.buckets[self._hash(key)]
    bucket.append((key, value))
    self.count += 1
    ...
```

`put` never checks whether `key` is already present in the bucket. It always appends a new pair and
always increments `count`.

## Why the Program Behaved Incorrectly

The first `put('the', 1)` appends `('the', 1)`. On the second occurrence, `get('the')` scans the
bucket from the front and returns the *first* pair's value, 1, so `main` calls `put('the', 2)`,
which appends `('the', 2)` behind the old pair. Every later lookup still meets `('the', 1)` first, so
the count never rises above 1 and the bucket accumulates six pairs for one key. `count` grows once
per word rather than once per distinct word (24, not 14), which inflates the load factor and
lengthens the reported chain. `remove` deletes only the first matching pair, so the next `get`
returns the second pair's value, 2.

## The Concept This Illustrates

A hash map is a *dictionary*: the invariant is that each key maps to exactly one value. In CLRS
CHAINED-HASH-INSERT the pseudocode simply inserts at the head of the list because the textbook
assumes the key is not already present; a real `put` (update-or-insert) must first search the chain
for the key. Students holding this bug conflate "insert into the bucket list" with "store the
mapping", and they also tend to think `count` is the number of operations rather than the number of
keys. The load-factor argument for O(1) expected time depends on `count` being the true number of
stored keys.

## The Correction

```python
# before
bucket.append((key, value))
self.count += 1

# after
for idx, (k, _) in enumerate(bucket):
    if k == key:
        bucket[idx] = (key, value)
        return
bucket.append((key, value))
self.count += 1
```

## Instructor Notes

- Some students fix the count by only changing `get` to return the *last* matching pair. Counts
  then look right, but `distinct words` stays 24 and `remove` still leaves a pair behind; ask them
  to explain the `remove` line.
- Others keep appending duplicates but make `remove` loop until no pair remains. Ask what the load
  factor now measures and whether the O(1 + α) bound still means anything.
- Point out that `_resize` rehashes pairs in bucket order, which is why the duplicate pairs stay in
  insertion order and the stale value keeps winning even after two rehashes.
- Good follow-up: should `put` insert at the head of the chain (as CLRS does) or at the tail? Does
  it matter for correctness? For performance?
