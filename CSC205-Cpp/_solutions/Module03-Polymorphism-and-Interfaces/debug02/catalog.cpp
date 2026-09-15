// catalog.cpp
// A store catalog. Every item type implements the Sellable interface so the
// catalog can price and describe items without knowing their concrete type.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interface: all sellable items must provide these operations.
class Sellable {
public:
    virtual ~Sellable() {}
    virtual string describe() const = 0;
    virtual double price() const = 0;
};

class Book : public Sellable {
private:
    string title;
    int pages;
public:
    Book(const string& t, int p) : title(t), pages(p) {}
    string describe() const override { return "Book: " + title; }
    double price() const override { return 5.00 + pages * 0.02; }
};

class Movie : public Sellable {
private:
    string title;
    int minutes;
public:
    Movie(const string& t, int m) : title(t), minutes(m) {}
    string describe() const override { return "Movie: " + title; }
    double price() const override { return minutes > 120 ? 14.99 : 9.99; }
};

double catalogTotal(const vector<Sellable*>& items) {
    double total = 0.0;
    for (const Sellable* item : items) {
        cout << item->describe() << " - $" << item->price() << endl;
        total += item->price();
    }
    return total;
}

int main() {
    vector<Sellable*> catalog;
    catalog.push_back(new Book("Data Structures", 450));
    catalog.push_back(new Movie("Hackers", 105));
    catalog.push_back(new Movie("The Long Cut", 165));

    double total = catalogTotal(catalog);
    cout << "Total: $" << total << endl;

    for (Sellable* item : catalog) {
        delete item;
    }
    return 0;
}
