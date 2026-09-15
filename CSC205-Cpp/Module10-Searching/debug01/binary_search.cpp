// binary_search.cpp
// Binary search over a sorted array of part numbers. For each requested part
// the program reports where it was found and how many elements it examined.

#include <iostream>
using namespace std;

// Returns the index of target in the sorted array a[0..n-1], or -1 if it is
// not present. comparisons is set to the number of elements examined.
int binarySearch(const int a[], int n, int target, int& comparisons) {
    int low = 0;
    int high = n - 1;
    comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return -1;
}

int main() {
    const int n = 10;
    int parts[n] = { 104, 211, 305, 418, 522, 637, 741, 856, 960, 1073 };
    int requests[] = { 522, 104, 1073, 741, 300, 2000 };

    for (int target : requests) {
        int comparisons = 0;
        int index = binarySearch(parts, n, target, comparisons);
        if (index >= 0) {
            cout << "part " << target << ": found at index " << index
                 << " (" << comparisons << " comparisons)" << endl;
        } else {
            cout << "part " << target << ": not found"
                 << " (" << comparisons << " comparisons)" << endl;
        }
    }
    return 0;
}
