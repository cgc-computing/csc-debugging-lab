// insertion_sort.cpp
// Sorts a hand of card values with insertion sort, printing the hand after
// each pass so the growing sorted prefix is visible.

#include <iostream>
#include <vector>
using namespace std;

void printHand(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << (i > 0 ? " " : "") << a[i];
    }
    cout << endl;
}

// Insertion sort: for each card, shift the larger cards to its left one
// slot to the right, then drop the card into the gap.
void insertionSort(vector<int>& a) {
    int n = static_cast<int>(a.size());

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        cout << "  pass " << i << ": ";
        printHand(a);
    }
}

int main() {
    vector<int> hand = { 7, 3, 9, 2, 8, 4 };

    cout << "Start:   ";
    printHand(hand);

    insertionSort(hand);

    cout << "Sorted:  ";
    printHand(hand);
    return 0;
}
