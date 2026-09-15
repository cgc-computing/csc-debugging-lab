// coin_change.cpp
// Makes change for an amount using the fewest coins from a given set of
// denominations. Every denomination set contains a 1-unit coin, so change
// can always be made. The driver prints the coin count and the coins used
// for several denomination sets and amounts.
#include <algorithm>
#include <iostream>
#include <vector>

// Returns the fewest coins that sum to amount; the coins chosen are appended
// to coins in descending order. Uses the standard dynamic-programming
// recurrence best[a] = 1 + min over d of best[a - d].
int fewestCoins(std::vector<int> denoms, int amount, std::vector<int>& coins) {
    std::sort(denoms.begin(), denoms.end());
    const int NONE = amount + 1;                // more than any real answer
    std::vector<int> best(amount + 1, NONE);
    std::vector<int> choice(amount + 1, 0);
    best[0] = 0;
    for (int a = 1; a <= amount; ++a) {
        for (int d : denoms) {
            if (d <= a && best[a - d] + 1 < best[a]) {
                best[a] = best[a - d] + 1;
                choice[a] = d;
            }
        }
    }
    for (int a = amount; a > 0; a -= choice[a]) {
        coins.push_back(choice[a]);
    }
    std::sort(coins.begin(), coins.end(), std::greater<int>());
    return best[amount];
}

void report(const std::vector<int>& denoms, int amount) {
    std::vector<int> coins;
    int count = fewestCoins(denoms, amount, coins);
    std::cout << "amount " << amount << " with {";
    for (std::size_t i = 0; i < denoms.size(); ++i) {
        std::cout << (i ? ", " : "") << denoms[i];
    }
    std::cout << "}: " << count << " coin" << (count == 1 ? "" : "s") << " ->";
    for (int c : coins) {
        std::cout << ' ' << c;
    }
    std::cout << '\n';
}

int main() {
    report({1, 5, 10, 25}, 63);
    report({1, 5, 10, 25}, 30);
    report({1, 3, 4}, 6);
    report({1, 3, 4}, 10);
    report({1, 4, 5}, 8);
    report({1, 2, 5, 10, 20, 50}, 88);
    return 0;
}
