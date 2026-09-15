// shapes.cpp
// A Shape hierarchy. The program collects several shapes and reports
// each one's area and the total area of the collection.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual string name() const { return "shape"; }
    virtual double area() const { return 0.0; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    string name() const override { return "rectangle"; }
    double area() const override { return width * height; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    string name() const override { return "circle"; }
    double area() const override { return 3.14159 * radius * radius; }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    string name() const override { return "square"; }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3.0, 4.0));
    shapes.push_back(new Circle(1.0));
    shapes.push_back(new Square(2.0));

    double total = 0.0;
    for (size_t i = 0; i < shapes.size(); i++) {
        cout << shapes[i]->name() << " area = " << shapes[i]->area() << endl;
        total += shapes[i]->area();
    }
    cout << "Total area = " << total << endl;

    for (size_t i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    return 0;
}
