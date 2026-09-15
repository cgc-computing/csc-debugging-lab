// score_reader.cpp
// Reads student names and scores from scores.txt, prints each one, and
// reports how many students there are and the class average.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("scores.txt");
    if (!in.is_open()) {
        cout << "Could not open scores.txt" << endl;
        return 1;
    }

    string name;
    int score;
    int count = 0;
    int total = 0;

    while (!in.eof()) {
        in >> name >> score;
        cout << name << ": " << score << endl;
        total += score;
        count++;
    }
    in.close();

    cout << "Students: " << count << endl;
    cout << "Average: " << static_cast<double>(total) / count << endl;
    return 0;
}
