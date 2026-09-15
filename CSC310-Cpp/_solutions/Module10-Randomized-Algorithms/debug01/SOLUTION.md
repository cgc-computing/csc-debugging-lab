# Solution: Checking a Shuffle for Uniformity

**Course/Module/Activity:** CSC310 · Module 10 Randomized Algorithms · debug01
**Bug type(s):** conceptual/design (probability: wrong range for the random swap partner)
**Bug count:** 1

## Observed Behavior

```
shuffles of 3 elements: 108000   (expected per permutation: 18000)
  012:  23710  (+5710)
  021:  23910  (+5910)
  102:  12130  (-5870)
  120:  12090  (-5910)
  201:  24090  (+6090)
  210:  12070  (-5930)
largest deviation from expected: 6090
permutations seen: 6 of 6
```

Three permutations appear about twice as often as the other three (≈24 000 vs ≈12 000). Exact counts vary by standard library, but the 2:1 pattern does not.

## The Bug(s)

`shuffle_tally.cpp`, `shuffle`:

```cpp
for (int i = n - 1; i > 0; --i) {
    std::uniform_int_distribution<int> pick(0, n - 1);
```

The swap partner is drawn from the whole vector every time. RANDOMIZE-IN-PLACE draws it from the still-unsettled prefix, i.e. from `0..i`.

## Why the Program Behaved Incorrectly

The loop runs for `i = 2` and `i = 1`, each time choosing one of 3 positions, so there are 3 × 3 = 9 equally likely random outcomes. Nine outcomes cannot be spread evenly over 6 permutations: three permutations are reached by two outcomes each (probability 2/9 ≈ 24 000 of 108 000) and three by one outcome each (1/9 ≈ 12 000). A correct run draws from 3 positions and then from 2, giving 3 × 2 = 6 equally likely outcomes—one per permutation.

The general principle: a correct shuffle of `n` elements must generate exactly `n!` equally likely outcomes (or a multiple of `n!`); a loop that draws from `n` positions `n - 1` times produces `n^(n-1)` outcomes, which is not a multiple of `n!` for any `n ≥ 3`.

## The Concept This Illustrates

Randomized algorithms are correct only if their probability distribution is what the analysis assumes. CLRS proves RANDOMIZE-IN-PLACE uniform with a loop invariant: before iteration `i`, the settled suffix contains each possible arrangement with equal probability, and drawing the next element uniformly from the *unsettled* positions extends the invariant. Drawing from *all* positions can disturb an element that was already settled and destroys the invariant. Students tend to accept any procedure that "looks random"; this activity shows that a bias of this size is invisible in one run but obvious in a tally, and that a counting argument (9 vs 6 outcomes) explains it exactly.

## The Correction

```cpp
for (int i = n - 1; i > 0; --i) {
    std::uniform_int_distribution<int> pick(0, i);
    int j = pick(rng);
    std::swap(a[i], a[j]);
}
```

## Instructor Notes

- A classic wrong "fix" is to draw from `0..n-1` but run the loop for all `n` positions (`i = n - 1` down to 0). That gives 27 outcomes over 6 permutations: 4/27 vs 5/27, i.e. ≈16 000 vs ≈20 000. It looks *closer* to uniform and students may declare victory—ask them to explain 27 mod 6.
- `std::shuffle(a.begin(), a.end(), rng)` is the library version of the correct algorithm; a fine follow-up is to swap it in and check that the tallies stay within noise (they will differ from the sample because it consumes the generator differently).
- The counts printed by the sample were produced by Apple's libc++. `std::uniform_int_distribution` is unspecified across implementations, so libstdc++/MSVC give different exact counts; the *pattern* (2:1 in the buggy program, all within a few hundred in the fixed one) is what to check.
- For a larger discussion: why is it wrong to sort with a random comparator, and how would you tally-test `std::sort` with one?
