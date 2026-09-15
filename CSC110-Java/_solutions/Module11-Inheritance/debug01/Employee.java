// Employee.java
// A general employee with a name and an annual salary.

public class Employee {
    private String name;
    private double salary;

    public Employee() {
        name = "Unassigned";
        salary = 0.0;
    }

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public String toString() {
        return String.format("%s earns $%,.2f", name, salary);
    }
}
