# Solution: Dice Simulator

**Course/Module/Activity:** CSC101 · Module 13 Python Libraries · debug01  
**Bug type(s):** boundary (exclusive upper bound in `randrange`)  
**Bug count:** 1

## Observed Behavior

```
Results of 600 rolls:
1:  118  #######################
2:  126  #########################
3:  114  ######################
4:  121  ########################
5:  121  ########################
6:    0
```

Faces 1–5 each appear about 120 times; face 6 never appears, on every run.

## The Bug(s)

`dice_simulator.py`, line 11: `random.randrange(1, 6)` returns an integer from 1 up to *but not
including* 6, exactly like `range(1, 6)`. The die can never roll a 6.

## Why the Program Behaved Incorrectly

`randrange(start, stop)` follows the same half-open convention as `range`. The programmer read
`6` as the largest possible value. Six hundred rolls are spread over five faces (about 120 each),
and `counts[6]` stays at 0.

## The Concept This Illustrates

Reading library documentation for inclusive versus exclusive bounds. `randrange(a, b)` excludes
`b`; `randint(a, b)` includes both. The bug is deterministic in its *symptom* even though the
program is random — a useful lesson about how to test randomized code (look at what is impossible,
not just what is likely).

## The Correction

```python
# before
face = random.randrange(1, 6)
# after
face = random.randint(1, 6)          # or: random.randrange(1, 7)
```

## Instructor Notes

* Both corrections are fine; ask students to explain the two different upper limits.
* Some students propose `randrange(0, 6) + 1`; also correct, and a nice bridge to zero-based
  thinking. Ask which reads most clearly.
* A common mis-fix is `randrange(1, 7)` *and* changing the dictionary to include key 7 "just in
  case"; ask whether a 7 should ever be possible.
* Extension: use `random.seed(42)` at the top so runs are reproducible while debugging, then
  remove it.
