# Solution: Naive String Matching

**Course/Module/Activity:** CSC310 · Module 14 String Algorithms · debug01
**Bug type(s):** boundary (off-by-one in the shift range)
**Bug count:** 1

## Observed Behavior

```
"abra" in "abracadabra": 1 match at shift 0
"aa" in "aaaaa": 3 matches at shifts 0 1 2
"world" in "hello world": no match
"issi" in "mississippi": 2 matches at shifts 1 4
"abcd" in "abc": no match
"nan" in "banana": 1 match at shift 2
```

Any match that ends at the last character of the text is missed: `abra` at 7, `aa` at 3, `world` at 6.

## The Bug(s)

`naive_match.cpp`, `naiveMatch`:

```cpp
for (int s = 0; s < n - m; ++s) {
```

The valid shifts are `0 .. n - m` inclusive; the loop stops one early. CLRS writes `for s = 0 to n - m`.

## Why the Program Behaved Incorrectly

At shift `s` the pattern occupies text positions `s .. s + m - 1`, which fit as long as `s + m - 1 <= n - 1`, i.e. `s <= n - m`. With `s < n - m` the final shift—the only one at which a match can end on the last text character—is never examined. Cases whose matches all end earlier (`issi`, `nan`) are unaffected, which makes the bug easy to miss in casual testing.

## The Concept This Illustrates

Translating an inclusive mathematical range (`0 ≤ s ≤ n − m`) into a half-open C++ loop requires `<=` or an adjusted bound; the reflex to write `<` (correct for `0 ≤ s < n`) produces an off-by-one at the far end. In string algorithms the boundary is where the interesting cases live: a pattern that ends exactly at the end of the text is common (file suffixes, line endings) and is the case a test suite should always include. The same `n - m` boundary reappears in Rabin-Karp and in KMP's final-match handling.

## The Correction

```cpp
for (int s = 0; s <= n - m; ++s) {
```

## Instructor Notes

- Students sometimes "fix" it as `s < n - m + 1`—equivalent and fine, but ask them to state the inclusive range in words.
- Another "fix" is `s < n`, which relies on `.at()` throwing to stop the overrun; in this program that turns the last cases into `std::out_of_range` exceptions. Good moment to talk about why bounds should be right rather than caught.
- Ask what happens when `m > n` (`"abcd"` in `"abc"`): `n - m` is negative, the loop does not run, and the answer "no match" is correct for free. Ask what would break if `n` and `m` were `size_t`.
- Follow-up: count character comparisons for `"aa"` in `"aaaaa"` and relate to the O((n − m + 1) m) bound.
