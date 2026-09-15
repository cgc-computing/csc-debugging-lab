// DuplicateChecker.java
// Reads two student records from the keyboard and reports whether they
// describe the same student.

import java.util.Scanner;

public class DuplicateChecker {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("First student's name: ");
        String name1 = keyboard.nextLine();
        System.out.print("First student's ID: ");
        int id1 = Integer.parseInt(keyboard.nextLine());

        System.out.print("Second student's name: ");
        String name2 = keyboard.nextLine();
        System.out.print("Second student's ID: ");
        int id2 = Integer.parseInt(keyboard.nextLine());

        Student a = new Student(name1, id1);
        Student b = new Student(name2, id2);

        System.out.println();
        System.out.println("Record A: " + a);
        System.out.println("Record B: " + b);

        if (a.equals(b)) {
            System.out.println("These records describe the SAME student.");
        } else {
            System.out.println("These records describe DIFFERENT students.");
        }
    }
}
