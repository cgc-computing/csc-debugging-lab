// insertion_sort.cpp
// Insertion sort as presented in CLRS (INSERTION-SORT), adapted to 0-based
// indexing, along with a small driver that sorts a few arrays and reports
// how many key comparisons were made.
#include <iostream>
#include <vector>

// Sorts a in nondecreasing order; returns the number of comparisons
// between a key and an array element.
long insertionSort(std::vector<int>& a) {
    long comparisons = 0;
    for (std::size_t j = 1; j < a.size(); ++j) {
        int key = a[j];
        // Insert a[j] into the sorted sequence a[0 .. j-1].
        int i = static_cast<int>(j) - 1;
        while (i > 0 && a[i] > key) {
            ++comparisons;
            a[i + 1] = a[i];
            --i;
        }
        if (i > 0) {
            ++comparisons;   // the comparison that ended the loop
        }
        a[i + 1] = key;
    }
    return comparisons;
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
        {5, 2, 4, 6, 1, 3},
        {31, 41, 59, 26, 41, 58},
        {9, 8, 7, 6, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {42}
    };

    for (auto& a : tests) {
        std::cout << "input:  ";
        print(a);
        long c = insertionSort(a);
        std::cout << "sorted: ";
        print(a);
        std::cout << "comparisons: " << c
                  << (isSorted(a) ? "" : "   (NOT SORTED)") << "\n\n";
    }
    return 0;
}
