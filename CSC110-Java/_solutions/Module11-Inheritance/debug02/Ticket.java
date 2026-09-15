// Ticket.java
// A regular admission ticket. Given the base fare, a ticket reports
// what it costs. Subclasses apply their own discounts.

public class Ticket {
    private String holder;

    public Ticket(String holder) {
        this.holder = holder;
    }

    public String getHolder() {
        return holder;
    }

    public String getType() {
        return "Regular";
    }

    public double cost(double baseFare) {
        return baseFare;
    }
}
