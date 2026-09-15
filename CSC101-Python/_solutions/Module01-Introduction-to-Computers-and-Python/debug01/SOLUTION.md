# Solution: Welcome Greeting

**Course/Module/Activity:** CSC101 · Module 1 Introduction to Computers and Python · debug01  
**Bug type(s):** runtime  
**Bug count:** 1

## Observed Behavior

The first two lines print, both prompts work, and "Nice to meet you, Jordan." prints. Then:

```
Traceback (most recent call last):
  File "greeting.py", line 12, in <module>
    Print("I like the color " + color + " too!")
NameError: name 'Print' is not defined
```

The final "Have a great semester." line never appears.

## The Bug(s)

`greeting.py`, line 12: `Print(...)` is capitalized. Python's built-in function is `print`.

## Why the Program Behaved Incorrectly

Python executes statements top to bottom. Lines 4–11 are valid, so they run. When Python reaches
line 12 it looks up a name called `Print`; no such name exists (identifiers are case-sensitive), so
it raises `NameError` and stops. Nothing after that line runs.

## The Concept This Illustrates

Case sensitivity of identifiers, sequential execution, and how to read a traceback: the `File`/
`line` entry says where, the last line says what kind of problem and which name was involved.

## The Correction

```python
# before
Print("I like the color " + color + " too!")
# after
print("I like the color " + color + " too!")
```

## Instructor Notes

* Students often ask why this is not a SyntaxError. Point out that `Print(...)` is grammatically
  valid Python; the problem only appears when Python tries to *find* the name at run time. Compare
  with removing a closing quote, which fails before anything runs.
* Have them predict what would happen if the typo were on line 4 instead. (Nothing would print.)
* Some students will "fix" it by deleting the line. Ask them to compare with the Expected Behavior.
