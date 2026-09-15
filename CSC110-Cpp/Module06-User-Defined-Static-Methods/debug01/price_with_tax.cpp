// price_with_tax.cpp
// Uses a helper function to add 8% sales tax to each item price, then prints
// the taxed prices and their total.
#include <iostream>
using namespace std;

const double TAX_RATE = 0.08;

// Returns the price with sales tax added.
double addTax(double price) {
    return price * (1 + TAX_RATE);
}

int main() {
    double price1, price2;

    cout << "Enter two item prices: ";
    cin >> price1 >> price2;

    addTax(price1);
    addTax(price2);

    cout << "Item 1 with tax: " << price1 << endl;
    cout << "Item 2 with tax: " << price2 << endl;
    cout << "Total with tax:  " << price1 + price2 << endl;
    return 0;
}
