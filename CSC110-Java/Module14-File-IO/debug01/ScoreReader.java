// ScoreReader.java
// Reads exam scores, one per line, from scores.txt and prints the
// number of scores, the highest score, and the average.

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ScoreReader {
    public static void main(String[] args) {
        Scanner fileIn;
        try {
            fileIn = new Scanner(new File("scores.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("Could not open scores.txt");
            return;
        }

        int count = 0;
        int total = 0;
        int highest = 0;

        while (fileIn.hasNextLine()) {
            int score = fileIn.nextInt();
            count++;
            total += score;
            if (score > highest) {
                highest = score;
            }
        }
        fileIn.close();

        System.out.println("Scores read: " + count);
        System.out.println("Highest:     " + highest);
        System.out.printf("Average:     %.2f%n", (double) total / count);
    }
}
