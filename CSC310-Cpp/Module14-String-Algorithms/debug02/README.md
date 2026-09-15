# Knuth-Morris-Pratt Matching

**Course:** CSC310 &nbsp;|&nbsp; **Module 14:** String Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`computePrefixFunction` builds the KMP prefix function `pi` for a pattern (CLRS 32.4): `pi[q]` is the length of the longest proper prefix of the pattern that is also a suffix of the pattern's first `q + 1` characters. `kmpMatch` then scans the text once, using `pi` to decide how far to fall back after a mismatch, and reports every shift at which the pattern occurs. The driver prints `pi` for each pattern and every match with the text it matched.

## Expected Behavior

```
pattern "ababaca"  pi = 0 0 1 2 3 0 1
  in "abababacaba": shift 2 ("ababaca") 
pattern "ababb"  pi = 0 0 1 2 0
  in "ababbabb": shift 0 ("ababb") 
pattern "ababb"  pi = 0 0 1 2 0
  in "ababbababbabababb": shift 0 ("ababb") shift 5 ("ababb") shift 12 ("ababb") 
pattern "abaab"  pi = 0 0 1 1 2
  in "aabaabaaabaab": shift 1 ("abaab") shift 8 ("abaab") 
```

## How to Run

```bash
g++ -std=c++17 -Wall -o kmp kmp.cpp
./kmp
```

(on Windows: `kmp.exe` or `.\kmp.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The matcher is fine; the structure should stay as it is.

## Think About

- In `pi`, which prefix of the pattern does the entry at index `k` describe? When a comparison fails after `k` characters have matched, of which string does the algorithm need the longest border?
- Work out `pi` for `"ababb"` by hand. The whole pattern has no border at all, so its last entry must be 0. What does the program claim, and at which step does the hand computation diverge from the program's?
- The program reports a "match" whose text is `"bbabb"`. How can the matcher believe it has matched all five characters after reading text that does not spell the pattern? What does that say about the values it was given in `pi`?
