// selection_sort.cpp
// Sorts a list of quiz scores into ascending order with selection sort and
// reports how many swaps the sort performed.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void printScores(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << (i > 0 ? " " : "") << a[i];
    }
    cout << endl;
}

// Selection sort: each pass finds the smallest value in the unsorted part
// and moves it to the front of that part. Returns the number of swaps.
int selectionSort(vector<int>& a) {
    int swaps = 0;
    int n = static_cast<int>(a.size());

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
                swap(a[i], a[minIndex]);
                swaps++;
            }
        }
    }
    return swaps;
}

bool isSorted(const vector<int>& a) {
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> scores = { 72, 45, 91, 60, 88, 45, 30 };

    cout << "Before: ";
    printScores(scores);

    int swaps = selectionSort(scores);

    cout << "After:  ";
    printScores(scores);
    cout << "Swaps:  " << swaps << endl;
    cout << (isSorted(scores) ? "Sorted correctly." : "NOT sorted!") << endl;
    return 0;
}
