// daily_changes.cpp
// For each week of temperature readings, prints the change from one day
// to the next (positive = warmer, negative = cooler).

#include <iostream>
#include <vector>
using namespace std;

// Prints the day-to-day change for consecutive readings in temps.
void printChanges(const vector<int>& temps) {
    for (size_t i = 0; i + 1 < temps.size(); i++) {
        int change = temps[i + 1] - temps[i];
        cout << "  day " << i + 1 << " -> day " << i + 2 << ": "
             << (change >= 0 ? "+" : "") << change << endl;
    }
}

int main() {
    vector<int> week1 = { 68, 71, 75, 74, 70, 66, 69 };
    vector<int> week2 = { 72 };          // only one reading recorded
    vector<int> week3;                   // sensor was offline all week

    cout << "Week 1 changes:" << endl;
    printChanges(week1);

    cout << "Week 2 changes:" << endl;
    printChanges(week2);

    cout << "Week 3 changes:" << endl;
    printChanges(week3);

    cout << "Done." << endl;
    return 0;
}
