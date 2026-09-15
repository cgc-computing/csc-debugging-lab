// A manager is an employee who also receives an annual bonus.
public class Manager extends Employee {
    private double bonus;

    public Manager(String name, double baseSalary, double bonus) {
        super(name, baseSalary);
        this.bonus = bonus;
    }

    @Override
    public double computePay() {
        return baseSalary + bonus;
    }
}
