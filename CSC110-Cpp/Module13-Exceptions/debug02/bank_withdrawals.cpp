// bank_withdrawals.cpp
// Processes a short list of withdrawal requests against an account balance.
// A non-positive amount is rejected with invalid_argument; an amount larger
// than the balance is rejected with a custom InsufficientFunds exception that
// also records how far short the account is.
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InsufficientFunds : public runtime_error {
private:
    double shortfall;

public:
    InsufficientFunds(double shortfall)
        : runtime_error("Insufficient funds"), shortfall(shortfall) {}

    double getShortfall() const { return shortfall; }
};

// Returns the new balance, or throws if the request cannot be honored.
double withdraw(double balance, double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount must be positive");
    }
    if (amount > balance) {
        throw InsufficientFunds(amount - balance);
    }
    return balance - amount;
}

int main() {
    double balance = 120.0;
    const int REQUESTS = 3;
    double requests[REQUESTS] = {40.0, -5.0, 500.0};

    cout << "Starting balance: $" << balance << endl;

    for (int i = 0; i < REQUESTS; i++) {
        cout << "Withdraw $" << requests[i] << ": ";
        try {
            balance = withdraw(balance, requests[i]);
            cout << "OK, balance is now $" << balance << endl;
        } catch (const exception& e) {
            cout << "Transaction failed: " << e.what() << endl;
        } catch (const InsufficientFunds& e) {
            cout << "Declined: " << e.what()
                 << " (short by $" << e.getShortfall() << ")" << endl;
        } catch (const invalid_argument& e) {
            cout << "Invalid amount: " << e.what() << endl;
        }
    }

    cout << "Final balance: $" << balance << endl;
    return 0;
}
