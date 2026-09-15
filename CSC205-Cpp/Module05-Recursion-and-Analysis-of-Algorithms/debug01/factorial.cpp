// factorial.cpp
// Recursive factorial with a small driver.

#include <iostream>
using namespace std;

// Returns n! for n >= 0.
long long factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int inputs[] = { 5, 10, 1, 0 };

    for (int n : inputs) {
        cout << n << "! = " << factorial(n) << endl;
    }
    return 0;
}
