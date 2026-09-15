# Longest Common Subsequence Table

**Course:** CSC310 &nbsp;|&nbsp; **Module 9:** Dynamic Programming &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`longestCommonSubsequence` implements LCS-LENGTH and PRINT-LCS from CLRS 14.4. It fills a table `c` with `m + 1` rows and `n + 1` columns, where `c[i][j]` is the length of an LCS of the first `i` characters of `X` and the first `j` characters of `Y`, records the direction of each choice in a second table `b`, and then walks `b` from the bottom-right corner to reconstruct one LCS.

## Expected Behavior

```
LCS("ABCBDAB", "BDCABA"): length 4, one LCS is "BCBA"
LCS("XMJYAUZ", "MZJAWXU"): length 4, one LCS is "MJAU"
LCS("AGGTAB", "GXTXAYB"): length 4, one LCS is "GTAB"
LCS("ABC", "DEF"): length 0, one LCS is ""
```

## How to Run

```bash
g++ -std=c++17 -Wall -o lcs lcs.cpp
./lcs
```

(on Windows: `lcs.exe` or `.\lcs.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the `.at()` accesses; they are there so that mistakes are reported instead of silently producing garbage.

## Think About

- The table has `m + 1` rows but `X` has only `m` characters. What does row 0 stand for, and which character of `X` does row `i` correspond to?
- The exception says an index was out of range. For which values of `i` or `j` can that happen, and what does it tell you about how table positions map to string positions?
- Once the table is right, the reconstruction follows a diagonal arrow at cell `(i, j)`. Which character of `X` should be emitted at that moment?
