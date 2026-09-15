// remove_evens.cpp
// Removes every even number from a vector, leaving the odd numbers in
// their original order.

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << v[i];
    }
    cout << "]" << endl;
}

// Erases each even element from v.
void removeEvens(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            v.erase(v.begin() + i);
        }
    }
}

int main() {
    vector<int> numbers = { 2, 4, 6, 7, 8, 10, 11, 12 };

    cout << "Before: ";
    printVector(numbers);

    removeEvens(numbers);

    cout << "After:  ";
    printVector(numbers);
    cout << "Remaining count: " << numbers.size() << endl;
    return 0;
}
