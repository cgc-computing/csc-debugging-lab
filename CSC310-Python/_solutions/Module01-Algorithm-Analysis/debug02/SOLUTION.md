# Solution: One-Pass Duplicate Removal

**Course/Module/Activity:** CSC310 · Module 1 Algorithm Analysis · debug02
**Bug type(s):** conceptual/design (asymptotic cost of primitive operations)
**Bug count:** 2 (same misconception, two operations)

## Observed Behavior

Results are correct but the time quadruples when n doubles, i.e., the function is Θ(n²):

```
unique_in_order([4, 7, 4, 1, 7, 9, 1, 4]) = [4, 7, 1, 9]

n =  10000: 9995 unique readings, 0.259 s
n =  20000: 19995 unique readings, 1.040 s
time ratio (n doubled): 4.0x
```

## The Bug(s)

`unique_stream.py`, function `unique_in_order`:

1. `pending.pop(0)` removes from the front of a Python list, which shifts every remaining element:
   O(n) per call, O(n²) over the loop.
2. `x not in seen` where `seen` is a list performs a linear scan: O(|seen|) per call, O(n²) total
   when almost all readings are distinct (the sample has only 5 duplicates).

Both are "one line, one operation" statements whose hidden cost is linear.

## Why the Program Behaved Incorrectly

The loop body executes n times, but the cost of one iteration is not constant. Summing
`pop(0)` costs gives n + (n-1) + ... + 1 = Θ(n²), and the `in` scans give the same sum. Doubling n
multiplies each sum by four, which is exactly what the timing shows (0.26 s → 1.04 s). Nothing about
the output is wrong, so the only symptom is the growth rate.

## The Concept This Illustrates

Asymptotic analysis counts *primitive operations*, and a library call is not primitive just because
it is one token. Students must know (or measure) the cost model of the containers they use: list
`append`/`pop()` are amortized O(1), `pop(0)`/`insert(0, x)`/`in` are O(n); a `set` gives expected
O(1) membership and a `collections.deque` gives O(1) at both ends. The empirical doubling test is the
standard way to check an O(n) claim.

## The Correction

```python
# before
pending = list(items)
seen = []
...
x = pending.pop(0)
if x not in seen:
    seen.append(x)

# after
from collections import deque
pending = deque(items)
seen = set()
...
x = pending.popleft()
if x not in seen:
    seen.add(x)
```

Iterating over `items` directly with `for x in items:` is an equally good fix for the queue half.

## Instructor Notes

- Students who fix only the `set` will still see a ratio between 2 and 4 because `pop(0)` is
  cheaper than the scan (it is a `memmove`) but still linear; try n = 40 000 to make it obvious.
- Students who fix only `pop(0)` will see essentially no change because the membership scan
  dominates; this is a good moment to talk about which term dominates a sum.
- Ask why `seen.append(x)` and `result.append(x)` are *not* a problem (amortized O(1)).
- With the fix the timings are so small that noise can push the ratio to 1.5x or 3x; that is a
  worthwhile conversation about measuring tiny intervals and why analysts use large n.
- Someone may propose `list(dict.fromkeys(items))`. It is correct and linear; ask them to explain
  *why* it is linear.
