// A course that keeps a roster of enrolled students.
public class Course {
    private String title;
    private Student[] students;
    private int count;

    public Course(String title, int capacity) {
        this.title = title;
        this.students = new Student[capacity];
        this.count = 0;
    }

    public void enroll(Student s) {
        if (count < students.length) {
            students[count] = s;
            count++;
        }
    }

    // Returns the enrolled student with this name, or null if nobody matches.
    public Student findStudent(String name) {
        for (int i = 0; i < count; i++) {
            if (students[i].getName().equals(name)) {
                return students[i];
            }
        }
        return null;
    }

    public int getCount() {
        return count;
    }

    public String toString() {
        String result = "Course: " + title + " (" + count + " students)";
        for (int i = 0; i < count; i++) {
            result += "\n  " + students[i];
        }
        return result;
    }
}
