// merge_sort.cpp
// Sorts race finishing times (in seconds) with merge sort and prints the
// result of each merge so the recursion can be followed.

#include <iostream>
#include <vector>
using namespace std;

void printRange(const vector<int>& a, int low, int high) {
    for (int i = low; i <= high; i++) {
        cout << (i > low ? " " : "") << a[i];
    }
}

// Merges the two sorted ranges a[low..mid] and a[mid+1..high] into one
// sorted range a[low..high].
void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> merged;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            merged.push_back(a[i]);
            i++;
        } else {
            merged.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid) {                // leftovers from the left half
        merged.push_back(a[i]);
        i++;
    }
    while (j <= high) {
        merged.push_back(a[j]);
        j++;
    }

    for (size_t k = 0; k < merged.size(); k++) {
        a[low + k] = merged[k];
    }

    cout << "  merged [" << low << ".." << high << "]: ";
    printRange(a, low, high);
    cout << endl;
}

void mergeSort(vector<int>& a, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main() {
    vector<int> times = { 301, 412, 350, 377, 388, 520, 399, 455 };
    int n = static_cast<int>(times.size());

    cout << "Before: ";
    printRange(times, 0, n - 1);
    cout << endl;

    mergeSort(times, 0, n - 1);

    cout << "After:  ";
    printRange(times, 0, n - 1);
    cout << endl;
    return 0;
}
