# Longest Common Subsequence Table

**Course:** CSC310 &nbsp;|&nbsp; **Module 9:** Dynamic Programming &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`lcs.py` implements LCS-LENGTH and the reconstruction procedure from CLRS Section 14.4. It fills an
(m+1) × (n+1) table `c` whose entry `c[i][j]` is the length of a longest common subsequence of the
first `i` characters of `X` and the first `j` characters of `Y`, records directions in a second table,
and reconstructs one LCS. The `main` block prints the full table for the textbook example and then
runs a pair of longer DNA strings.

## Expected Behavior

```
      B  D  C  A  B  A
    0  0  0  0  0  0  0
  A 0  0  0  0  1  1  1
  B 0  1  1  1  1  2  2
  C 0  1  1  2  2  2  2
  B 0  1  1  2  2  3  3
  D 0  1  2  2  2  3  3
  A 0  1  2  2  3  3  4
  B 0  1  2  2  3  4  4
X = ABCBDAB, Y = BDCABA
  LCS length = 4, one LCS = 'BCBA'

X = ACCGGTCGAGTGCGCGGAAGCCGGCCGAA, Y = GTCGTTCGGAATGCCGTTGCTCTGTAAA
  LCS length = 20, one LCS = 'GTCGTCGGAAGCCGGCCGAA'
```

This is exactly the LCS table worked out in CLRS Section 14.4.

## How to Run

```bash
python3 lcs.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
bottom-up table; do not switch to a recursive or memoized version.

## Think About

- Row `i` of the table is labelled with a character of `X`. Which character of `X` (by Python index)
  should row `i` correspond to, and which character does the code actually compare when it fills row
  `i`?
- The table has m+1 rows and n+1 columns. Which rows and columns does the loop actually fill? Look
  at the last row and column of the printed table.
- In the printed table, which character of `Y` gets no credit anywhere, and which character of `X`?
  What do those two characters have in common?
- Where does the program read the final answer from, and where should the answer to "LCS of all of
  `X` and all of `Y`" live in the table?
