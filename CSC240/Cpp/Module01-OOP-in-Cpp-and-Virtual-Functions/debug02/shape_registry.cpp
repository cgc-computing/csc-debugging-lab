/*
 * shape_registry.cpp
 * Every shape registers itself with a log message when it is created.
 * Derived shapes supply their own kind() and area().
 */
#include <iostream>
#include <string>

class Shape {
public:
    Shape()
    {
        registered_as_ = kind();
        std::cout << "Registered a " << registered_as_ << std::endl;
    }
    virtual ~Shape() = default;

    virtual std::string kind() const { return "generic shape"; }
    virtual double area() const { return 0.0; }

    const std::string& registered_as() const { return registered_as_; }

private:
    std::string registered_as_;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : Shape(), radius_(radius) {}
    std::string kind() const override { return "circle"; }
    double area() const override { return 3.14159 * radius_ * radius_; }
private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(), width_(w), height_(h) {}
    std::string kind() const override { return "rectangle"; }
    double area() const override { return width_ * height_; }
private:
    double width_;
    double height_;
};

int main()
{
    Circle c(2.0);
    Rectangle r(3.0, 4.0);

    Shape* shapes[2] = { &c, &r };

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    for (Shape* s : shapes) {
        std::cout << s->kind() << " registered as \"" << s->registered_as()
                  << "\", area " << s->area() << std::endl;
    }
    return 0;
}
