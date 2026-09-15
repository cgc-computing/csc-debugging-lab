// Rectangle.java
// Represents a rectangle with a width and a height, both in inches.

public class Rectangle {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }

    public void setWidth(double newWidth) {
        width = newWidth;
    }

    public void setHeight(double newHeight) {
        height = newHeight;
    }

    public double area() {
        return width * height;
    }

    public double perimeter() {
        return 2 * (width + height);
    }
}
