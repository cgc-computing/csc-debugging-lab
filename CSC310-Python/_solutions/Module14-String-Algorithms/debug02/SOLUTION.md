# Solution: Knuth-Morris-Pratt Matching

**Course/Module/Activity:** CSC310 · Module 14 String Algorithms · debug02
**Bug type(s):** boundary (fallback indexes `pi` by length instead of by position), logic
**Bug count:** 1

## Observed Behavior

```
pattern "ababaca"  pi = 0 0 1 2 3 0 1
  in "abababacaba": shift 2 ("ababaca")
pattern "ababb"  pi = 0 0 1 2 2
  in "ababbabb": shift 0 ("ababb") shift 3 ("bbabb")
  in "ababbababbabababb": shift 0 ("ababb") shift 5 ("ababb") shift 12 ("ababb")
pattern "abacabab"  pi = 0 0 1 0 1 2 3 0
  in "abacababacabab": shift 0 ("abacabab")
```

`pi[4]` of `ababb` is 2 instead of 0 and produces a *false* match (`"bbabb"` is not the pattern);
`pi[7]` of `abacabab` is 0 instead of 2 and the overlapping occurrence at shift 6 is *missed*. The
textbook pattern is unaffected.

## The Bug(s)

`kmp.py`, function `compute_prefix_function`:

```python
while k > 0 and pattern[k] != pattern[q]:
    k = pi[k]                 # should be pi[k - 1]
```

## Why the Program Behaved Incorrectly

`k` is the length of the current candidate border, i.e. the candidate is `pattern[:k]`, whose last
position is `k − 1`. The longest border of that prefix is `pi[k - 1]`. `pi[k]` instead describes
`pattern[:k + 1]`, a *longer* prefix, so the fallback can land on a value that is too large or too
small. For `ababb` at `q = 4`: `k = pi[3] = 2`, `pattern[2] = 'a' ≠ 'b'`, and the code falls back to
`pi[2] = 1` (correct: `pi[1] = 0`); then `pattern[1] = 'b'` matches and `pi[4]` becomes 2, asserting
that `"ab"` is a suffix of `"ababb"`. In the matcher, after the match at shift 0 the state is reset to
`q = pi[4] = 2`, so the algorithm believes the last two text characters `"bb"` already match `"ab"`,
and three more matching characters yield the phantom match at shift 3. For `abacabab` the wrong
fallback goes the other way (`pi[3] = 0` instead of `pi[2] = 1`), `pi[7]` becomes 0 instead of 2, and
after the match at shift 0 the matcher forgets the overlap `"ab"` and misses shift 6. `ababaca` is
unaffected because each of its fallbacks happens to reach the same value either way.

## The Concept This Illustrates

The prefix function is indexed by *position* `q` (it describes `P[0..q]`), while the running variable
`k` is a *length*. Moving from a border of length `k` to the next shorter border means looking up the
entry for the prefix of length `k`, which ends at position `k − 1`. In CLRS's 1-based pseudocode the
lookup is `π[k]` because there the `k`-character prefix ends at position `k`; a faithful 0-based
translation must shift the index. The matcher already does this correctly (`q = pi[q - 1]`), which is
the consistency check a student can make.

## The Correction

```python
# before
while k > 0 and pattern[k] != pattern[q]:
    k = pi[k]

# after
while k > 0 and pattern[k] != pattern[q]:
    k = pi[k - 1]
```

## Instructor Notes

- The shipped patterns were chosen so that the buggy program terminates. With a pattern that starts
  with two equal characters (`pi[1] = 1`), `k = pi[k]` with `k = 1` never changes and the buggy
  function hangs; try `"aab"`. Use it to show that the same off-by-one can be a wrong answer or an
  infinite loop depending on the data, and ask students to explain why `pi[k - 1] < k` always
  guarantees termination.
- Students who instead "fix" the matcher (changing `q = pi[q - 1]` to `q = pi[q]`) break the correct
  half; the printed `pi` values still disagree with hand computation, which is the tell.
- Have students compute `pi` for `ababb` by hand using the definition, then step through the loop
  with both index choices.
- Follow-up: why is the amortized cost of the `while` loop O(m) overall? The argument depends on `k`
  strictly decreasing during fallback — which is exactly what the correct index guarantees.
