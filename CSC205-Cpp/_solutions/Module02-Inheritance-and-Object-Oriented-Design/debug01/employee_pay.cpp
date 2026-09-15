// employee_pay.cpp
// Computes weekly pay for regular employees and managers.
// Managers earn a higher hourly rate than regular employees.

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int hoursWorked;

public:
    Employee(const string& employeeName, int hours)
        : name(employeeName), hoursWorked(hours) {}

    virtual ~Employee() {}

    virtual double hourlyRate() const { return 20.0; }

    string getName() const { return name; }

    // Computed on demand so the most-derived hourlyRate() is used.
    double getPay() const { return hoursWorked * hourlyRate(); }

    virtual string title() const { return "Employee"; }
};

class Manager : public Employee {
private:
    double rateBonus;   // extra dollars per hour on top of the base rate

public:
    Manager(const string& managerName, int hours, double bonus)
        : Employee(managerName, hours), rateBonus(bonus) {}

    double hourlyRate() const override { return 20.0 + rateBonus; }

    string title() const override { return "Manager"; }
};

void printPay(const Employee& e) {
    cout << e.title() << " " << e.getName()
         << " ($" << e.hourlyRate() << "/hr): $" << e.getPay() << endl;
}

int main() {
    Employee alice("Alice", 40);
    Manager bob("Bob", 40, 15.0);
    Manager cara("Cara", 30, 10.0);

    printPay(alice);
    printPay(bob);
    printPay(cara);
    return 0;
}
