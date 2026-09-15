// Base class for all shapes. Each shape supplies its own name and area.
public abstract class Shape {
    public abstract String name();

    public abstract double area();

    public String toString() {
        return String.format("%-10s area = %.2f", name(), area());
    }
}
