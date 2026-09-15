// swap_values.cpp
// Reads two integers and prints them in ascending order, using a helper
// function to swap them when they arrive out of order.
#include <iostream>
using namespace std;

// Exchanges the values of a and b.
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int low, high;

    cout << "Enter two integers: ";
    cin >> low >> high;

    if (low > high) {
        swapValues(low, high);
    }

    cout << "Smaller: " << low << endl;
    cout << "Larger:  " << high << endl;
    return 0;
}
