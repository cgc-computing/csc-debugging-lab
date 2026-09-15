# Solution: Knuth-Morris-Pratt Matching

**Course/Module/Activity:** CSC310 · Module 14 String Algorithms · debug02
**Bug type(s):** logic (index translation from CLRS's 1-based `π[k]` to a 0-based array)
**Bug count:** 1

## Observed Behavior

```
pattern "ababaca"  pi = 0 0 1 2 3 0 1
  in "abababacaba": shift 2 ("ababaca") 
pattern "ababb"  pi = 0 0 1 2 2
  in "ababbabb": shift 0 ("ababb") shift 3 ("bbabb") 
pattern "ababb"  pi = 0 0 1 2 2
  in "ababbababbabababb": shift 0 ("ababb") shift 5 ("ababb") shift 12 ("ababb") 
pattern "abaab"  pi = 0 0 1 1 2
  in "aabaabaaabaab": shift 1 ("abaab") shift 8 ("abaab") 
```

For `"ababb"` the last prefix-function value is 2 instead of 0, and the matcher reports a false match at shift 3 whose text is `"bbabb"`. The other patterns come out right by coincidence. For some patterns not in the driver (e.g., `"aab"`) the buggy program hangs.

## The Bug(s)

`kmp.cpp`, `computePrefixFunction`, the fallback inside the `while`:

```cpp
while (k > 0 && P.at(k) != P.at(q)) {
    k = pi.at(k);          // should be pi.at(k - 1)
}
```

CLRS writes `k = π[k]` with 1-based arrays, where `π[k]` is the border length of the prefix of length `k`. In a 0-based array the prefix of length `k` is described by `pi[k - 1]`.

## Why the Program Behaved Incorrectly

For `"ababb"` the hand computation gives `pi = 0 0 1 2 0`. The program agrees up to `q = 3` (`pi[3] = 2`, so `k = 2` when `q = 4` begins). At `q = 4`, `P[2] = 'a'` differs from `P[4] = 'b'`, so the algorithm must fall back to the longest border of the *matched* prefix `"ab"` (length `k = 2`), which is `pi[1] = 0`; with `k = 0` the final comparison `P[0] = 'a'` vs `'b'` fails and `pi[4] = 0`. The buggy code reads `pi[2] = 1` instead—the border of `"aba"`, a prefix that was *not* matched—so it retries with `k = 1`: `P[1] = 'b'` equals `P[4]`, `k` becomes 2, and `pi[4] = 2` is recorded even though `"ababb"` has no border. In the matcher, a wrong `pi[4] = 2` means that after a full match the automaton believes the last two text characters spell `"ab"`; reading `"abb"` next takes it to state 5 and it reports a match for `"bbabb"`. For patterns such as `"aab"` (`pi[1] = 1`), `k = pi[1]` leaves `k` unchanged and the `while` never terminates.

## The Concept This Illustrates

The prefix function is a chain of borders: to shrink a border of length `k` you consult the border of the *length-`k` prefix*. Getting the index right is not cosmetic—`pi[k]` and `pi[k - 1]` describe different strings. This is the same 1-based/0-based translation issue as in the LCS table (Module 9), now inside a while-loop whose termination depends on `k` strictly decreasing. Students who "port" pseudocode index-for-index produce a function that is right for many patterns, wrong for some, and non-terminating for others—a good illustration that partial agreement with the textbook example proves little.

## The Correction

```cpp
while (k > 0 && P.at(k) != P.at(q)) {
    k = pi.at(k - 1);
}
```

## Instructor Notes

- Have students compute `pi` for `"ababb"` by hand *before* looking at the loop; the divergence at `q = 4` is where the discussion should happen.
- If a student tries pattern `"aab"` or `"aaaa"` the buggy program hangs. That is not a driver case, but it is a great prompt: "why does the loop rely on `k` decreasing, and does `pi[k] < k` always hold?" (`pi[k] ≤ k`, with equality possible; `pi[k - 1] ≤ k - 1 < k` never stalls.)
- The matcher's own fallback `q = pi.at(q - 1)` is already correct; some students "fix" the wrong function to make them look alike (changing the matcher to `pi[q]`), which throws for `q = m`. Ask which of the two loops the driver's output implicates.
- Follow-up: show that the total number of `k` decrements is bounded by the number of increments (amortized O(m)), and that this argument *also* needs `pi[k - 1] < k`.
