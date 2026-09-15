// letter_grade.cpp
// Converts a numeric score (0-100) into a letter grade using the usual
// 90/80/70/60 cutoffs.
#include <iostream>
using namespace std;

int main() {
    int score;
    char grade;

    cout << "Enter a score from 0 to 100: ";
    cin >> score;

    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    cout << "Score: " << score << endl;
    cout << "Letter grade: " << grade << endl;
    return 0;
}
