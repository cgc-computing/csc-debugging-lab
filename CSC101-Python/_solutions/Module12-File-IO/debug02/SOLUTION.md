# Solution: Workout Log

**Course/Module/Activity:** CSC101 · Module 12 File I/O · debug02  
**Bug type(s):** conceptual/design (file open mode)  
**Bug count:** 1

## Observed Behavior

```
What did you do today? Wed: lifted weights

Your workout log so far:
  Wed: lifted weights
```

Only the new entry is shown, and `workout_log.txt` now contains just that one line; Monday and
Tuesday are gone.

## The Bug(s)

`workout_log.py`, line 8: `open(LOG_FILE, "w")`. Write mode truncates the file to zero length
the moment it is opened, discarding the existing entries. Append mode (`"a"`) is needed.

## Why the Program Behaved Incorrectly

`"w"` means "start a fresh file." Opening the log in that mode erased it before `write` ran, so
the file afterward holds only the new entry. The read loop then faithfully prints the single line
that remains.

## The Concept This Illustrates

File modes express intent: `"r"` read, `"w"` overwrite, `"a"` add to the end. Choosing `"w"`
for a log is a destructive operation on data the program did not create, and the loss is permanent.

## The Correction

```python
# before
with open(LOG_FILE, "w") as log:
# after
with open(LOG_FILE, "a") as log:
```

## Instructor Notes

* Students must restore the two original lines before re-testing; the README tells them how.
  Make the point that the *file* is the evidence, not just the screen.
* Some students try to "fix" it by reading the old contents first, then writing everything back
  with `"w"`. It works, and it is a good moment to ask which is simpler and what happens if the
  program crashes between the read and the write.
* Ask what `"a"` does when the file does not exist yet (it creates it), and whether `"r"` would.
