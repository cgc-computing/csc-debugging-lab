// savings_account.cpp
// A basic Account with deposits, and a SavingsAccount that also earns interest.

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string owner;
    double balance;

public:
    Account(const string& ownerName, double initial)
        : owner(ownerName), balance(initial) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const { return balance; }
    string getOwner() const { return owner; }
};

class SavingsAccount : public Account {
private:
    double interestRate;   // e.g. 0.05 for 5%
    double balance;

public:
    SavingsAccount(const string& ownerName, double initial, double rate)
        : Account(ownerName, initial), interestRate(rate) {
        balance = initial;
    }

    // Adds one period of interest to the account.
    void addInterest() {
        balance += balance * interestRate;
    }

    double getInterestRate() const { return interestRate; }
};

int main() {
    SavingsAccount acct("Dana", 1000.00, 0.05);
    cout << acct.getOwner() << " opens a savings account with $"
         << acct.getBalance() << endl;

    acct.deposit(200.00);
    cout << "After deposit:  $" << acct.getBalance() << endl;

    acct.addInterest();
    cout << "After interest: $" << acct.getBalance() << endl;
    return 0;
}
