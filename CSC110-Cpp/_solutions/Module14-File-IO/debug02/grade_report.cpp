// grade_report.cpp
// Reads names and scores from scores.txt, assigns a letter grade to each
// student, and writes the results to report.txt one line at a time. When
// finished, it displays the contents of report.txt on the screen.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char letterGrade(int score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

// Writes one line of the report to the named file.
void appendLine(const string& filename, const string& line) {
    ofstream out(filename, ios::app);
    out << line << endl;
    out.close();
}

int main() {
    ifstream in("scores.txt");
    if (!in.is_open()) {
        cout << "Could not open scores.txt" << endl;
        return 1;
    }

    // Start a fresh report with a header line.
    ofstream report("report.txt");
    report << "Name Score Grade" << endl;
    report.close();

    string name;
    int score;
    while (in >> name >> score) {
        string line = name + " " + to_string(score) + " " + letterGrade(score);
        appendLine("report.txt", line);
    }
    in.close();

    cout << "Report written to report.txt" << endl << endl;

    // Show the finished report.
    cout << "--- report.txt ---" << endl;
    ifstream check("report.txt");
    string text;
    while (getline(check, text)) {
        cout << text << endl;
    }
    check.close();
    return 0;
}
