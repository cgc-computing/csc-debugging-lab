// high_score.cpp
// Records a new high score entry: the score, then the player's full name
// (which may contain spaces), and prints a confirmation banner.
#include <iostream>
#include <string>
using namespace std;

int main() {
    int score;
    string playerName;

    cout << "Enter the new high score: ";
    cin >> score;

    cout << "Enter the player's full name: ";
    getline(cin, playerName);

    string banner = "*** NEW HIGH SCORE ***";

    cout << endl << banner << endl;
    cout << playerName << " scored " << score << " points!" << endl;
    cout << "Name length: " << playerName.length() << " characters" << endl;
    return 0;
}
