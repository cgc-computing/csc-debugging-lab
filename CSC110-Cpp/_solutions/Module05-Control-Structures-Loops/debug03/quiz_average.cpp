// quiz_average.cpp
// Reads quiz scores until the user enters -1 (the sentinel), then prints how
// many scores were entered and their average.
#include <iostream>
using namespace std;

int main() {
    int score;
    int count = 0;
    double sum = 0;

    cout << "Enter quiz scores one at a time. Enter -1 when finished." << endl;

    cin >> score;
    while (score != -1) {
        sum += score;
        count++;
        cin >> score;
    }

    cout << "Scores entered: " << count << endl;
    if (count > 0) {
        cout << "Average: " << sum / count << endl;
    } else {
        cout << "No scores were entered." << endl;
    }
    return 0;
}
