# Solution: Making Change With the Fewest Coins

**Course/Module/Activity:** CSC310 · Module 7 Greedy Algorithms · debug02
**Bug type(s):** conceptual/design (algorithm choice: the greedy-choice property does not hold)
**Bug count:** 1

## Observed Behavior

```
denominations [25, 10, 5, 1]
  amount 63 -> 6 coins: [25, 25, 10, 1, 1, 1]
  amount 30 -> 2 coins: [25, 5]
denominations [4, 3, 1]
  amount  6 -> 3 coins: [4, 1, 1]
  amount 10 -> 4 coins: [4, 4, 1, 1]
  amount  7 -> 2 coins: [4, 3]
```

The US-coin results are optimal. For {1, 3, 4}, amount 6 is made with three coins (optimum is two:
3 + 3) and amount 10 with four (optimum is three: 4 + 3 + 3). Amount 7 happens to be right.

## The Bug(s)

There is no faulty line: the *algorithm* is wrong for the problem as stated. `make_change` applies
the greedy rule (largest coin first) to every denomination system and presents the result as the
minimum. The header comment's justification, "each choice reduces the amount as much as possible,
so the coin count is as small as possible", is false in general.

## Why the Program Behaved Incorrectly

With coins {4, 3, 1} and amount 6, the greedy step takes a 4, leaving 2, which can only be made with
1 + 1. The optimal solution never uses a 4 at all. The greedy rule commits to a locally attractive
choice that no optimal solution contains, so the remaining subproblem is one whose optimum is worse.
For US coins the greedy choice *is* always contained in some optimal solution (each coin is a
multiple, or nearly so, of the next smaller one, so any solution using several small coins can be
exchanged for one larger coin without increasing the count), which is why those amounts come out
right.

## The Concept This Illustrates

CLRS Section 15.2: a greedy algorithm is correct only when the problem has the **greedy-choice
property** (a locally optimal choice is part of some globally optimal solution) and **optimal
substructure**. Coin change has optimal substructure but the greedy-choice property depends on the
denominations. Systems for which greedy is optimal are called *canonical*; {1, 5, 10, 25} is
canonical, {1, 3, 4} is not (the coin-changing problem at the end of CLRS Chapter 15 explores exactly this). When the greedy-choice
property fails, the fallback is dynamic programming or exhaustive search over the subproblems, which
is the subject of the next module.

## The Correction

The corrected file keeps the greedy routine and adds two things:

```python
def is_canonical(coins):
    # Kozen & Zaks (1994): if greedy is ever non-optimal, the smallest
    # counterexample is below c_k + c_(k-1); check every amount up to there.
    bound = coins[0] + coins[1]
    for amount in range(1, bound):
        if len(greedy_change(amount, coins)) != len(fewest_coins(amount, coins)):
            return False
    return True

def make_change(amount, coins):
    coins = sorted(coins, reverse=True)
    if is_canonical(coins):
        return greedy_change(amount, coins)
    return sorted(fewest_coins(amount, coins), reverse=True)
```

`fewest_coins` is a plain exhaustive recursion (try each coin, keep the shortest completion). It is
exponential but the amounts in this activity are tiny. Students who have already seen memoization
may add a memo table; that is a preview of Module 9, not a requirement.

## Instructor Notes

- The intended discussion is *not* "find the typo". Steer groups toward "for which inputs is the
  claim in the header comment true, and how would you check?"
- Some students "fix" the program by reordering or filtering the coin list for {1, 3, 4}
  (e.g., dropping the 4). Ask what happens for amount 8 (4 + 4 is optimal).
- Others hard-code a special case for amount 6. Ask about amount 10 and 13.
- An acceptable alternative correction is to replace `make_change` entirely with the exhaustive
  or DP version and drop the greedy routine; if so, ask why the greedy version is still preferable
  for canonical systems (linear in the number of coins, versus O(amount × k)).
- The Kozen–Zaks bound can be stated without proof; the point is that "canonical" is a checkable
  property, so the program can be made correct *and* keep the fast path.
- Amount 7 is included deliberately: greedy is right there, so students see that being right on
  some inputs proves nothing.
