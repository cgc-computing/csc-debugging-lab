// grade_report.cpp
// Reads students.csv (name,exam1,exam2,exam3), prints each student's exam
// average, and reports records that cannot be parsed.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

const int NUM_EXAMS = 3;

int main() {
    ifstream in("students.csv");
    if (!in.is_open()) {
        cerr << "Could not open students.csv" << endl;
        return 1;
    }

    string line;
    getline(in, line);   // skip the header row

    string name;
    int scores[NUM_EXAMS];
    int reported = 0;

    while (getline(in, line)) {
        stringstream fields(line);
        string field;

        getline(fields, field, ',');
        name = field;

        try {
            for (int i = 0; i < NUM_EXAMS; i++) {
                getline(fields, field, ',');
                scores[i] = stoi(field);
            }
        } catch (const invalid_argument& e) {
            cout << "Warning: bad record for " << name << ", skipping." << endl;
            continue;
        }

        int total = 0;
        for (int i = 0; i < NUM_EXAMS; i++) {
            total += scores[i];
        }
        double average = static_cast<double>(total) / NUM_EXAMS;
        cout << name << ": " << average << endl;
        reported++;
    }

    cout << reported << " students reported." << endl;
    return 0;
}
