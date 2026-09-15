// employee_manager.cpp
// An Employee base class (name, salary) and a Manager subclass that adds a
// department. Prints a short summary of each.
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee() {
        name = "unassigned";
        salary = 0.0;
    }
    Employee(string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    string getName() const { return name; }
    double getSalary() const { return salary; }

    void print() const {
        cout << name << " earns $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string name, double salary, string department)
        : department(department) {
    }

    string getDepartment() const { return department; }

    void print() const {
        cout << getName() << " manages " << department
             << " and earns $" << getSalary() << endl;
    }
};

int main() {
    Employee e("Ana Ruiz", 52000);
    Manager m("Ben Okafor", 78000, "Engineering");

    e.print();
    m.print();
    cout << "Manager's name on file: " << m.getName() << endl;
    return 0;
}
