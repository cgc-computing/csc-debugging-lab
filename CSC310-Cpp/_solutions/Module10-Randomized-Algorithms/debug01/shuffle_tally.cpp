// shuffle_tally.cpp
// Empirical check of an in-place random shuffle (RANDOMIZE-IN-PLACE, CLRS
// 5.3). The driver shuffles the sequence 0 1 2 many times with a fixed-seed
// generator and tallies how often each of the 6 permutations appears. A
// uniform shuffle should hit every permutation about equally often.
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

std::mt19937 rng(2024);   // fixed seed so every run gives the same tallies

// Shuffles a in place so that every permutation is equally likely.
void shuffle(std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    for (int i = n - 1; i > 0; --i) {
        std::uniform_int_distribution<int> pick(0, i);
        int j = pick(rng);
        std::swap(a[i], a[j]);
    }
}

int main() {
    const int trials = 108000;
    const int n = 3;
    std::map<std::string, int> tally;

    for (int t = 0; t < trials; ++t) {
        std::vector<int> a = {0, 1, 2};
        shuffle(a);
        std::string key;
        for (int v : a) {
            key += static_cast<char>('0' + v);
        }
        ++tally[key];
    }

    const double expected = static_cast<double>(trials) / 6.0;
    std::cout << "shuffles of " << n << " elements: " << trials
              << "   (expected per permutation: " << expected << ")\n";
    int worst = 0;
    for (const auto& [perm, count] : tally) {
        int diff = count - static_cast<int>(expected);
        worst = std::max(worst, std::abs(diff));
        std::cout << "  " << perm << ": " << std::setw(6) << count
                  << "  (" << std::showpos << diff << std::noshowpos << ")\n";
    }
    std::cout << "largest deviation from expected: " << worst << '\n';
    std::cout << "permutations seen: " << tally.size() << " of 6\n";
    return 0;
}
