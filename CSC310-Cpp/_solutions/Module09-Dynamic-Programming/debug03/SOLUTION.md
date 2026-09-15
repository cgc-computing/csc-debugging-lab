# Solution: Rod Cutting with Memoization

**Course/Module/Activity:** CSC310 · Module 9 Dynamic Programming · debug03
**Bug type(s):** logic (memo sentinel collides with a legitimate value), boundary (recurrence omits the "no cut" option)
**Bug count:** 2 related (both concern the values the recurrence ranges over: its initial/"unknown" value and its last case)

## Observed Behavior

```
length 1: revenue 0, pieces:   (1 calls)
length 2: revenue 0, pieces:   (1 calls)
length 3: revenue 0, pieces:   (1 calls)
length 4: revenue 0, pieces:   (1 calls)
length 7: revenue 0, pieces:   (1 calls)
length 10: revenue 0, pieces:   (1 calls)
length 13: revenue 0, pieces:   (1 calls)
```

Every rod is worth 0, no pieces are listed, and each query makes exactly one call.

After fixing only the first bug the program runs the recursion but still gets every answer wrong:

```
length 1: revenue -1, pieces:   (1 calls)
length 2: revenue 0, pieces: 1   (2 calls)
length 3: revenue 4, pieces: 2   (4 calls)
length 10: revenue 24, pieces: 3 6   (46 calls)
```

## The Bug(s)

`rod_cutting.cpp`.

1. `cutRod` initializes the memo with 0:
   ```cpp
   std::vector<int> memo(n + 1, 0);
   ```
   while `cutRodAux` treats any non-negative entry as already computed (`if (memo.at(n) >= 0) return memo[n];`). CLRS initializes `r[i] = -∞` for exactly this reason.
2. `cutRodAux`'s loop over the first piece stops one short:
   ```cpp
   for (int i = 1; i < std::min(n, MAX_PIECE); ++i) {
   ```
   It never tries `i == n`, i.e. selling the rod whole (or, for `n > 10`, the longest piece).

## Why the Program Behaved Incorrectly

With the memo full of zeros, the very first test `memo[n] >= 0` succeeds, so `cutRodAux` returns 0 immediately—one call, no recursion, no first piece recorded, so the piece list is empty. The sentinel and a legitimate revenue (0 for a rod of length 0) are indistinguishable.

Once the sentinel is `-1`, the recursion runs, but for `n = 1` the loop `for i = 1; i < 1` executes zero times, so `best` stays at its starting value `-1` and `memo[1] = -1`. Every larger `n` builds on that: `r(2) = p(1) + r(1) = 0`, `r(3) = max(p(1) + r(2), p(2) + r(1)) = 4` instead of 8, and the rod of length 10 is never sold whole (`30`) because `i = 10` is skipped, giving 24. The `-1` also happens to be the "unknown" sentinel, so `memo[1]` is recomputed on every visit—visible as slightly higher call counts.

## The Concept This Illustrates

Two habits of careful DP:

- **The "unknown" marker must be outside the range of real answers.** CLRS uses −∞ and tests `r[n] ≥ 0`; a student who "simplifies" to 0 has made the base case and the sentinel identical. In general, choose a sentinel the recurrence can never produce (here `-1`, since revenues are ≥ 0), or keep a separate `computed` flag.
- **The recurrence must include all of its cases.** `r_n = max(p_n, r_1 + r_{n-1}, …)`—the `p_n` term is the whole rod. Writing the loop as `i < n` drops it, and the error propagates to every larger `n` through the memo. Boundary mistakes in a DP are not local: one wrong base or one missing case poisons the whole table.

## The Correction

```cpp
std::vector<int> memo(n + 1, -1);
...
for (int i = 1; i <= std::min(n, MAX_PIECE); ++i) {
```

## Instructor Notes

- Students often fix the sentinel by changing the test to `memo[n] > 0`. Ask what happens to `memo[0]` (recomputed forever—harmless here) and what would happen if some rod really were worth 0 (a price table with a 0 entry); the fix works by accident.
- The intermediate output (`revenue -1` for length 1) is a good prompt: "Where did −1 come from, and why does `-1` propagate into `length 2: revenue 0`?"
- Ask why the call counts are `2, 4, 7, 11, …` for `n = 1, 2, 3, 4`: with memoization each `n` is computed once and each of its `n` subproblems is *called* once, so calls ≈ 1 + n(n+1)/2 for a fresh memo. Without memoization the count doubles with each unit of length—have students comment out the memo and try `n = 25`.
- The corrected output `length 13: pieces: 3 10` shows why rods longer than 10 must be cut: `MAX_PIECE` bounds the first piece, not the rod.
