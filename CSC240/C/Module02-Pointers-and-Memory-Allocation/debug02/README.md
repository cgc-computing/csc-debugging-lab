# Word Copies

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Pointers and Memory Allocation &nbsp;|&nbsp; **Activity:** debug02
**Language:** C (C11)

## Goal

The program takes a fixed list of five words, makes a heap-allocated copy of each one with a hand-written `copy_string` function, builds a dynamically allocated table of the words' lengths, prints the words with their lengths and a total, and frees everything it allocated.

## Expected Behavior

```
pointer        length  7
malloc         length  6
segmentation   length 12
free           length  4
heap           length  4
Total characters: 33
```

The program should finish without any error report from the address sanitizer.

## How to Run

This activity uses the address sanitizer so that memory mistakes are reported instead of silently corrupting the heap. Compile **with** the extra flag:

```bash
gcc -std=c11 -Wall -fsanitize=address -g -o word_copies word_copies.c
./word_copies
```

(on Windows: `word_copies.exe` or `.\word_copies.exe`; if your compiler does not support `-fsanitize=address`, compile without it and read the code very carefully, because the mistakes may not show up as output.)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- How many bytes does the string `"heap"` occupy in memory? Is that the same number `strlen` returns?
- `malloc` takes a number of *bytes*. How many bytes does an `int` occupy on your machine, and how many does an array of five of them need?
- The sanitizer report names a function and says how far past the end of a block the program wrote or read. Which allocation is it talking about, and how big was that block?
