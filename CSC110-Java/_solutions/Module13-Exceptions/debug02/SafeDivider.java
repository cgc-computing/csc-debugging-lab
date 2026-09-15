// SafeDivider.java
// Reads two whole numbers as text, converts them, and prints the
// quotient and remainder. Bad input and division by zero are each
// reported with a specific message instead of crashing the program.

import java.util.Scanner;

public class SafeDivider {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Dividend: ");
        String first = keyboard.nextLine();
        System.out.print("Divisor:  ");
        String second = keyboard.nextLine();

        try {
            int dividend = Integer.parseInt(first.trim());
            int divisor = Integer.parseInt(second.trim());
            int quotient = dividend / divisor;
            int remainder = dividend % divisor;
            System.out.println(dividend + " / " + divisor + " = " + quotient
                               + " remainder " + remainder);
        } catch (NumberFormatException e) {
            System.out.println("Both entries must be whole numbers.");
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero.");
        } catch (Exception e) {
            System.out.println("Something went wrong: " + e.getMessage());
        }

        System.out.println("Done.");
    }
}
