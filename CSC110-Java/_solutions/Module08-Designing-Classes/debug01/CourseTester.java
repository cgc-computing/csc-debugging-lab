// CourseTester.java
// Sets up two course sections, enrolls students, and prints both rosters.

public class CourseTester {
    public static void main(String[] args) {
        Course intro = new Course("CSC110", "Intro to Programming", new Roster());
        Course dataStructures = new Course("CSC205", "Data Structures", new Roster());

        intro.enroll("Ada");
        intro.enroll("Grace");
        intro.enroll("Linus");

        dataStructures.enroll("Dennis");
        dataStructures.enroll("Barbara");

        System.out.println(intro);
        System.out.println(dataStructures);
        System.out.println();
        System.out.println("Total enrollment across both sections: "
                           + (intro.enrollment() + dataStructures.enrollment()));
    }
}
