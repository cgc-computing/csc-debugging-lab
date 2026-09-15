import java.util.Arrays;

// Sorts students by GPA (highest first) and prints the honor-roll order.
public class Main {
    public static void main(String[] args) {
        Student[] roster = {
            new Student("Ana", 3.20),
            new Student("Ben", 3.90),
            new Student("Cleo", 2.80),
            new Student("Dev", 3.50),
            new Student("Eli", 3.85)
        };

        Arrays.sort(roster);

        System.out.println("Honor roll order:");
        int rank = 1;
        for (Student s : roster) {
            System.out.println(rank + ". " + s);
            rank++;
        }
    }
}
