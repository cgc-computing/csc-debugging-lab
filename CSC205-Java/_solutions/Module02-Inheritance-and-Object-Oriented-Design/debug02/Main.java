// Exercises a checking account with an overdraft limit.
public class Main {
    public static void main(String[] args) {
        CheckingAccount acct = new CheckingAccount("Priya", 100.00, 100.00);
        System.out.printf("Opening balance: $%.2f%n", acct.getBalance());

        acct.deposit(50.00);
        System.out.printf("After deposit of $50.00: $%.2f%n", acct.getBalance());

        attempt(acct, 80.00);
        attempt(acct, 150.00);
    }

    private static void attempt(CheckingAccount acct, double amount) {
        boolean ok = acct.withdraw(amount);
        System.out.printf("Withdraw $%.2f: %s%n", amount, ok ? "approved" : "declined");
        System.out.printf("Balance now: $%.2f%n", acct.getBalance());
    }
}
