# Solution: Word Censor

**Course/Module/Activity:** CSC101 · Module 3 Strings · debug02  
**Bug type(s):** conceptual/design (string immutability)  
**Bug count:** 1

## Observed Behavior

```
Original: this homework is dumb, really dumb
Censored: this homework is dumb, really dumb
```

The "Censored" line is identical to the original; nothing was replaced.

## The Bug(s)

`censor.py`, line 10: `censored.replace(banned, stars)` is called as a statement and its result
is thrown away. `replace` does not modify `censored`; it returns a *new* string, which the program
never stores.

## Why the Program Behaved Incorrectly

Strings in Python are immutable. Every string method that "changes" text actually builds and
returns a new string, leaving the original untouched. Line 10 computes the censored text
correctly, then discards it, so `censored` still refers to the same characters as `message`.

## The Concept This Illustrates

String immutability and the pattern `variable = variable.method(...)`. Students coming from the
list methods later in the course (`append`, `sort`) will see the mirror image of this issue there.

## The Correction

```python
# before
censored = message
censored.replace(banned, stars)
# after
censored = message.replace(banned, stars)
```

## Instructor Notes

* The assignment `censored = message` on line 9 is harmless but confusing; ask students whether
  it is needed once the correction is in place.
* Some students expect `message` to change too after the fix. Have them explain why it does not.
* Try a banned word that does not appear in the message; `replace` simply returns the same text.
  Contrast with `find`, which returns -1 when a substring is missing.
