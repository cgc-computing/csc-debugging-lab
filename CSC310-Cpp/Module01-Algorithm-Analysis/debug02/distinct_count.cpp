// distinct_count.cpp
// Counts the number of distinct values in a vector by making a single pass
// over the input. The pass is intended to be linear: each element is
// examined once, so doubling n should roughly double the running time.
// The driver times the routine for several input sizes and prints the
// ratio between consecutive timings.
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// One pass: repeatedly take the element at the front of the work list,
// remove it, and record it if it has not been seen before.
std::size_t countDistinct(std::vector<int> work) {
    std::vector<int> seen;
    while (!work.empty()) {
        int x = work.front();
        work.erase(work.begin());
        if (std::find(seen.begin(), seen.end(), x) == seen.end()) {
            seen.push_back(x);
        }
    }
    return seen.size();
}

std::vector<int> makeData(std::size_t n, std::mt19937& rng) {
    std::vector<int> data(n);
    for (std::size_t i = 0; i < n; ++i) {
        // values drawn from a range as large as n, so roughly 63% are distinct
        data[i] = static_cast<int>(rng() % n);
    }
    return data;
}

int main() {
    std::mt19937 rng(2024);
    const std::size_t sizes[] = {20000, 40000, 80000, 160000};
    double previous = 0.0;

    for (std::size_t n : sizes) {
        std::vector<int> data = makeData(n, rng);

        auto start = std::chrono::steady_clock::now();
        std::size_t distinct = countDistinct(data);
        auto stop = std::chrono::steady_clock::now();
        double ms = std::chrono::duration<double, std::milli>(stop - start).count();

        std::cout << "n = " << n << "  distinct = " << distinct
                  << "  time = " << ms << " ms";
        if (previous > 0.0) {
            std::cout << "  (ratio to previous n: " << ms / previous << ")";
        }
        std::cout << '\n';
        previous = ms;
    }
    std::cout << "A linear-time routine should show a ratio near 2 each time n doubles.\n";
    return 0;
}
