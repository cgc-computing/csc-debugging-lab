/*
 * staff_payroll.cpp
 * A small payroll: several kinds of employee share a common base class
 * and are processed through base-class pointers.
 */
#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string& name, double annual_salary)
        : annual_salary_(annual_salary), name_(name) {}
    virtual ~Employee() = default;

    virtual std::string title() const { return "Employee"; }

    virtual double monthly_pay() const { return annual_salary_ / 12.0; }

    const std::string& name() const { return name_; }

protected:
    double annual_salary_;

private:
    std::string name_;
};

class Manager : public Employee {
public:
    Manager(const std::string& name, double annual_salary, double monthly_bonus)
        : Employee(name, annual_salary), monthly_bonus_(monthly_bonus) {}

    std::string title() const override { return "Manager"; }

    double monthly_pay() const override { return annual_salary_ / 12.0 + monthly_bonus_; }

private:
    double monthly_bonus_;
};

class Intern : public Employee {
public:
    Intern(const std::string& name, double hourly_rate, int hours_per_month)
        : Employee(name, 0.0), hourly_rate_(hourly_rate), hours_(hours_per_month) {}

    std::string title() const override { return "Intern"; }

    double monthly_pay() const override { return hourly_rate_ * hours_; }

private:
    double hourly_rate_;
    int hours_;
};

int main()
{
    Employee* staff[3] = {
        new Employee("Priya Shah", 60000.0),
        new Manager("Tom Reyes", 90000.0, 500.0),
        new Intern("Lee Chen", 18.0, 80)
    };

    double total = 0.0;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    for (Employee* e : staff) {
        std::cout << e->title() << " " << e->name()
                  << ": " << e->monthly_pay() << std::endl;
        total += e->monthly_pay();
    }
    std::cout << "Total monthly payroll: " << total << std::endl;

    for (Employee* e : staff) {
        delete e;
    }
    return 0;
}
