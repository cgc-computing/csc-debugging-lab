// pet_sounds.cpp
// A Pet base class with Dog and Cat subclasses that each make their own sound.
// A helper function introduces any pet passed to it by reference.
#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;

public:
    Pet(string name) : name(name) {}

    string getName() const { return name; }
    string speak() const { return "..."; }
};

class Dog : public Pet {
public:
    Dog(string name) : Pet(name) {}
    string speak() const { return "Woof!"; }
};

class Cat : public Pet {
public:
    Cat(string name) : Pet(name) {}
    string speak() const { return "Meow."; }
};

// Works for any kind of Pet.
void introduce(const Pet& pet) {
    cout << pet.getName() << " says " << pet.speak() << endl;
}

int main() {
    Dog rex("Rex");
    Cat luna("Luna");
    Pet rock("Pet Rock");

    introduce(rex);
    introduce(luna);
    introduce(rock);
    return 0;
}
