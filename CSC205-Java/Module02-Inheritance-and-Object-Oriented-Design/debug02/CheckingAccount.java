// A checking account that may be overdrawn up to an overdraft limit.
public class CheckingAccount extends BankAccount {
    private double balance;
    private double overdraftLimit;

    public CheckingAccount(String owner, double openingBalance, double overdraftLimit) {
        super(owner, openingBalance);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public boolean withdraw(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            return true;
        }
        return false;
    }
}
