// seating_chart.cpp
// A small theater's seating chart stored as a 2-D array (1 = taken, 0 = open).
// Prints a map of the room and counts the open seats.
#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 5;
    int seats[ROWS][COLS] = {
        {1, 0, 0, 1, 0},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0}
    };

    cout << "Seating map (X = taken, . = open):" << endl;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (seats[r][c] == 1) {
                cout << "X ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    int openSeats = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < ROWS; c++) {
            if (seats[r][c] == 0) {
                openSeats++;
            }
        }
    }

    cout << "Open seats: " << openSeats << " of " << ROWS * COLS << endl;
    return 0;
}
