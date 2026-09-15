// TestAverage.java
// Reads three test scores from the user and prints their average.

import java.util.Scanner;

public class TestAverage {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Enter the first test score: ");
        int test1 = keyboard.nextInt();

        System.out.print("Enter the second test score: ");
        int test2 = keyboard.nextInt();

        System.out.print("Enter the third test score: ");
        int test3 = keyboard.nextInt();

        int total = test1 + test2 + test3;
        double average = total / 3.0;

        System.out.println();
        System.out.println("Total points: " + total);
        System.out.println("Average score: " + average);
    }
}
