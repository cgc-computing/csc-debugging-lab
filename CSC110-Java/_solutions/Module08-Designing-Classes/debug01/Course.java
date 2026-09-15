// Course.java
// A course section. A Course HAS-A Roster of the students enrolled in it.

public class Course {
    private String code;
    private String title;
    private Roster roster;

    public Course(String code, String title, Roster roster) {
        this.code = code;
        this.title = title;
        this.roster = roster;
    }

    public void enroll(String studentName) {
        roster.addStudent(studentName);
    }

    public int enrollment() {
        return roster.getCount();
    }

    public String toString() {
        return code + " " + title + " -- " + roster;
    }
}
