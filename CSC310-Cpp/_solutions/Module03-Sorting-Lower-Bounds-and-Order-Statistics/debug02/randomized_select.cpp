// randomized_select.cpp
// RANDOMIZED-SELECT (CLRS 9.2): finds the i-th smallest element of an array
// in expected linear time using a random pivot and Lomuto partition.
// i is 1-based: i = 1 is the minimum, i = n is the maximum.
#include <iostream>
#include <random>
#include <utility>
#include <vector>

std::mt19937 rng(7);   // fixed seed so every run is reproducible

int partition(std::vector<int>& a, int p, int r) {
    int pivot = a.at(r);
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (a.at(j) <= pivot) {
            ++i;
            std::swap(a.at(i), a.at(j));
        }
    }
    std::swap(a.at(i + 1), a.at(r));
    return i + 1;
}

int randomizedPartition(std::vector<int>& a, int p, int r) {
    int span = r - p + 1;
    int pick = p + static_cast<int>(rng() % span);
    std::swap(a.at(pick), a.at(r));
    return partition(a, p, r);
}

// Returns the i-th smallest element of a[p..r].
int randomizedSelect(std::vector<int>& a, int p, int r, int i) {
    if (p == r) {
        return a.at(p);
    }
    int q = randomizedPartition(a, p, r);
    int k = q - p + 1;           // number of elements in the low side, including the pivot
    if (i == k) {
        return a.at(q);
    }
    if (i < k) {
        return randomizedSelect(a, p, q - 1, i);
    }
    return randomizedSelect(a, q + 1, r, i - k);
}

int main() {
    const std::vector<int> data = {29, 3, 47, 12, 8, 35, 21, 40, 15, 6, 33};
    const int n = static_cast<int>(data.size());
    // sorted copy used only to show the correct answers
    std::vector<int> sorted = data;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && sorted[j - 1] > sorted[j]; --j) {
            std::swap(sorted[j - 1], sorted[j]);
        }
    }

    std::cout << "data: ";
    for (int x : data) {
        std::cout << x << ' ';
    }
    std::cout << "\n\n";
    for (int i : {1, 3, 6, 9, 11}) {
        std::vector<int> work = data;
        int found = randomizedSelect(work, 0, n - 1, i);
        std::cout << "i = " << i << ":  select -> " << found
                  << "   (sorted[" << i << "] = " << sorted[i - 1] << ")\n";
    }
    return 0;
}
