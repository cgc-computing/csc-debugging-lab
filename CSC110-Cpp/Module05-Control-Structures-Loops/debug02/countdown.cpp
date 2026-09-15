// countdown.cpp
// Prints a launch countdown from a starting value down to 1, then "Liftoff!".
#include <iostream>
using namespace std;

int main() {
    int start;

    cout << "Start the countdown from: ";
    cin >> start;

    int t;
    for (t = start; t >= 1; t--);
    {
        cout << "T-minus " << t << endl;
    }

    cout << "Liftoff!" << endl;
    return 0;
}
