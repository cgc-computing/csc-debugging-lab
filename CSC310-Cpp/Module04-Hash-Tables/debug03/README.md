# Word Counting with a Chained Hash Table

**Course:** CSC310 &nbsp;|&nbsp; **Module 4:** Hash Tables &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

`WordCountTable` maps `std::string` keys to `int` counts using separate chaining: each of 13 buckets holds a singly linked list of nodes. The hash code is the familiar polynomial `h = 31·h + c` over the characters. The driver counts the words of a short passage and prints several lookups.

## Expected Behavior

```
distinct words: 26
the: 3
analysis: 2
sorting: 2
linear: 2
priority: 1
n: 2
zebra: 0
```

## How to Run

```bash
g++ -std=c++17 -Wall -o word_count_table word_count_table.cpp
./word_count_table
```

(on Windows: `word_count_table.exe` or `.\word_count_table.exe`)

## Your Task

Run the program, compare its output with the Expected Behavior, and inspect the code. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the chained design and the polynomial hash.

## Think About

- What range of values must a bucket index fall in? Which expression in the program produces that index, and can you convince yourself it always stays in range?
- Roughly how large does the polynomial `31·h + c` get for an eight-letter word? Follow that number through every integer type it passes through on its way to becoming an index.
- In C++, what is the sign of `a % b` when `a` is negative and `b` is positive? Try a couple of small examples on paper.
- The short words in the passage are handled fine. Why does the program fail on some words and not others?
