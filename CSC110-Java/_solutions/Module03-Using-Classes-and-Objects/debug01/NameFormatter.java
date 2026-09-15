// NameFormatter.java
// Reads a person's first and last name and prints a name tag with the
// full name in capital letters, plus the person's initials.

import java.util.Scanner;

public class NameFormatter {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("First name: ");
        String first = keyboard.nextLine();

        System.out.print("Last name: ");
        String last = keyboard.nextLine();

        String fullName = first + " " + last;
        fullName = fullName.toUpperCase();

        String initials = "" + first.toUpperCase().charAt(0) + last.toUpperCase().charAt(0);

        System.out.println();
        System.out.println("HELLO, my name is");
        System.out.println("   " + fullName);
        System.out.println("Initials: " + initials);
        System.out.println("Name length: " + fullName.length() + " characters");
    }
}
