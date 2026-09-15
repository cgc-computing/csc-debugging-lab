# Solution: Class Rosters

**Course/Module/Activity:** CSC101 · Module 4 Lists, Tuples, Sets, and Dictionaries · debug02  
**Bug type(s):** conceptual/design (aliasing)  
**Bug count:** 1

## Observed Behavior

```
Section A: ['Maya', 'Ben', 'Chloe', 'Dev', 'Eli']
Section B: ['Maya', 'Ben', 'Chloe', 'Dev', 'Eli']
Section A has 5 students.
Section B has 5 students.
```

Section A shows the transfer student and the extra student even though only Section B was edited.

## The Bug(s)

`roster.py`, line 6: `section_b = section_a` does not copy the list. It makes a second *name*
for the same list object, so every change made through `section_b` is visible through
`section_a`.

## Why the Program Behaved Incorrectly

Assignment binds a name to an object; it never duplicates the object. Both names point at one
list, so `section_b[0] = transfer` and `section_b.append("Eli")` mutate the only list that
exists. Printing either name shows the same five students.

## The Concept This Illustrates

Reference semantics and aliasing for mutable objects. Lists are mutable, so two names for one list
see each other's changes. Making an independent copy requires `list.copy()`, `list(...)`, or a
full slice `[:]`.

## The Correction

```python
# before
section_b = section_a
# after
section_b = section_a.copy()      # or list(section_a), or section_a[:]
```

## Instructor Notes

* Ask students to draw the two-name/one-box picture before and after the correction.
* A nice check: `print(section_a is section_b)` before and after.
* Contrast with strings and numbers: `b = a` followed by `b = b + 1` does *not* change `a`,
  because numbers are immutable and `+` builds a new value. Why is that different from
  `section_b.append(...)`?
* Nested lists (a roster of lists) would still share inner lists after `.copy()`; that is a
  good "what if" for stronger groups but beyond this module.
