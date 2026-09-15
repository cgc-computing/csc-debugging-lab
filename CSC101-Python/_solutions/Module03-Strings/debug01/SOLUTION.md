# Solution: Campus Username Builder

**Course/Module/Activity:** CSC101 · Module 3 Strings · debug01  
**Bug type(s):** boundary (slice end index)  
**Bug count:** 1

## Observed Behavior

```
First name: Grace
Last name:  Hopper
Username:   hoppg
```

The username has only four letters from the last name (`hopp`) instead of five (`hoppe`).

## The Bug(s)

`username.py`, line 11: `last[0:4]` takes indexes 0, 1, 2, 3 — four characters. Five characters
require `last[0:5]` (or `last[:5]`).

## Why the Program Behaved Incorrectly

A slice `s[a:b]` includes index `a` and stops *before* index `b`, so it contains `b - a`
characters. The programmer read `4` as "up to and including the fifth letter" (thinking in
1-based positions) rather than as an exclusive end index.

## The Concept This Illustrates

Zero-based indexing and half-open slice ranges. The end index of a slice is exclusive, which is
exactly why `s[0:n]` gives `n` characters. This is the same rule that later governs `range()`.

## The Correction

```python
# before
username = last[0:4] + first[0]
# after
username = last[0:5] + first[0]
```

## Instructor Notes

* Students who get the count right sometimes propose `last[1:5]` (also four characters). Have them
  print the slice by itself and count.
* Ask what happens with a short last name like `Lin`: `"Lin"[0:5]` is just `"Lin"`; slicing past
  the end does not raise an error, unlike indexing. Good contrast with `first[0]` on an empty string.
* Follow-up: what does `find` return if there is no space, and what would the slices do then?
