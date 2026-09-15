// score_reader.cpp
// Reads exam scores typed by the user until a 0 is entered, skipping anything
// that is not a whole number, then prints the count, total, and average.

#include <iostream>
#include <string>
using namespace std;

int main() {
    int total = 0;
    int count = 0;
    int value;

    cout << "Enter scores one at a time. Enter 0 to finish." << endl;

    while (true) {
        cout << "Score: ";
        if (cin >> value) {
            if (value == 0) {
                break;
            }
            total += value;
            count++;
        } else {
            if (cin.eof()) {
                break;
            }
            cin.clear();          // leave the failed state before reading again
            string junk;
            cin >> junk;
            cout << "Skipping invalid input: " << junk << endl;
        }
    }

    cout << "Scores entered: " << count << endl;
    cout << "Total: " << total << endl;
    if (count > 0) {
        cout << "Average: " << static_cast<double>(total) / count << endl;
    }
    return 0;
}
