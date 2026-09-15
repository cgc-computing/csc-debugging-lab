/*
 * welcome_badge.cpp
 * Reads a visitor's full name and age, then prints a welcome badge.
 * Practice with std::string, std::cin, and reference parameters.
 */
#include <iostream>
#include <string>

void trim_badge_line(std::string& line, int width)
{
    while (static_cast<int>(line.size()) < width) {
        line += ' ';
    }
}

std::string make_greeting(const std::string& name, int age)
{
    std::string greeting = "Hello, " + name + "!";
    if (age < 18) {
        greeting += " (junior visitor)";
    }
    return greeting;
}

int main()
{
    std::string name;
    int age = 0;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::string line1 = make_greeting(name, age);
    std::string line2 = "Age: " + std::to_string(age);

    trim_badge_line(line1, 30);
    trim_badge_line(line2, 30);

    std::cout << "+--------------------------------+\n";
    std::cout << "| " << line1 << " |\n";
    std::cout << "| " << line2 << " |\n";
    std::cout << "+--------------------------------+\n";

    return 0;
}
