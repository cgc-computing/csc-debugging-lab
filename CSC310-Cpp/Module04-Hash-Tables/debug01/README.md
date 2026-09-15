# Hash Table with Linear Probing

**Course:** CSC310 &nbsp;|&nbsp; **Module 4:** Hash Tables &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`LinearProbingTable` stores `int` keys in an open-addressing hash table of fixed capacity 11 using linear probing: the home slot is `key % 11`, and probe number `i` examines slot `h(key, i) = (key % 11 + i) mod 11`. The program inserts eight keys, prints the table, and answers a few membership queries.

## Expected Behavior

```
inserting into a table of capacity 11
  insert 5 -> slot 5 after 0 probe(s)
  insert 27 -> slot 6 after 1 probe(s)
  insert 16 -> slot 7 after 2 probe(s)
  insert 10 -> slot 10 after 0 probe(s)
  insert 21 -> slot 0 after 1 probe(s)
  insert 32 -> slot 1 after 2 probe(s)
  insert 43 -> slot 2 after 3 probe(s)
  insert 9 -> slot 9 after 0 probe(s)
[0]=21 [1]=32 [2]=43 [3]=- [4]=- [5]=5 [6]=27 [7]=16 [8]=- [9]=9 [10]=10 
contains(16) = true
contains(21) = true
contains(32) = true
contains(43) = true
contains(7) = false
contains(54) = false
```

## How to Run

```bash
g++ -std=c++17 -Wall -o linear_probing linear_probing.cpp
./linear_probing
```

(on Windows: `linear_probing.exe` or `.\linear_probing.exe`)

## Your Task

Run the program, compare its output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep linear probing; do not switch to chaining.

## Think About

- Write out the probe sequence for key 21 in a table of capacity 11: which slots should be examined, in order?
- What range of values must a slot index always stay within, and what happens in this program when the home slot is near the end of the table?
- Insert and search must follow the *same* probe sequence. If you change one, what must you check in the other?
