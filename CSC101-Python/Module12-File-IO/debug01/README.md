# Exam Scores Report

**Course:** CSC101 &nbsp;|&nbsp; **Module 12:** File I/O &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The file `scores.txt` holds one exam score per line. The program reads the file, lists each score,
and prints how many scores there were, their total, and their average.

## Expected Behavior

`scores.txt` contains:

```
88
92
79
95
84
```

Running the program produces:

```
Score 1: 88
Score 2: 92
Score 3: 79
Score 4: 95
Score 5: 84

Number of scores: 5
Total points:     438
Average score:    87.6
```

## How to Run

Run from the folder that contains both files:

```bash
python3 scores_report.py
```

No keyboard input is required.

## Your Task

Run the program and read all of its output. This program contains one or more bugs. Fix them so
the program matches the Expected Behavior, and be ready to explain *why* the original version
behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

* Open `scores.txt` in an editor and press the down arrow past the last score. How does the file
  end? What does `file.read()` return for that file — write out the exact string, including every
  `\n`.
* If you split that string on `"\n"`, how many pieces do you get, and what is the last one?
* What tools does Python give you for trimming whitespace from the ends of a string, or for
  splitting text into lines without this problem?
