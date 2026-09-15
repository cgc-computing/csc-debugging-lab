// SentinelAverage.java
// Reads quiz scores until the user enters -1, then reports how many
// scores were entered and their average. The -1 is a sentinel and is
// not a score.

import java.util.Scanner;

public class SentinelAverage {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        final int SENTINEL = -1;

        int count = 0;
        int sum = 0;
        int score;

        System.out.println("Enter quiz scores one per line. Enter -1 to finish.");

        do {
            System.out.print("Score: ");
            score = keyboard.nextInt();
            sum += score;
            count++;
        } while (score != SENTINEL);

        System.out.println();
        if (count == 0) {
            System.out.println("No scores were entered.");
        } else {
            double average = (double) sum / count;
            System.out.println("Scores entered: " + count);
            System.out.println("Total points:   " + sum);
            System.out.printf("Average:        %.2f%n", average);
        }
    }
}
