// quicksort.cpp
// QUICKSORT with the Lomuto PARTITION scheme from CLRS. The last element of
// each subarray is the pivot; partition rearranges the subarray so that
// everything <= pivot comes first, then the pivot, then everything larger.
#include <iostream>
#include <utility>
#include <vector>

long partitionCalls = 0;

// Partitions a[p..r] around the pivot a[r] and returns the pivot's final index.
int partition(std::vector<int>& a, int p, int r) {
    ++partitionCalls;
    int pivot = a.at(r);
    int i = p - 1;
    for (int j = p; j <= r; ++j) {
        if (a.at(j) <= pivot) {
            ++i;
            std::swap(a.at(i), a.at(j));
        }
    }
    std::swap(a.at(i + 1), a.at(r));
    return i;
}

void quicksort(std::vector<int>& a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

void print(const std::vector<int>& a) {
    for (int x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

bool isSorted(const std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> tests = {
        {2, 8, 7, 1, 3, 5, 6, 4},
        {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11},
        {5, 5, 5, 1, 5, 2},
        {9, 7, 5, 3, 1},
        {1, 2, 3, 4, 5, 6}
    };
    for (auto& a : tests) {
        partitionCalls = 0;
        std::cout << "input:  ";
        print(a);
        quicksort(a, 0, static_cast<int>(a.size()) - 1);
        std::cout << "output: ";
        print(a);
        std::cout << (isSorted(a) ? "sorted" : "NOT SORTED")
                  << "  (partition calls: " << partitionCalls << ")\n\n";
    }
    return 0;
}
