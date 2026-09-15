# Solution: Longest Common Subsequence Table

**Course/Module/Activity:** CSC310 · Module 9 Dynamic Programming · debug01
**Bug type(s):** boundary (1-based table index vs 0-based string index)
**Bug count:** 1 misconception, expressed consistently in four places

## Observed Behavior

```
      B  D  C  A  B  A
    0  0  0  0  0  0  0
  A 0  0  0  0  1  1  0
  B 0  0  1  1  1  1  0
  C 0  0  1  1  2  2  0
  B 0  1  1  1  2  2  0
  D 0  1  1  2  2  3  0
  A 0  1  1  2  3  3  0
  B 0  0  0  0  0  0  0
X = ABCBDAB, Y = BDCABA
  LCS length = 3, one LCS = 'CBA'

X = ACCGGTCGAGTGCGCGGAAGCCGGCCGAA, Y = GTCGTTCGGAATGCCGTTGCTCTGTAAA
  LCS length = 19, one LCS = 'CGTTCGGAAGCCGGCCGAA'
```

The last row and last column of the table are all zero, the interior entries are shifted relative
to the row/column labels, and both answers are one short.

## The Bug(s)

`lcs.py`. The table is indexed 1..m / 1..n (CLRS style) but the strings are indexed 0..m-1 /
0..n-1 (Python style), and the code treats the two as the same:

```python
for i in range(1, m):            # should run to m (inclusive)
    for j in range(1, n):        # should run to n (inclusive)
        if X[i] == Y[j]:         # should compare X[i-1] with Y[j-1]
...
out.append(X[i])                 # should be X[i-1]
...
c[m - 1][n - 1] / build_lcs(b, X, m - 1, n - 1)   # should be c[m][n] and (m, n)
```

## Why the Program Behaved Incorrectly

Table entry `c[i][j]` is supposed to describe the prefixes of length `i` and `j`, whose *last*
characters are `X[i-1]` and `Y[j-1]`. Comparing `X[i]` with `Y[j]` instead means row `i` is really
about the prefix of length `i+1` while its recurrence reads `c[i-1][j-1]`, the prefix of length `i`,
so the character `X[0]` (and `Y[0]`) is never given a chance to match anything. The trimmed loop
bounds (`range(1, m)`) prevent the `IndexError` that `X[m]` would raise but leave the final row and
column at zero, so the program has to read its answer from `c[m-1][n-1]`. The net effect is that the
program computes an LCS of `X[1:]` and `Y[1:]`: for the textbook strings that drops the leading `A`
and `B`, and the LCS of `BCBDAB` and `DCABA` has length 3.

## The Concept This Illustrates

DP tables are usually padded with a row and column of base cases (index 0 = empty prefix), so the
table index is one greater than the corresponding sequence index. Translating CLRS's 1-based
pseudocode into a 0-based language requires deciding, once, what `c[i][j]` *means* and then
deriving every index from that meaning. Students holding this bug have the recurrence right but
have not pinned down the table's semantics, so they patch symptoms (the crash) rather than the
definition.

## The Correction

```python
# before
for i in range(1, m):
    for j in range(1, n):
        if X[i] == Y[j]:
...
out.append(X[i])
...
c[m - 1][n - 1], build_lcs(b, X, m - 1, n - 1)

# after
for i in range(1, m + 1):
    for j in range(1, n + 1):
        if X[i - 1] == Y[j - 1]:
...
out.append(X[i - 1])
...
c[m][n], build_lcs(b, X, m, n)
```

## Instructor Notes

- Students who fix only the loop bounds get `IndexError: string index out of range`; that is the
  crash the original author "fixed" by trimming the loops. Use it to talk about fixing causes rather
  than symptoms.
- Students who fix the comparison but not `build_lcs` get the right length and a wrong string
  (or an `IndexError` at `X[m]`). Ask what the `diag` entry at `(i, j)` records.
- An alternative consistent design pads the *strings* instead (`X = " " + X`) and keeps `X[i]`; it
  is legitimate but ask them to rewrite `print_table` to match.
- Follow-up: why does the recurrence need the 0 row and column at all, and what would a version
  without padding have to special-case?
