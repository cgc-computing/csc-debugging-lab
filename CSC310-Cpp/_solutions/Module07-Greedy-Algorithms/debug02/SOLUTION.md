# Solution: Making Change with the Fewest Coins

**Course/Module/Activity:** CSC310 · Module 7 Greedy Algorithms · debug02
**Bug type(s):** conceptual/design (algorithm choice: greedy where the greedy-choice property does not hold)
**Bug count:** 1

## Observed Behavior

```
amount 63 with {1, 5, 10, 25}: 6 coins -> 25 25 10 1 1 1
amount 30 with {1, 5, 10, 25}: 2 coins -> 25 5
amount 6 with {1, 3, 4}: 3 coins -> 4 1 1
amount 10 with {1, 3, 4}: 4 coins -> 4 4 1 1
amount 8 with {1, 4, 5}: 4 coins -> 5 1 1 1
amount 88 with {1, 2, 5, 10, 20, 50}: 6 coins -> 50 20 10 5 2 1
```

The two US-coin cases and the {1, 2, 5, 10, 20, 50} case are right; the three unusual denomination sets get too many coins (3 instead of 2, 4 instead of 3, 4 instead of 2).

## The Bug(s)

`coin_change.cpp`, `fewestCoins`. The whole function is a greedy loop—repeatedly take the largest denomination that still fits:

```cpp
std::sort(denoms.begin(), denoms.end(), std::greater<int>());
int remaining = amount;
for (int d : denoms) {
    while (remaining >= d) {
        coins.push_back(d);
        remaining -= d;
    }
}
```

There is no single wrong line; the *algorithm* is wrong for the problem as stated. Greedy change-making is optimal only for **canonical** coin systems, and {1, 3, 4} and {1, 4, 5} are not canonical.

## Why the Program Behaved Incorrectly

For {1, 3, 4} and amount 6 the greedy loop takes a 4 (remaining 2), cannot take a 3, then takes two 1s: three coins. But 3 + 3 also makes 6 with two coins. Taking the largest coin first is irrevocable in the greedy loop, and here that first choice is not part of any optimal solution—the greedy-choice property fails. The same happens for 10 = 4 + 4 + 1 + 1 (optimal 4 + 3 + 3) and, with {1, 4, 5}, 8 = 5 + 1 + 1 + 1 (optimal 4 + 4). The US denominations happen to be canonical, so greedy is correct there and the failure is invisible.

## The Concept This Illustrates

Greedy algorithms need two things: optimal substructure *and* the greedy-choice property. Change-making has optimal substructure (an optimal solution for `amount` contains an optimal solution for `amount - d`), which is exactly what dynamic programming exploits. But the greedy choice "largest coin first" is only guaranteed to be in an optimal solution for special denomination sets (every US and Euro system is one). Students who have seen greedy coin change in an earlier course tend to believe it is *the* algorithm; this activity makes them articulate the property that justifies it and notice when it is missing. The right fix is to change algorithms, not to patch the loop.

## The Correction

Replace the greedy loop with the bottom-up recurrence `best[a] = 1 + min over d <= a of best[a - d]`, recording which coin achieved the minimum so the combination can be listed:

```cpp
std::vector<int> best(amount + 1, NONE), choice(amount + 1, 0);
best[0] = 0;
for (int a = 1; a <= amount; ++a)
    for (int d : denoms)
        if (d <= a && best[a - d] + 1 < best[a]) { best[a] = best[a - d] + 1; choice[a] = d; }
for (int a = amount; a > 0; a -= choice[a]) coins.push_back(choice[a]);
```

The full corrected file sits beside this document. Running time is O(amount × |denoms|).

## Instructor Notes

- Expect some students to argue the program is "correct because it always makes change". Push on the word *fewest* in the header comment and the README.
- An acceptable alternative "fix" is to keep the greedy loop but *check* that the denomination set is canonical (e.g., by comparing greedy against the DP answer for all amounts up to the sum of the two largest coins, which is a known sufficient range—Kozen & Zaks 1994), and refuse or fall back to DP otherwise. That is a good discussion of when a fast greedy method is trustworthy. Do not accept special-casing the sample inputs.
- Ask for the *smallest* amount on which greedy fails for {1, 3, 4} (it is 6) and for {1, 4, 5} (8). Hunting for the counterexample is the point of the exercise.
- Connect to Module 9: the corrected function is a dynamic program; students will meet the same recurrence shape in rod cutting.
- The corrected program lists coins in descending order after sorting; if a student's DP produces `3 3 4` for amount 10, that is fine—only the count is uniquely determined.
