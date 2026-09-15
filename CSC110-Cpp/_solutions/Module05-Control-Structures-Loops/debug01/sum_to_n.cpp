// sum_to_n.cpp
// Adds the whole numbers from 1 up to n, showing the running total after
// each addition.
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Add the numbers from 1 up to what value? ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        cout << "After adding " << i << ", the sum is " << sum << endl;
    }

    cout << "The sum of 1 through " << n << " is " << sum << endl;
    return 0;
}
