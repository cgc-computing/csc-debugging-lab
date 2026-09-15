// ShippingCost.java
// Computes the shipping charge for a package. The charge is a flat rate
// that depends on the shipping zone (1, 2, or 3) plus $0.50 per pound.

import java.util.Scanner;

public class ShippingCost {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Shipping zone (1, 2, or 3): ");
        int zone = keyboard.nextInt();

        System.out.print("Package weight in pounds: ");
        double weight = keyboard.nextDouble();

        double flatRate;

        switch (zone) {
            case 1:
                flatRate = 5.00;
                break;
            case 2:
                flatRate = 8.50;
                break;
            case 3:
                flatRate = 12.00;
                break;
            default:
                System.out.println("Unknown zone; using the zone 2 rate.");
                flatRate = 8.50;
        }

        double perPound = 0.50 * weight;
        double total = flatRate + perPound;

        System.out.println();
        System.out.printf("Flat rate:   $%.2f%n", flatRate);
        System.out.printf("Weight fee:  $%.2f%n", perPound);
        System.out.printf("Total:       $%.2f%n", total);
    }
}
