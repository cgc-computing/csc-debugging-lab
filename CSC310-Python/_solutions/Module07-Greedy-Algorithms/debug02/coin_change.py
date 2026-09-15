"""Making change with the fewest coins.

The greedy rule "always take the largest coin that still fits" is
optimal for canonical coin systems such as US coins {1, 5, 10, 25}, but
not for every set of denominations.  make_change therefore verifies the
denomination set before trusting the greedy answer:

    Kozen and Zaks (1994): if greedy is not optimal for some amount, then
    the smallest counterexample is less than c_k + c_(k-1), the sum of the
    two largest coins.  Checking every amount below that bound against an
    exhaustive search decides whether the system is canonical.

For a non-canonical system the exhaustive search is used directly.  The
amounts involved are small, so the search is fast enough here.
"""


def greedy_change(amount, coins):
    """coins sorted in decreasing order; every system contains 1."""
    result = []
    for c in coins:
        while amount >= c:
            result.append(c)
            amount -= c
    return result


def fewest_coins(amount, coins):
    """Exhaustive search: the shortest list of coins summing to amount."""
    if amount == 0:
        return []
    best = None
    for c in coins:
        if c <= amount:
            candidate = [c] + fewest_coins(amount - c, coins)
            if best is None or len(candidate) < len(best):
                best = candidate
    return best


def is_canonical(coins):
    """True if the greedy rule is optimal for every amount with these coins."""
    if len(coins) < 2:
        return True
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


def main():
    systems = [
        ([25, 10, 5, 1], [63, 30]),
        ([4, 3, 1], [6, 10, 7]),
    ]
    for coins, amounts in systems:
        print(f"denominations {coins}")
        for amount in amounts:
            change = make_change(amount, coins)
            print(f"  amount {amount:>2} -> {len(change)} coins: {change}")


if __name__ == "__main__":
    main()
