// StarBox.java
// Draws a solid rectangle of asterisks. The user chooses how many
// rows tall and how many columns wide the rectangle should be.

import java.util.Scanner;

public class StarBox {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Rows: ");
        int rows = keyboard.nextInt();

        System.out.print("Columns: ");
        int columns = keyboard.nextInt();

        System.out.println();

        int row = 1;
        while (row <= rows) {
            for (int col = 1; col <= columns; col++)
            {
                System.out.print("*");
            }
            System.out.println();
            row++;
        }

        System.out.println();
        System.out.println("Drew a " + rows + " x " + columns + " box.");
    }
}
