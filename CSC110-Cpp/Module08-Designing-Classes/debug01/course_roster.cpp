// course_roster.cpp
// A Course "has a" Roster (aggregation). The program enrolls students in a
// course through the course's roster and then prints the roster.
#include <iostream>
#include <string>
using namespace std;

class Roster {
private:
    int count = 0;
    string names;    // enrolled names separated by ", "

public:
    void add(string name) {
        if (count > 0) {
            names += ", ";
        }
        names += name;
        count++;
    }

    int getCount() { return count; }
    string getNames() { return names; }
};

class Course {
private:
    string title;
    Roster roster;

public:
    Course(string title) { this->title = title; }

    string getTitle() { return title; }
    Roster getRoster() { return roster; }
};

int main() {
    Course cpp("CSC110 - Introduction to C++");
    int howMany;

    cout << "How many students to enroll? ";
    cin >> howMany;

    for (int i = 0; i < howMany; i++) {
        string name;
        cout << "Student name: ";
        cin >> name;
        cpp.getRoster().add(name);
    }

    cout << endl << cpp.getTitle() << endl;
    cout << "Enrolled: " << cpp.getRoster().getCount() << endl;
    cout << "Roster:   " << cpp.getRoster().getNames() << endl;
    return 0;
}
