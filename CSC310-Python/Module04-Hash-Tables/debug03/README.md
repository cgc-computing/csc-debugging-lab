# Word Counter on a Chained Hash Map

**Course:** CSC310 &nbsp;|&nbsp; **Module 4:** Hash Tables &nbsp;|&nbsp; **Activity:** debug03
**Language:** Python 3

## Goal

`chained_hash_map.py` implements a hash map with separate chaining (CLRS Section 11.2): each bucket
is a list of `(key, value)` pairs, and the table doubles and rehashes when the load factor passes
0.75. The `main` block uses the map to count word frequencies in a short sentence, prints some
statistics about the table, looks up several words, and finally removes one key.

## Expected Behavior

```
words processed : 24
distinct words  : 14
buckets         : 32
rehashes        : 2
longest chain   : 3

count['the'] = 6
count['dog'] = 3
count['fox'] = 2
count['quick'] = 2
count['over'] = 2
count['hill'] = 1
count['cat'] = 0

remove 'the'   : True
count['the']   : 0
distinct words : 13
```

## How to Run

```bash
python3 chained_hash_map.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the chaining
design; do not replace the map with a Python `dict` or `collections.Counter`.

## Think About

- The word `the` appears six times. Each time, `main` calls `get` and then `put`. What does the
  bucket for `the` look like after the second `put`? After the sixth?
- What should be true of the keys within a single bucket, and within the whole table, at all times?
  Which method is responsible for keeping that true?
- After `remove('the')` returns `True`, the count for `the` is still not zero. How can a key be
  removed and still be found?
- `distinct words` is reported as 24 even though the sentence obviously repeats words. Which
  counter is off, and what event should actually change it?
