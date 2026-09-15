// ScoreCurve.java
// Reads a student's raw exam score and applies a curve: every score is
// raised by 5 points, but never above 100. Prints the raw and curved
// scores.

import java.util.Scanner;

public class ScoreCurve {
    public static final int CURVE_POINTS = 5;
    public static final int MAX_SCORE = 100;

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Raw exam score: ");
        int score = keyboard.nextInt();

        int rawScore = score;
        applyCurve(score);

        System.out.println("Raw score:    " + rawScore);
        System.out.println("Curved score: " + score);
    }

    // Raises the score by the curve amount, capped at the maximum.
    public static void applyCurve(int score) {
        score = score + CURVE_POINTS;
        if (score > MAX_SCORE) {
            score = MAX_SCORE;
        }
    }
}
