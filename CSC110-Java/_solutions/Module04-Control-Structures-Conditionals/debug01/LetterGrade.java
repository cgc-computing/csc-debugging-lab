// LetterGrade.java
// Converts a numeric course score (0-100) into a letter grade using the
// standard 90/80/70/60 scale.

import java.util.Scanner;

public class LetterGrade {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Enter the final score (0-100): ");
        int score = keyboard.nextInt();

        char grade;

        if (score >= 90) {
            grade = 'A';
        } else if (score >= 80) {
            grade = 'B';
        } else if (score >= 70) {
            grade = 'C';
        } else if (score >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        System.out.println("Score " + score + " earns a grade of " + grade);

        if (grade == 'A' || grade == 'B') {
            System.out.println("Nice work!");
        }
    }
}
