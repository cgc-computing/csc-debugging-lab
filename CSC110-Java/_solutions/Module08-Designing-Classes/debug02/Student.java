// Student.java
// A student identified by name and a 4-digit student ID. Two Student
// objects are considered equal when both the name and the ID match.

public class Student {
    private String name;
    private int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof Student)) {
            return false;
        }
        Student other = (Student) obj;
        return name.equals(other.name) && id == other.id;
    }

    public String toString() {
        return name + " (#" + id + ")";
    }
}
