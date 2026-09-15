public class Triangle extends Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public String name() {
        return "triangle";
    }

    @Override
    public double area() {
        return 0.5 * base * height;
    }
}
