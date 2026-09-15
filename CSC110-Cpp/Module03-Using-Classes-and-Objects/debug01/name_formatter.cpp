// name_formatter.cpp
// Reads a full name (first middle last) and prints it in several formats
// using std::string member functions.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;

    cout << "Enter your full name (first middle last): ";
    getline(cin, fullName);

    int firstSpace = fullName.find(' ');
    int lastSpace = fullName.rfind(' ');

    string first = fullName.substr(0, firstSpace);
    string middle = fullName.substr(firstSpace + 1, lastSpace);
    string last = fullName.substr(lastSpace + 1);

    cout << "First name:  " << first << endl;
    cout << "Middle name: " << middle << endl;
    cout << "Last name:   " << last << endl;
    cout << "Formal:      " << last << ", " << first << " " << middle << endl;
    cout << "Initials:    " << first[0] << middle[0] << last[0] << endl;
    return 0;
}
