# Solution: Exam Scores Report

**Course/Module/Activity:** CSC101 · Module 12 File I/O · debug01  
**Bug type(s):** runtime (ValueError) / boundary  
**Bug count:** 1

## Observed Behavior

```
Score 1: 88
Score 2: 92
Score 3: 79
Score 4: 95
Score 5: 84
Traceback (most recent call last):
  File "scores_report.py", line 13, in <module>
    score = int(line)
ValueError: invalid literal for int() with base 10: ''
```

All five scores print, then the program crashes before the summary.

## The Bug(s)

`scores_report.py`, line 8: `contents.split("\n")` on the raw file contents. The file ends with
a newline (`"88\n92\n79\n95\n84\n"`), so splitting yields six pieces, the last of which is the
empty string `''`. `int('')` raises `ValueError`.

## Why the Program Behaved Incorrectly

Text files conventionally end each line — including the last — with `\n`. `str.split("\n")`
produces one extra element after the final separator. The program never trimmed the contents, so
the trailing empty string was treated as a sixth "score."

## The Concept This Illustrates

Newlines are real characters in file data, and `.strip()` / `.splitlines()` / iterating over
the file object exist precisely to deal with them. Reading a file is not the same as getting
"clean" values; the program has to normalize what it reads.

## The Correction

```python
# before
lines = contents.split("\n")
# after
lines = contents.strip().split("\n")      # or: lines = contents.splitlines()
```

Equally good: drop `read()` and loop `for line in file:` with `int(line)` (`int()` tolerates the
surrounding whitespace on each line).

## Instructor Notes

* Ask students to `print(repr(contents))` — seeing the trailing `\n` explicitly is what makes the
  extra empty element make sense.
* Some students add `if line != "":` inside the loop. That works and is a fine conversation about
  defensive handling versus cleaning input once up front.
* Ask why `int("88\n")` works but `int("")` does not (`int` ignores surrounding whitespace, but
  needs at least one digit).
* Remind students the program must be run from the activity folder so `scores.txt` is found;
  `FileNotFoundError` here is a working-directory problem, not this activity's issue.
