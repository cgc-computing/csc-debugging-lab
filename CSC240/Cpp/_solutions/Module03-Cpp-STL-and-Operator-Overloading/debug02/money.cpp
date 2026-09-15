/*
 * money.cpp
 * A Money value type that stores whole cents to avoid floating-point
 * rounding. Supports addition, scaling by an integer, comparison, and
 * printing, so receipts can be computed with ordinary operators.
 */
#include <iostream>
#include <string>

class Money {
public:
    Money() : cents_(0) {}
    Money(long dollars, long cents) : cents_(dollars * 100 + cents) {}

    long cents() const { return cents_; }

    Money operator+(const Money& other) const
    {
        Money result;
        result.cents_ = cents_ + other.cents_;
        return result;
    }

    Money operator*(int factor) const
    {
        Money result;
        result.cents_ = cents_ * factor;
        return result;
    }

    bool operator<(const Money& other) const
    {
        return cents_ < other.cents_;
    }

private:
    long cents_;
};

std::ostream& operator<<(std::ostream& out, const Money& amount)
{
    long dollars = amount.cents() / 100;
    long cents = amount.cents() % 100;
    out << "$" << dollars << "." << (cents < 10 ? "0" : "") << cents;
    return out;
}

int main()
{
    Money coffee(3, 75);
    Money bagel(2, 50);
    Money tax(0, 47);

    Money subtotal = coffee + bagel;
    Money total = subtotal + tax;
    Money two_coffees = coffee * 2;

    std::cout << "Coffee:      " << coffee << std::endl;
    std::cout << "Bagel:       " << bagel << std::endl;
    std::cout << "Subtotal:    " << subtotal << std::endl;
    std::cout << "Tax:         " << tax << std::endl;
    std::cout << "Total:       " << total << std::endl;
    std::cout << "Two coffees: " << two_coffees << std::endl;

    if (two_coffees < total) {
        std::cout << "Two coffees cost less than the whole order." << std::endl;
    } else {
        std::cout << "Two coffees cost at least as much as the whole order." << std::endl;
    }
    return 0;
}
