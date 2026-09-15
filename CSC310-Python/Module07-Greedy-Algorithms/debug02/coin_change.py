"""Making change with the fewest coins.

make_change applies the greedy rule: always take the largest coin that
still fits, and repeat until the remaining amount is zero.  Each choice
reduces the amount as much as possible, so the coin count is as small as
possible.
"""


def greedy_change(amount, coins):
    """coins sorted in decreasing order; every system contains 1."""
    result = []
    for c in coins:
        while amount >= c:
            result.append(c)
            amount -= c
    return result


def make_change(amount, coins):
    coins = sorted(coins, reverse=True)
    return greedy_change(amount, coins)


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
