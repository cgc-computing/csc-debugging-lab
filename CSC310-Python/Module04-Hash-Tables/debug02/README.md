# Open Addressing With Deletion

**Course:** CSC310 &nbsp;|&nbsp; **Module 4:** Hash Tables &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`open_addressing_delete.py` implements an open-addressing hash table (linear probing, h(k) = k mod 11)
that supports insert, search and delete. Keys are student ID numbers. The `main` block inserts eight
records, deletes two of them, searches for every original key, and then inserts one more record to
show that freed space is reused.

## Expected Behavior

```
after inserts : 0:22 1:33 2:44 3:- 4:- 5:5 6:16 7:27 8:38 9:9 10:-
after deletes : 0:22 1:X 2:44 3:- 4:- 5:5 6:X 7:27 8:38 9:9 10:-

search 22: Ana
search 33: None
search 44: Cho
search  5: Dev
search 16: None
search 27: Fay
search 38: Gus
search  9: Hal

after insert 55: 0:22 1:55 2:44 3:- 4:- 5:5 6:X 7:27 8:38 9:9 10:-
search 55: Ivy
search 44: Cho
```

(`-` marks a slot that has never been used; `X` marks a slot whose record was deleted.) The two
deleted IDs, 33 and 16, must report `None`; every other original key must still be found.

## How to Run

```bash
python3 open_addressing_delete.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep open
addressing; do not switch to chaining or rebuild the table after each delete.

## Think About

- Trace the search for key 44 by hand after the deletes. Which slots does the probe sequence visit,
  and at which slot does the loop stop? Why does it stop there?
- A search stops early when it reaches a slot that has *never* held a key. Is that the same
  condition as "this slot currently holds nothing"? Should it be?
- The final insert of 55 shows the space at slot 1 being reused. How can a table distinguish "free
  and never used" from "free because something was removed", and which of the three operations
  needs to treat those two cases differently?
