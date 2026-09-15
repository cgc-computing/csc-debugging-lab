// temperature_stats.cpp
// Stores a week of daily high temperatures in an array and reports the total
// and the average high.
#include <iostream>
using namespace std;

int main() {
    const int DAYS = 7;
    int highs[DAYS];

    cout << "Enter " << DAYS << " daily high temperatures: ";
    for (int i = 0; i < DAYS; i++) {
        cin >> highs[i];
    }

    int total = 0;
    for (int i = 0; i < DAYS; i++) {
        total += highs[i];
    }

    cout << "Total of highs: " << total << endl;
    cout << "Average high:   " << static_cast<double>(total) / DAYS << endl;
    return 0;
}
