# Naive String Matching

**Course:** CSC310 &nbsp;|&nbsp; **Module 14:** String Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`naiveMatch` implements NAIVE-STRING-MATCHER (CLRS 32.1): for every shift `s` at which the pattern fits inside the text, compare the pattern with the text characters starting at `s`, and report every shift where all characters agree. The driver runs six text/pattern pairs.

## Expected Behavior

```
"abra" in "abracadabra": 2 matches at shifts 0 7
"aa" in "aaaaa": 4 matches at shifts 0 1 2 3
"world" in "hello world": 1 match at shift 6
"issi" in "mississippi": 2 matches at shifts 1 4
"abcd" in "abc": no match
"nan" in "banana": 1 match at shift 2
```

## How to Run

```bash
g++ -std=c++17 -Wall -o naive_match naive_match.cpp
./naive_match
```

(on Windows: `naive_match.exe` or `.\naive_match.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The comparison loop is fine; the structure should stay as it is.

## Think About

- If the text has `n` characters and the pattern has `m`, what is the *largest* shift at which the pattern still fits entirely inside the text? How many shifts are there in total?
- Count the shifts the program tries for `"aa"` in `"aaaaa"`. How many should it try?
- `"issi"` in `"mississippi"` and `"nan"` in `"banana"` come out right even in the buggy version. What do those two cases have in common that the failing cases lack?
