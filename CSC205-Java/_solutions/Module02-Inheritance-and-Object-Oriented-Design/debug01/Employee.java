// A salaried employee. Annual pay is computed on demand.
public class Employee {
    private String name;
    protected double baseSalary;

    public Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }

    public double computePay() {
        return baseSalary;
    }

    public double getAnnualPay() {
        return computePay();
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return String.format("%-6s $%,.2f", name, getAnnualPay());
    }
}
