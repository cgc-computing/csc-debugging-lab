# Naive String Matching

**Course:** CSC310 &nbsp;|&nbsp; **Module 14:** String Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`naive_match.py` implements NAIVE-STRING-MATCHER (CLRS Section 32.1): for every shift `s` at which the
pattern still fits inside the text, compare the pattern with the text characters starting at `s`, one
character at a time, and record the shift if all of them agree. The `main` block runs seven
text/pattern pairs and prints the shifts found.

## Expected Behavior

```
"abra" in "abracadabra": 2 matches at shifts 0 7
"aa" in "aaaaa": 4 matches at shifts 0 1 2 3
"world" in "hello world": 1 match at shift 6
"issi" in "mississippi": 2 matches at shifts 1 4
"abcd" in "abc": no match
"nan" in "banana": 1 match at shift 2
"abc" in "abc": 1 match at shift 0
```

## How to Run

```bash
python3 naive_match.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
character-by-character comparison; do not use `str.find` or slicing to do the matching.

## Think About

- CLRS says the valid shifts are `0 <= s <= n - m`. How many values is that? How many values does the
  program's loop actually try?
- `"world"` sits at the very end of `"hello world"`. Which shift would find it, and is that shift ever
  tried?
- `"abcd"` in `"abc"` (pattern longer than text) must produce no match. Does your corrected loop still
  handle that case without an index error? Why or why not?
- For `"abc"` in `"abc"` the pattern is the whole text. How many valid shifts are there, and which one?
