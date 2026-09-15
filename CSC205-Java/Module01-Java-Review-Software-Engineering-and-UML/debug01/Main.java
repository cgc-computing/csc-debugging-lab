// Builds a course roster from a comma-separated list of names,
// prints the roster, and looks up a few students by name.
public class Main {
    public static void main(String[] args) {
        String rosterLine = "Alice Chen,Brianna Ortiz,Carlos Diaz";
        String[] names = rosterLine.split(",");

        Course course = new Course("CSC205", 10);
        int nextId = 1001;
        for (String n : names) {
            course.enroll(new Student(n, nextId));
            nextId++;
        }
        System.out.println(course);

        String[] queries = "Brianna Ortiz,Dmitri Volkov".split(",");
        for (String q : queries) {
            Student found = course.findStudent(q);
            if (found != null) {
                System.out.println("Looking up " + q + ": found -> " + found);
            } else {
                System.out.println("Looking up " + q + ": not enrolled");
            }
        }
    }
}
