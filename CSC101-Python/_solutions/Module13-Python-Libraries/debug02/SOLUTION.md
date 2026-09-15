# Solution: Birthday Facts

**Course/Module/Activity:** CSC101 · Module 13 Python Libraries · debug02  
**Bug type(s):** runtime (ValueError) / logic (argument order)  
**Bug count:** 1

## Observed Behavior

```
Birth year (e.g., 2005): 2005
Birth month (1-12): 3
Birth day (1-31): 25
Traceback (most recent call last):
  File "birthday_facts.py", line 11, in <module>
    birthday = date(year, day, month)
ValueError: month must be in 1..12
```

With a day of 12 or less (e.g., March 7) the program runs but silently describes the wrong date
(July 3 instead of March 7).

## The Bug(s)

`birthday_facts.py`, line 11: `date(year, day, month)`. The `date` constructor's signature is
`date(year, month, day)`; the program passes the day where the month belongs and vice versa.

## Why the Program Behaved Incorrectly

The library has no way to know what the caller *meant*; it interprets the second positional
argument as the month. 25 is not a valid month, so it raises `ValueError`. When the day happens to
be 12 or less, both values are "valid" and the swap goes unnoticed, producing a plausible-looking
but incorrect weekday and age.

## The Concept This Illustrates

Using a library means honoring its interface: positional argument order is defined by the
documentation, not by the order that feels natural in your own program. Also, validation that
raises immediately (the 25 case) is far friendlier than a silent wrong answer (the 7 case).

## The Correction

```python
# before
birthday = date(year, day, month)
# after
birthday = date(year, month, day)      # or: date(year=year, month=month, day=day)
```

## Instructor Notes

* Have students run the corrected program with `2005 3 7` and the original with the same input,
  then compare weekdays; it demonstrates the silent failure mode concretely.
* Keyword arguments (`date(year=year, month=month, day=day)`) are a nice defensive habit to
  mention here.
* Some students "fix" the crash by swapping the *input prompts* so the user is asked for the day
  before the month. Ask whether the printed result is then right (it is), and whether the program
  is now easier or harder to read.
* Expected values for the sample: March 25, 2005 was a Friday; 7587 days to Jan 1, 2026.
