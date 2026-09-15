# Validated Score Reader

**Course:** CSC205 &nbsp;|&nbsp; **Module 4:** File I/O and Exceptions &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads integer scores from the keyboard until the user types `0`. If the user types something that is not a whole number, the program reports it, discards it, and keeps going.

## Expected Behavior

Typing `85`, `92`, `abc`, `78`, `0` (each followed by Enter):

```
Enter scores one at a time. Enter 0 to finish.
Score: 85
Score: 92
Score: abc
Skipping invalid input: abc
Score: 78
Score: 0
Scores entered: 3
Total: 255
Average: 85
```

The program must finish after the `0`. If it keeps printing without waiting for you, stop it with Ctrl+C.

## How to Run

```bash
g++ -std=c++17 -Wall -o score_reader score_reader.cpp
./score_reader
```
(on Windows: `score_reader.exe` or `.\score_reader.exe`)

Then type the five inputs shown above, one per line.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the loop structure; only the handling of a bad token needs attention.

## Think About

- What state is `cin` in immediately after `cin >> value` fails on `abc`? Is `abc` still waiting in the input buffer?
- While a stream is in a failed state, what does *every* later `>>` on it do?
- What has to be true about the stream before you can read (or discard) the offending text?
