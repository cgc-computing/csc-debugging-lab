"""0/1 knapsack with a one-dimensional DP table.

Each item may be taken at most once.  dp[w] holds the best value
achievable with capacity exactly w using the items processed so far.
The two-dimensional table of CLRS's 0-1 knapsack exercise is compressed to one
row by updating it in place, one item at a time.  A brute-force checker
over all subsets confirms the answer for these small instances.
"""

from itertools import combinations


def knapsack(weights, values, capacity):
    dp = [0] * (capacity + 1)
    for wt, val in zip(weights, values):
        for w in range(wt, capacity + 1):
            dp[w] = max(dp[w], dp[w - wt] + val)
    return dp[capacity]


def brute_force(weights, values, capacity):
    n = len(weights)
    best = 0
    for k in range(n + 1):
        for chosen in combinations(range(n), k):
            if sum(weights[i] for i in chosen) <= capacity:
                best = max(best, sum(values[i] for i in chosen))
    return best


def report(name, weights, values, capacity):
    got = knapsack(weights, values, capacity)
    want = brute_force(weights, values, capacity)
    print(f"{name}: weights {weights}, values {values}, capacity {capacity}")
    print(f"  dp value = {got}   brute force = {want}   match = {got == want}")


def main():
    report("instance A", [10, 20, 30], [60, 100, 120], 50)
    report("instance B", [2, 3, 4], [3, 4, 5], 8)
    report("instance C", [1, 3, 4, 5], [1, 4, 5, 7], 7)
    report("instance D", [5, 4, 6, 3], [10, 40, 30, 50], 10)


if __name__ == "__main__":
    main()
