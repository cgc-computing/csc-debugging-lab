// receipt.cpp
// Prints a restaurant receipt: the meal subtotal, a 15% tip, and the total.
#include <iostream>
using namespace std;

int main() {
    double subtotal;

    cout << "Enter the meal subtotal: ";
    cin >> subtotal;

    int tip = subtotal * 0.15;
    double total = subtotal + tip;

    cout << "Subtotal:  $" << subtotal << endl;
    cout << "Tip (15%): $" << tip << endl;
    cout << "Total:     $" << total << endl;
    return 0;
}
