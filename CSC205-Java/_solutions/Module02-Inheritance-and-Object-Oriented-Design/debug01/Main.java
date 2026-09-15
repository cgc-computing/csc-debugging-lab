// Prints the annual pay of each staff member and the payroll total.
public class Main {
    public static void main(String[] args) {
        Employee[] staff = {
            new Employee("Ana", 52000),
            new Manager("Ben", 70000, 12000),
            new Manager("Cleo", 81000, 15000)
        };

        double total = 0;
        for (Employee e : staff) {
            System.out.println(e);
            total += e.getAnnualPay();
        }
        System.out.printf("Payroll total: $%,.2f%n", total);
    }
}
