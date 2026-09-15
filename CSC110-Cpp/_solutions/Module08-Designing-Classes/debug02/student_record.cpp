// student_record.cpp
// A Student class (name, ID number, GPA) with getters and a validated setter,
// plus a helper function that prints a one-line summary of any student.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int idNumber;
    double gpa;

public:
    Student(string name, int idNumber, double gpa) {
        this->name = name;
        this->idNumber = idNumber;
        this->gpa = gpa;
    }

    string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    double getGpa() const { return gpa; }

    void setGpa(double newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            gpa = newGpa;
        }
    }
};

// Prints one student on a single line. Takes the student by const reference
// so no copy is made and the function cannot change the student.
void printSummary(const Student& s) {
    cout << s.getName() << " (ID " << s.getIdNumber() << ")"
         << " - GPA " << s.getGpa() << endl;
}

int main() {
    Student a("Ana Ruiz", 1001, 3.7);
    Student b("Ben Okafor", 1002, 3.2);

    printSummary(a);
    printSummary(b);

    b.setGpa(3.5);
    printSummary(b);
    return 0;
}
