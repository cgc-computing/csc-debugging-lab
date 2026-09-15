// PriceCalculator.java
// Reads the sticker price of an item, applies an 8% sales tax using a
// helper method, and prints the final price. A second helper formats
// the dollar amount.

import java.util.Scanner;

public class PriceCalculator {
    public static final double TAX_RATE = 0.08;

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Sticker price: ");
        double price = keyboard.nextDouble();

        System.out.println("Before tax: " + formatDollars(price));

        addTax(price);

        System.out.println("After tax:  " + formatDollars(price));
    }

    // Returns the price with sales tax added.
    public static double addTax(double amount) {
        double withTax = amount + amount * TAX_RATE;
        return withTax;
    }

    // Returns the amount as a string such as $12.34.
    public static String formatDollars(double amount) {
        return String.format("$%.2f", amount);
    }
}
