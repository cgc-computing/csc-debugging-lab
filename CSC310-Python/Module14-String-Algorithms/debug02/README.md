# Knuth-Morris-Pratt Matching

**Course:** CSC310 &nbsp;|&nbsp; **Module 14:** String Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`kmp.py` implements the Knuth-Morris-Pratt matcher (CLRS Section 32.4). `compute_prefix_function`
builds the list `pi`, where `pi[q]` is the length of the longest proper prefix of the pattern that is
also a suffix of `pattern[:q + 1]`. `kmp_match` then scans the text once, using `pi` to decide how far
to fall back after a mismatch, and reports every shift at which the pattern occurs. The `main` block
prints `pi` for three patterns and the matches found in a few texts, showing the matched text in
parentheses so you can check it.

## Expected Behavior

```
pattern "ababaca"  pi = 0 0 1 2 3 0 1
  in "abababacaba": shift 2 ("ababaca")
pattern "ababb"  pi = 0 0 1 2 0
  in "ababbabb": shift 0 ("ababb")
  in "ababbababbabababb": shift 0 ("ababb") shift 5 ("ababb") shift 12 ("ababb")
pattern "abacabab"  pi = 0 0 1 0 1 2 3 2
  in "abacababacabab": shift 0 ("abacabab") shift 6 ("abacabab")
```

The first `pi` is the one CLRS works out for `ababaca`. Every reported match should show the pattern
itself in parentheses.

## How to Run

```bash
python3 kmp.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep both
functions; the matcher's structure is fine.

## Think About

- `pi[4]` for `"ababb"` is reported as 2, which claims that `"ab"` is both a proper prefix and a suffix
  of `"ababb"`. Is it? Work out the correct value by hand, and then do the same for `pi[7]` of
  `"abacabab"`.
- Inside `compute_prefix_function`, `k` is a *length* (the current candidate border) while `pi` is
  indexed by *position*. When the comparison fails, the algorithm needs the longest border of a shorter
  prefix. Which prefix exactly, and which entry of `pi` describes it?
- The false match at shift 3 (`"bbabb"`) follows directly from the incorrect `pi`. Trace `kmp_match` from
  the moment the match at shift 0 completes: what does `q` become, and what does the algorithm now
  believe about the last few text characters it has read?
- `"ababaca"` comes out right even in the program as given. Look at how its `pi` is built: why does the
  mistake make no difference for this pattern?
