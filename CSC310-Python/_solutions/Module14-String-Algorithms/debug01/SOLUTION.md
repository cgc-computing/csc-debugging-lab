# Solution: Naive String Matching

**Course/Module/Activity:** CSC310 · Module 14 String Algorithms · debug01
**Bug type(s):** boundary (exclusive `range` bound used for an inclusive pseudocode bound)
**Bug count:** 1

## Observed Behavior

```
"abra" in "abracadabra": 1 match at shift 0
"aa" in "aaaaa": 3 matches at shifts 0 1 2
"world" in "hello world": no match
"issi" in "mississippi": 2 matches at shifts 1 4
"abcd" in "abc": no match
"nan" in "banana": 1 match at shift 2
"abc" in "abc": no match
```

Every match that ends flush with the end of the text is missed: shift 7 for `"abra"`, shift 3 for
`"aa"`, shift 6 for `"world"`, shift 0 for `"abc"`.

## The Bug(s)

`naive_match.py`, function `naive_match`:

```python
for s in range(n - m):        # tries s = 0 .. n-m-1; should be range(n - m + 1)
```

## Why the Program Behaved Incorrectly

CLRS's loop is `for s = 0 to n − m`, an *inclusive* upper bound: there are `n − m + 1` shifts at which
an `m`-character pattern fits inside an `n`-character text. Python's `range(n - m)` stops one short, so
the last possible shift, `s = n − m` — the only one where the pattern ends exactly at the end of the
text — is never compared. Any occurrence elsewhere is still found, which is why `"issi"` and `"nan"`
come out right and the bug is easy to miss with casual testing.

## The Concept This Illustrates

The count of valid shifts is `n − m + 1`, and it is the basis of the naive matcher's running time
Θ((n − m + 1)m). Translating an inclusive pseudocode bound to `range` requires adding one; students
who "know" that `range(k)` has `k` elements sometimes still write the pseudocode's upper limit
verbatim. The last shift is precisely the boundary case that a good test set must contain.

## The Correction

```python
# before
for s in range(n - m):

# after
for s in range(n - m + 1):
```

## Instructor Notes

- When `m > n`, `range(n - m + 1)` is empty (a non-positive stop), so the corrected loop does no
  comparisons and there is no index error. Some students add `if m > n: return []`; harmless, but ask
  them whether it is needed.
- A tempting alternative "fix" is `for s in range(n)` together with slicing (`text[s:s+m] == pattern`),
  which works only because slices silently truncate; with the character loop it raises `IndexError`.
  Ask which version is the honest translation of the pseudocode.
- Have students confirm `len(range(n - m + 1)) == n - m + 1` for a few values, and connect it to the
  Θ((n − m + 1)m) bound.
- Follow-up: which of the seven cases would still detect this bug if the test suite had only one
  case? Any case whose only occurrence is at the last shift (`"world"` or `"abc"`).
