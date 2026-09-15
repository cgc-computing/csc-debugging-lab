// A student enrolled in a course.
public class Student {
    public String name;
    private int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public String toString() {
        return name + " (" + id + ")";
    }
}
