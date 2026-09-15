// RectangleTester.java
// Creates a couple of Rectangle objects and prints their measurements.

public class RectangleTester {
    public static void main(String[] args) {
        Rectangle poster = new Rectangle(18.0, 24.0);
        Rectangle photo = new Rectangle(4.0, 6.0);

        System.out.println("Poster: " + poster.getWidth() + " x " + poster.getHeight());
        System.out.println("  area = " + poster.area() + ", perimeter = " + poster.perimeter());

        System.out.println("Photo:  " + photo.getWidth() + " x " + photo.getHeight());
        System.out.println("  area = " + photo.area() + ", perimeter = " + photo.perimeter());

        photo.setWidth(5.0);
        System.out.println("After widening the photo to 5 inches:");
        System.out.println("  area = " + photo.area() + ", perimeter = " + photo.perimeter());
    }
}
