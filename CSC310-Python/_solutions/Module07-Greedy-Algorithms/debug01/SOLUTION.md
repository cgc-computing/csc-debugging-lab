# Solution: Activity Selection

**Course/Module/Activity:** CSC310 · Module 7 Greedy Algorithms · debug01
**Bug type(s):** conceptual/design (wrong greedy choice)
**Bug count:** 1

## Observed Behavior

```
CLRS activity set
  chosen  : ['a3', 'a7', 'a11']
  count   : 3   (optimum 4)
Lab schedule
  chosen  : ['setup', 'demo', 'review']
  count   : 3   (optimum 4)
```

The chosen activities are mutually compatible, but there are only three of them where four are
possible.

## The Bug(s)

`activity_selection.py`, function `select_activities`:

```python
ordered = sorted(activities, key=lambda a: a[1])
```

The activities are sorted by *start* time (index 1) rather than by *finish* time (index 2).

## Why the Program Behaved Incorrectly

Sorting by start time makes the greedy step "take the activity that starts earliest". In the CLRS
data that is `a3` (0–6), which occupies the room until time 6 and excludes `a1`, `a2`, `a4`, `a5`
and `a6`. The finish-time rule instead takes `a1` (1–4), which frees the room two units earlier and
leaves room for `a4`, then `a8`, then `a11`. In the lab schedule the earliest starter is `setup`
(0–3), which blocks `intro` and `lecture`. Sorting by finish time is the only ordering for which the
greedy-choice property (the greedy-choice theorem of CLRS Section 15.1) has been proved for this problem; starting earliest has
no such guarantee, and with an activity like `long` (0–9) in the mix it can be arbitrarily bad.

## The Concept This Illustrates

A greedy algorithm is only as good as its greedy choice. "Take the earliest start", "take the
shortest", and "take the one with fewest conflicts" all sound reasonable, and all can be beaten by
counterexamples; "take the earliest finish" is correct because the activity that finishes first
leaves the maximum remaining time, and an exchange argument shows some optimal solution contains it.
Students should learn to ask *why* a particular greedy choice is safe, not merely whether it sounds
plausible.

## The Correction

```python
# before
ordered = sorted(activities, key=lambda a: a[1])
# after
ordered = sorted(activities, key=lambda a: a[2])
```

## Instructor Notes

- Some students try "shortest duration first" (`key=lambda a: a[2] - a[1]`). It finds 4 on the CLRS
  data but is not optimal in general; ask them to construct a counterexample (a short activity
  straddling two long compatible ones).
- Others sort by finish time but keep comparing `start >= last_finish` against the wrong
  variable; the checker line makes the discrepancy visible.
- Ask students to prove the greedy-choice property on the board (exchange argument) and then to
  identify which line of code the proof is about.
- Follow-up: the brute-force checker is Θ(2ⁿ n log n). Why is it acceptable here and not as the
  real algorithm? What is the running time of the greedy version once the input is sorted?
