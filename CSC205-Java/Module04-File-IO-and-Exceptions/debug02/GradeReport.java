import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

// Writes a letter-grade report to report.txt, skipping invalid scores,
// then reads the file back and echoes it to the console.
public class GradeReport {
    public static void main(String[] args) {
        String[] names = {"Alice Chen", "Brianna Ortiz", "Carlos Diaz", "Dana Whitfield", "Evan Park"};
        int[] scores = {88, 92, 75, 105, 64};
        String fileName = "report.txt";

        try {
            writeReport(fileName, names, scores);
            System.out.println("Report saved to " + fileName);
            echoFile(fileName);
        } catch (IOException e) {
            System.out.println("File problem: " + e.getMessage());
        }
    }

    private static void writeReport(String fileName, String[] names, int[] scores) throws IOException {
        PrintWriter out = new PrintWriter(new FileWriter(fileName));
        for (int i = 0; i < names.length; i++) {
            try {
                String grade = letterGrade(scores[i]);
                out.println(names[i] + ": " + scores[i] + " (" + grade + ")");
            } catch (InvalidScoreException e) {
                System.out.println("Skipping " + names[i] + ": " + e.getMessage());
            }
        }
    }

    private static String letterGrade(int score) throws InvalidScoreException {
        if (score < 0 || score > 100) {
            throw new InvalidScoreException("score " + score + " is out of range");
        }
        if (score >= 90) return "A";
        if (score >= 80) return "B";
        if (score >= 70) return "C";
        if (score >= 60) return "D";
        return "F";
    }

    private static void echoFile(String fileName) throws IOException {
        System.out.println("Contents of " + fileName + ":");
        try (Scanner in = new Scanner(new File(fileName))) {
            while (in.hasNextLine()) {
                System.out.println(in.nextLine());
            }
        }
    }
}
