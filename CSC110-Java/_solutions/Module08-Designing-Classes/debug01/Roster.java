// Roster.java
// The list of students enrolled in one course, kept as a comma-separated
// string of names plus a count.

public class Roster {
    private String names;
    private int count;

    public Roster() {
        names = "";
        count = 0;
    }

    public void addStudent(String name) {
        if (count == 0) {
            names = name;
        } else {
            names = names + ", " + name;
        }
        count++;
    }

    public int getCount() {
        return count;
    }

    public String toString() {
        return count + " student(s): " + names;
    }
}
