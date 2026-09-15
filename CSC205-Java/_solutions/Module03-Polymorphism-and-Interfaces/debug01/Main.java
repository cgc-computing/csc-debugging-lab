// Prints the area of several shapes and their total, using one Shape array.
public class Main {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Circle(5.0),
            new Rectangle(4.0, 6.0),
            new Triangle(3.0, 4.0)
        };

        double total = 0.0;
        for (Shape s : shapes) {
            System.out.println(s);
            total += s.area();
        }
        System.out.printf("Total area: %.2f%n", total);
    }
}
