// coin_change.cpp
// Makes change for an amount using the fewest coins from a given set of
// denominations. Every denomination set contains a 1-unit coin, so change
// can always be made. The driver prints the coin count and the coins used
// for several denomination sets and amounts.
#include <algorithm>
#include <iostream>
#include <vector>

// Returns the fewest coins that sum to amount; the coins chosen are appended
// to coins in descending order.
int fewestCoins(std::vector<int> denoms, int amount, std::vector<int>& coins) {
    std::sort(denoms.begin(), denoms.end(), std::greater<int>());
    int remaining = amount;
    for (int d : denoms) {
        while (remaining >= d) {
            coins.push_back(d);
            remaining -= d;
        }
    }
    return static_cast<int>(coins.size());
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
