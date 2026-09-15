// Student.java
// A student with a name and a grade-point average.

public class Student {
    private String name;
    private double gpa;

    public Student() {
        name = "";
        gpa = 0.0;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    public String getName() {
        return name;
    }

    public double getGpa() {
        return gpa;
    }

    public String toString() {
        return String.format("%-8s GPA %.2f", name, gpa);
    }
}
