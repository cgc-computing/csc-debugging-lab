# Solution: Student Enrollment

**Course/Module/Activity:** CSC101 · Module 11 Classes and Objects · debug02  
**Bug type(s):** conceptual/design (class attribute shared across instances)  
**Bug count:** 1

## Observed Behavior

```
Ana is enrolled in 3 course(s): ['CSC101', 'MAT151', 'ENG101']
Ben is enrolled in 3 course(s): ['CSC101', 'MAT151', 'ENG101']
```

Both students show all three courses.

## The Bug(s)

`student.py`, line 6: `courses = []` is written in the class body, which makes it a *class
attribute* — one list shared by every `Student`. `__init__` sets `self.name` but never creates a
per-object `self.courses`.

## Why the Program Behaved Incorrectly

`self.courses.append(course)` looks up `courses` on the instance, does not find it, falls back to
the class attribute, and appends to that shared list. Ana's and Ben's enrollments all land in the
same list, and `__str__` on either object prints it.

## The Concept This Illustrates

Class attributes versus instance attributes. Anything assigned in the class body exists once, on
the class. Per-object state must be created in `__init__` via `self.`. The problem is invisible with
immutable class attributes (a shared default number is fine) and shows up exactly when the shared
value is mutable and gets mutated.

## The Correction

```python
# before
class Student:
    courses = []

    def __init__(self, name):
        self.name = name
# after
class Student:
    def __init__(self, name):
        self.name = name
        self.courses = []
```

## Instructor Notes

* `print(ana.courses is ben.courses)` in the original gives `True`; in the corrected version
  `False`. Ask students to predict before running.
* Some students keep the class attribute *and* add `self.courses = []` in `__init__`. It works
  (the instance attribute shadows the class one), but ask what the class attribute is now for.
* A wrong "fix" is `self.courses = self.courses + [course]` in `enroll`; it works by accident
  (creates an instance attribute on first call). Ask students to explain *why* it works, then
  whether they would want to rely on it.
* Connect to Module 10 debug02 (mutable default argument): same pattern, one shared list.
