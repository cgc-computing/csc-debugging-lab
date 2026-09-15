import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

// Reads students.csv (name,id,score), prints each student's score,
// and reports the class average.
public class ScoreReport {
    public static void main(String[] args) {
        String fileName = "students.csv";
        int total = 0;
        int count = 0;

        try (BufferedReader in = new BufferedReader(new FileReader(fileName))) {
            String line = in.readLine();          // header row
            while ((line = in.readLine()) != null) {
                String[] parts = line.split(",");
                try {
                    String name = parts[0].trim();
                    int id = Integer.parseInt(parts[1].trim());
                    int score = Integer.parseInt(parts[2].trim());
                    System.out.printf("%-16s %d  %3d%n", name, id, score);
                    total += score;
                    count++;
                } catch (NumberFormatException e) {
                    System.out.println("Skipping unreadable line: " + line);
                }
            }
        } catch (IOException e) {
            System.out.println("Could not read " + fileName + ": " + e.getMessage());
            return;
        }

        if (count > 0) {
            System.out.printf("Class average: %.1f%n", (double) total / count);
        }
    }
}
