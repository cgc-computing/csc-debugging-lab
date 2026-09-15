// ReportWriter.java
// Reads exam scores from scores.txt and writes a short summary report
// to report.txt: each score on its own line, then the count and average.

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ReportWriter {
    public static void main(String[] args) {
        try {
            Scanner fileIn = new Scanner(new File("scores.txt"));
            PrintWriter report = new PrintWriter("report.txt");

            report.println("Exam Score Report");
            report.println("=================");

            int count = 0;
            int total = 0;
            while (fileIn.hasNextInt()) {
                int score = fileIn.nextInt();
                count++;
                total += score;
                report.println("Score " + count + ": " + score);
            }
            fileIn.close();

            report.println();
            report.println("Scores:  " + count);
            report.printf("Average: %.2f%n", (double) total / count);
            report.close();

            System.out.println("Report written to report.txt (" + count + " scores).");
        } catch (FileNotFoundException e) {
            System.out.println("Could not open a file: " + e.getMessage());
        }
    }
}
