/*
 * honor_roll.cpp
 * Reads a list of students into a vector and keeps track of the student
 * with the highest GPA as the list is built, then prints the honor roll
 * and the top student.
 */
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double gpa;
};

void print_roll(const std::vector<Student>& roster)
{
    std::cout << "Honor roll (GPA >= 3.5):" << std::endl;
    for (const Student& s : roster) {
        if (s.gpa >= 3.5) {
            std::cout << "  " << s.name << " " << s.gpa << std::endl;
        }
    }
}

int main()
{
    const Student incoming[] = {
        { "Aisha",  3.2 },
        { "Marcus", 3.9 },
        { "Priya",  3.6 },
        { "Diego",  2.8 },
        { "Sofia",  3.7 },
        { "Ken",    3.1 }
    };
    const int incoming_count = 6;

    std::vector<Student> roster;
    const Student* top = nullptr;

    for (int i = 0; i < incoming_count; i++) {
        roster.push_back(incoming[i]);
        std::cout << "Added " << roster.back().name
                  << " (roster size " << roster.size() << ")" << std::endl;

        if (top == nullptr || roster.back().gpa > top->gpa) {
            top = &roster.back();
        }
    }

    print_roll(roster);
    std::cout << "Top student: " << top->name << " with GPA " << top->gpa << std::endl;
    return 0;
}
