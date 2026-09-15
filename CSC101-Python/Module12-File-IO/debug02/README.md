# Workout Log

**Course:** CSC101 &nbsp;|&nbsp; **Module 12:** File I/O &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

Each time the program runs it asks what workout you did today, adds that entry to the end of
`workout_log.txt`, and then prints the entire log. Earlier entries must be kept.

## Expected Behavior

`workout_log.txt` starts out containing two entries:

```
Mon: ran 2 miles
Tue: 30 min yoga
```

Running the program:

```
What did you do today? Wed: lifted weights

Your workout log so far:
  Mon: ran 2 miles
  Tue: 30 min yoga
  Wed: lifted weights
```

After the run, `workout_log.txt` should contain all three lines. If the file gets damaged while
you experiment, restore it by putting the two original lines back.

## How to Run

Run from the folder that contains both files:

```bash
python3 workout_log.py
```

Type `Wed: lifted weights` and press Enter.

## Your Task

Run the program with the sample entry and compare the printed log (and the file itself) with the
Expected Behavior. This program contains one or more bugs. Fix them so the program matches the
Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do
not rewrite the program; the structure is fine.

## Think About

* `open()` takes a mode argument. What are the differences between the modes `"r"`, `"w"`, and
  `"a"`, and what does each one do to a file that already exists?
* Where did the Monday and Tuesday entries go?
* If you ran the *original* program three days in a row, what would the log contain?
