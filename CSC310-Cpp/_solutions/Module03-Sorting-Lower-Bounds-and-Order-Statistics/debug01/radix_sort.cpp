// radix_sort.cpp
// LSD radix sort on non-negative integers. Each pass is a counting sort
// keyed on one decimal digit (least significant first). Counting sort must
// be stable for the digit passes to combine into a correct overall order.
#include <iostream>
#include <vector>

// Counting sort of a by the digit selected by exp (1, 10, 100, ...).
void countingSortByDigit(std::vector<int>& a, int exp) {
    const int n = static_cast<int>(a.size());
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // count[d] = number of elements whose current digit is d
    for (int j = 0; j < n; ++j) {
        ++count[(a[j] / exp) % 10];
    }
    // count[d] = number of elements whose current digit is <= d
    for (int d = 1; d < 10; ++d) {
        count[d] += count[d - 1];
    }
    // Place each element at its final position for this digit, walking
    // from the right so that equal digits keep their relative order.
    for (int j = n - 1; j >= 0; --j) {
        int d = (a[j] / exp) % 10;
        output[count[d] - 1] = a[j];
        --count[d];
    }
    a = output;
}

void radixSort(std::vector<int>& a) {
    int maxValue = 0;
    for (int x : a) {
        if (x > maxValue) {
            maxValue = x;
        }
    }
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        countingSortByDigit(a, exp);
        std::cout << "after digit " << exp << ": ";
        for (int x : a) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
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
    std::vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "input:         ";
    for (int x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    radixSort(a);
    std::cout << (isSorted(a) ? "sorted\n" : "NOT SORTED\n");
    return 0;
}
