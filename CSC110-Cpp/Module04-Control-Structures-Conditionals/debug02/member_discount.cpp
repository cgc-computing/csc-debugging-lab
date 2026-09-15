// member_discount.cpp
// Applies a store discount based on membership level:
//   G = Gold (20%), S = Silver (10%), B = Bronze (5%), anything else = no discount.
#include <iostream>
using namespace std;

int main() {
    char level;
    double price;
    double discountRate;

    cout << "Enter membership level (G/S/B): ";
    cin >> level;
    cout << "Enter the item price: ";
    cin >> price;

    switch (level) {
        case 'G':
            discountRate = 0.20;
        case 'S':
            discountRate = 0.10;
            break;
        case 'B':
            discountRate = 0.05;
            break;
        default:
            discountRate = 0.0;
    }

    double finalPrice = price * (1 - discountRate);

    cout << "Discount rate: " << discountRate * 100 << "%" << endl;
    cout << "You pay: $" << finalPrice << endl;
    return 0;
}
