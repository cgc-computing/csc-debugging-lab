# Linear-Probing Hash Table

**Course:** CSC310 &nbsp;|&nbsp; **Module 4:** Hash Tables &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`linear_probe_table.py` implements a fixed-size hash table with open addressing and linear probing
(CLRS Section 11.4). Keys are course codes; a small polynomial hash chooses the home slot, and a
collision moves to the next slot in the probe sequence. The `main` block inserts ten courses into an
11-slot table, prints where each one landed, and then searches for a few keys.

## Expected Behavior

```
insert CSC101: home slot  7, stored in slot  7
insert CSC110: home slot  4, stored in slot  4
insert CSC205: home slot  4, stored in slot  5
insert CSC240: home slot  2, stored in slot  2
insert CSC310: home slot  1, stored in slot  1
insert MAT227: home slot  6, stored in slot  6
insert PSY101: home slot  9, stored in slot  9
insert GEO101: home slot 10, stored in slot 10
insert CHM130: home slot  8, stored in slot  8
insert ENG101: home slot  7, stored in slot  0

table: 0:ENG101 1:CSC310 2:CSC240 3:- 4:CSC110 5:CSC205 6:MAT227 7:CSC101 8:CHM130 9:PSY101 10:GEO101
occupied slots: 10

search CSC310: 3
search ENG101: 3
search MAT227: 4
search BIO100: None
```

## How to Run

```bash
python3 linear_probe_table.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep linear
probing; do not switch to chaining or to a Python `dict`.

## Think About

- Write out the probe sequence h(k, 0), h(k, 1), h(k, 2), ... for a key whose home slot is 7 in an
  11-slot table. What is the fifth slot in that sequence?
- CLRS defines the probe sequence as a permutation of ⟨0, 1, ..., m-1⟩. Does the sequence this
  program generates have that property?
- Nine inserts succeed and the tenth does not. What is special about the tenth key's position
  relative to the end of the table?
