// knapsack.cpp
// 0/1 knapsack with the space-saving one-dimensional table. best[w] holds
// the maximum value achievable with capacity w using only the items
// processed so far; each item may be taken at most once.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Item {
    std::string name;
    int weight;
    int value;
};

void printRow(const std::string& label, const std::vector<int>& best) {
    std::cout << "  after " << label << ":";
    for (int v : best) {
        std::cout << ' ' << v;
    }
    std::cout << '\n';
}

int knapsack(const std::vector<Item>& items, int capacity, bool trace) {
    std::vector<int> best(capacity + 1, 0);
    for (const Item& it : items) {
        // Walk capacities from high to low so that best[w - weight] still
        // describes the table *before* this item was considered.
        for (int w = capacity; w >= it.weight; --w) {
            best[w] = std::max(best[w], best[w - it.weight] + it.value);
        }
        if (trace) {
            printRow(it.name, best);
        }
    }
    return best[capacity];
}

int main() {
    std::vector<Item> small = {{"pen", 1, 2}, {"book", 2, 3}, {"lamp", 3, 4}, {"radio", 4, 5}};
    std::cout << "small items, capacity 5 (table shows best value for capacity 0..5)\n";
    int best5 = knapsack(small, 5, true);
    std::cout << "best value: " << best5 << '\n';

    std::cout << "small items, capacity 7\n";
    std::cout << "best value: " << knapsack(small, 7, false) << '\n';

    std::vector<Item> classic = {{"A", 10, 60}, {"B", 20, 100}, {"C", 30, 120}};
    std::cout << "classic items, capacity 50\n";
    std::cout << "best value: " << knapsack(classic, 50, false) << '\n';
    return 0;
}
