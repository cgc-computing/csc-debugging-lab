# Solution: Longest Common Subsequence Table

**Course/Module/Activity:** CSC310 · Module 9 Dynamic Programming · debug01
**Bug type(s):** runtime (out-of-range), logic (index mapping between the 1-based table and the 0-based strings)
**Bug count:** 1 misconception, present in two places (table fill and reconstruction)

## Observed Behavior

```
LCS("ABCBDAB", "BDCABA"): exception: basic_string
LCS("XMJYAUZ", "MZJAWXU"): exception: basic_string
LCS("AGGTAB", "GXTXAYB"): exception: basic_string
LCS("ABC", "DEF"): exception: basic_string
```

Every call throws `std::out_of_range` from `std::string::at` (libc++ reports it with the terse message `basic_string`; other standard libraries word it differently). Nothing is computed.

## The Bug(s)

`lcs.cpp`, `longestCommonSubsequence`.

1. Table fill:
   ```cpp
   if (X.at(i) == Y.at(j)) {
   ```
   should compare `X.at(i - 1)` with `Y.at(j - 1)`.
2. Reconstruction:
   ```cpp
   result.insert(result.begin(), X.at(i));
   ```
   should emit `X.at(i - 1)`.

## Why the Program Behaved Incorrectly

`c[i][j]` describes the prefixes of length `i` and `j`, so the "last" characters of those prefixes are `X[i-1]` and `Y[j-1]`. The loops run `i` from 1 to `m` and `j` from 1 to `n`; on the row `i = m`, `X.at(m)` is one past the end and throws. Before the exception, rows 1 through `m - 1` were filled by comparing the *wrong* characters (each shifted one place), so even if the exception were suppressed the table would describe the LCS of the two strings with their first characters removed. The reconstruction repeats the same shift.

## The Concept This Illustrates

Dynamic-programming tables are usually indexed by *problem size* (a prefix length), which is naturally 1-based with a row/column 0 for the empty prefix, while the data is 0-based. Translating CLRS's `x_i` (1-based) to C++ requires `X[i - 1]`. Students who copy the pseudocode literally either read one past the end or shift the whole comparison. The exception is a gift here: with `operator[]` the program would run and quietly print wrong answers.

## The Correction

```cpp
if (X.at(i - 1) == Y.at(j - 1)) {
    ...
if (b[i][j] == '\\') {
    result.insert(result.begin(), X.at(i - 1));
```

## Instructor Notes

- A common "fix" is to replace `.at()` with `[]`. That makes the exception disappear because `std::string::operator[](size())` legally returns the terminating `'\0'`, and the program prints `length 4, one LCS is "CBA "` and even `length 1, one LCS is " "` for two strings with nothing in common (the two terminators match each other). Use that output to argue that suppressing an error is not fixing it.
- Another "fix" is to shrink the loops to `i < m` and `j < n`. The table is then missing its last row and column, so the length is wrong for many inputs (try `"AGGTAB"` / `"GXTXAYB"`, whose LCS ends with the final `B`).
- Ask students to fix the fill only and run again: the third test still throws from the reconstruction (`b[6][7]` is a diagonal, so `X.at(6)` is evaluated). Two places, one misconception.
- The tie-break `c[i-1][j] >= c[i][j-1]` decides which of several equally long LCSs is printed; CLRS's choice gives `"BCBA"`. Students who use `>` will print `"BDAB"`—also a valid LCS, and a good moment to say the *length* is unique but the subsequence is not.
