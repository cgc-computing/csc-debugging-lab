// roster.cpp
// A small class roster: stores students and looks them up by name.
// Written to match the UML diagram in the README.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Student {
private:
    char name[32];
    int id;

public:
    Student(const char* studentName, int studentId) {
        strncpy(name, studentName, 31);
        name[31] = '\0';
        id = studentId;
    }

    const char* getName() const { return name; }
    int getId() const { return id; }
};

class Roster {
public:
    vector<Student> students;

    void add(const Student& s) {
        students.push_back(s);
    }

    // Returns true if a student with this exact name is on the roster.
    bool find(const char* name) const {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getName() == name) {
                return true;
            }
        }
        return false;
    }

    int size() const { return static_cast<int>(students.size()); }
};

int main() {
    Roster roster;
    roster.add(Student("Alice Park", 1001));
    roster.add(Student("Bob Chen", 1002));
    roster.add(Student("Carla Diaz", 1003));

    cout << "Roster size: " << roster.size() << endl;

    const char* lookups[] = { "Bob Chen", "Carla Diaz", "Zed Nobody" };
    for (const char* who : lookups) {
        cout << who << ": " << (roster.find(who) ? "found" : "not found") << endl;
    }
    return 0;
}
