// randomized_quicksort.cpp
// Randomized quicksort (CLRS 7.3): RANDOMIZED-PARTITION picks a pivot
// position uniformly at random from the current subarray, so no fixed input
// can force the worst case. The driver sorts several arrays and checks them.
#include <iostream>
#include <random>
#include <vector>

std::mt19937 rng(42);   // fixed seed so every run is reproducible
long partitionCalls = 0;

int randomizedPartition(std::vector<int>& a, int lo, int hi) {
    ++partitionCalls;
    std::uniform_int_distribution<int> pick(lo, hi);
    int p = pick(rng);
    int pivot = a.at(p);
    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if (a.at(j) <= pivot) {
            ++i;
            std::swap(a.at(i), a.at(j));
        }
    }
    std::swap(a.at(i + 1), a.at(hi));
    return i + 1;
}

void quicksort(std::vector<int>& a, int lo, int hi) {
    if (lo < hi) {
        int q = randomizedPartition(a, lo, hi);
        quicksort(a, lo, q - 1);
        quicksort(a, q + 1, hi);
    }
}

void print(const char* label, const std::vector<int>& a) {
    std::cout << label;
    for (int v : a) {
        std::cout << ' ' << v;
    }
    std::cout << '\n';
}

bool isSorted(const std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        if (a[i - 1] > a[i]) return false;
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> tests = {
        {2, 8, 7, 1, 3, 5, 6, 4},
        {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11},
        {5, 5, 5, 1, 5, 2},
        {9, 7, 5, 3, 1},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    for (std::vector<int>& a : tests) {
        print("input: ", a);
        partitionCalls = 0;
        quicksort(a, 0, static_cast<int>(a.size()) - 1);
        print("output:", a);
        std::cout << (isSorted(a) ? "sorted" : "NOT SORTED")
                  << "  (partition calls: " << partitionCalls << ")\n\n";
    }
    return 0;
}
