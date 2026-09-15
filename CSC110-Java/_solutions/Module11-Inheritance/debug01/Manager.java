// Manager.java
// A manager is an employee who also runs a department.

public class Manager extends Employee {
    private String department;

    public Manager(String name, double salary, String department) {
        super(name, salary);
        this.department = department;
    }

    public String getDepartment() {
        return department;
    }

    public String toString() {
        return super.toString() + " and manages " + department;
    }
}
