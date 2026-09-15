// PayrollTester.java
// Creates an employee and a manager and prints the payroll lines.

public class PayrollTester {
    public static void main(String[] args) {
        Employee clerk = new Employee("Rosa Diaz", 42000.00);
        Manager boss = new Manager("Terry Jeffords", 78500.00, "Operations");

        System.out.println("Payroll");
        System.out.println("-------");
        System.out.println(clerk);
        System.out.println(boss);

        double total = clerk.getSalary() + boss.getSalary();
        System.out.printf("Total payroll: $%,.2f%n", total);
    }
}
