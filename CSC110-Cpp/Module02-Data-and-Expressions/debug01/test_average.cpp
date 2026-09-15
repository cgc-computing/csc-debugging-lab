// test_average.cpp
// Reads three test scores and reports the total points and the average.
#include <iostream>
using namespace std;

int main() {
    int test1, test2, test3;

    cout << "Enter three test scores: ";
    cin >> test1 >> test2 >> test3;

    int total = test1 + test2 + test3;
    double average = total / 3;

    cout << "Total points: " << total << endl;
    cout << "Average: " << average << endl;
    return 0;
}
