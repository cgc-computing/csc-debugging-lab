// NumberSummer.java
// Reads one line of whole numbers separated by spaces and prints their
// sum. Entries that are not whole numbers are reported and skipped, and
// the rest are still added up.

import java.util.Scanner;

public class NumberSummer {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Enter whole numbers separated by spaces: ");
        String line = keyboard.nextLine();
        String[] tokens = line.trim().split("\\s+");

        int sum = 0;
        int skipped = 0;

        for (int i = 0; i < tokens.length; i++) {
            try {
                int value = Integer.parseInt(tokens[i]);
                sum += value;
            } catch (NumberFormatException e) {
                System.out.println("  Skipping invalid entry: " + e.getMessage());
                skipped++;
            }
        }

        System.out.println();
        System.out.println("Sum of valid entries: " + sum);
        System.out.println("Entries skipped:      " + skipped);
    }
}
