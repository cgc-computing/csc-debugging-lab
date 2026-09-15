// highest_score.cpp
// Reads a series of bowling scores into an array and reports the highest score
// and which game (numbered from 1) it was bowled in.
#include <iostream>
using namespace std;

int main() {
    const int GAMES = 6;
    int scores[GAMES];

    cout << "Enter " << GAMES << " game scores: ";
    for (int i = 0; i < GAMES; i++) {
        cin >> scores[i];
    }

    int maxScore = scores[0];
    int maxIndex = 0;
    for (int i = 1; i < GAMES; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxIndex = i;
        }
    }

    cout << "Highest score: " << maxScore << endl;
    cout << "Bowled in game " << maxIndex + 1 << endl;
    return 0;
}
