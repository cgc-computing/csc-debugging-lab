// rectangle.cpp
// A Rectangle class with a constructor, getters, and area/perimeter methods,
// plus a short test program that reads the dimensions from the user.
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width = 0;
    double height = 0;

public:
    Rectangle(double width, double height) {
        width = width;
        height = height;
    }

    double getWidth() { return width; }
    double getHeight() { return height; }

    double area() { return width * height; }
    double perimeter() { return 2 * (width + height); }
};

int main() {
    double w, h;

    cout << "Enter width and height: ";
    cin >> w >> h;

    Rectangle room(w, h);

    cout << "Width:     " << room.getWidth() << endl;
    cout << "Height:    " << room.getHeight() << endl;
    cout << "Area:      " << room.area() << endl;
    cout << "Perimeter: " << room.perimeter() << endl;
    return 0;
}
