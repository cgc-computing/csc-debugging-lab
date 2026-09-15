# Activity Selection

**Course:** CSC310 &nbsp;|&nbsp; **Module 7:** Greedy Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`activity_selection.py` solves the activity-selection problem of CLRS Section 15.1: given activities
with start and finish times, choose as many mutually compatible (non-overlapping) activities as
possible. The greedy procedure sorts the activities, takes the first, and then repeatedly takes the
next activity that starts no earlier than the last chosen one finished. A small brute-force checker
reports the true optimum size so the greedy answer can be compared with it.

## Expected Behavior

```
CLRS activity set
  chosen  : ['a1', 'a4', 'a8', 'a11']
  count   : 4   (optimum 4)
Lab schedule
  chosen  : ['intro', 'lecture', 'quiz', 'wrapup']
  count   : 4   (optimum 4)
```

## How to Run

```bash
python3 activity_selection.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the greedy
approach; do not make `select_activities` call the brute-force checker.

## Think About

- The greedy choice is "the activity that leaves the most room for the rest". Of the attributes an
  activity has, which one measures how much room it leaves?
- In the CLRS data, the program picks `a3` first. How long does `a3` occupy the room, and which
  compatible activities does that choice rule out?
- Write down the order in which the program considers the activities and the order CLRS's
  GREEDY-ACTIVITY-SELECTOR considers them. Where do they differ?
- Both test sets come out one activity short. Is that a coincidence, or can you construct an input
  where the program's rule does much worse?
