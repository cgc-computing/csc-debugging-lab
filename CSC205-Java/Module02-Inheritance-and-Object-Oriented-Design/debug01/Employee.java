// A salaried employee. Annual pay is computed once when the object is built.
public class Employee {
    private String name;
    protected double baseSalary;
    private double annualPay;

    public Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
        this.annualPay = computePay();
    }

    public double computePay() {
        return baseSalary;
    }

    public double getAnnualPay() {
        return annualPay;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return String.format("%-6s $%,.2f", name, getAnnualPay());
    }
}
