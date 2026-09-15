// HonorRoll.java
// Keeps an array of Student objects, fills it in, and prints the students
// whose GPA qualifies for the honor roll (3.5 or higher).

public class HonorRoll {
    public static void main(String[] args) {
        Student[] roster = new Student[4];

        String[] names = {"Ava", "Ben", "Cleo", "Dmitri"};
        double[] gpas = {3.9, 3.2, 3.6, 2.8};

        for (int i = 0; i < roster.length; i++) {
            roster[i].setName(names[i]);
            roster[i].setGpa(gpas[i]);
        }

        System.out.println("All students:");
        for (int i = 0; i < roster.length; i++) {
            System.out.println("  " + roster[i]);
        }

        System.out.println();
        System.out.println("Honor roll (GPA 3.5 or higher):");
        for (int i = 0; i < roster.length; i++) {
            if (roster[i].getGpa() >= 3.5) {
                System.out.println("  " + roster[i].getName());
            }
        }
    }
}
