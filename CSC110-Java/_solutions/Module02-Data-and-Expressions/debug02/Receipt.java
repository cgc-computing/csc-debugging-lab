// Receipt.java
// Computes a simple receipt for one item: subtotal, sales tax, and total due.

import java.util.Scanner;

public class Receipt {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        final double TAX_RATE = 0.08;

        System.out.print("Item price: ");
        double price = keyboard.nextDouble();

        System.out.print("Quantity: ");
        int quantity = keyboard.nextInt();

        double subtotal = price * quantity;
        double tax = subtotal * TAX_RATE;

        System.out.println();
        System.out.println("Subtotal:  $" + subtotal);
        System.out.println("Tax (8%):  $" + tax);
        System.out.println("Total due: $" + (subtotal + tax));
    }
}
