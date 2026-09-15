// ScoreStats.java
// Stores a set of quiz scores in an array and reports the number of
// scores, their total, and their average.

public class ScoreStats {
    public static void main(String[] args) {
        int[] scores = {88, 92, 79, 95, 84};

        System.out.println("Number of scores: " + scores.length);

        int total = 0;
        for (int i = 0; i <= scores.length; i++) {
            total += scores[i];
        }

        double average = (double) total / scores.length;

        System.out.println("Total:   " + total);
        System.out.printf("Average: %.1f%n", average);
    }
}
