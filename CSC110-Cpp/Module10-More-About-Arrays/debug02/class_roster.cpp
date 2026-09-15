// class_roster.cpp
// Reads a set of students (name and score) into a vector of Student objects,
// then prints the roster and the class average.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int score;

public:
    Student() {
        name = "";
        score = 0;
    }
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }

    string getName() const { return name; }
    int getScore() const { return score; }
};

int main() {
    int count;

    cout << "How many students? ";
    cin >> count;

    vector<Student> roster(count);
    for (int i = 0; i < count; i++) {
        string name;
        int score;
        cout << "Name and score: ";
        cin >> name >> score;
        roster.push_back(Student(name, score));
    }

    cout << endl << "Roster (" << roster.size() << " students)" << endl;
    int total = 0;
    for (size_t i = 0; i < roster.size(); i++) {
        cout << i + 1 << ". " << roster[i].getName() << " - " << roster[i].getScore() << endl;
        total += roster[i].getScore();
    }

    cout << "Class average: " << static_cast<double>(total) / roster.size() << endl;
    return 0;
}
