// number_sum.cpp
// Reads a list of entries typed by the user, converts each one to a whole
// number, skips any entry that is not a number, and prints the sum of the
// valid entries.
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    int howMany;
    string entry;
    int sum = 0;
    int valid = 0;

    cout << "How many entries? ";
    cin >> howMany;

    cout << "Enter " << howMany << " entries: ";
    try {
        for (int i = 0; i < howMany; i++) {
            cin >> entry;
            int value = stoi(entry);
            sum += value;
            valid++;
        }
    } catch (const invalid_argument& e) {
        cout << "Skipping '" << entry << "' (not a whole number)" << endl;
    }

    cout << "Valid entries: " << valid << endl;
    cout << "Sum: " << sum << endl;
    return 0;
}
