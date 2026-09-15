// SeniorTicket.java
// A senior ticket costs 70% of the base fare.

public class SeniorTicket extends Ticket {
    public SeniorTicket(String holder) {
        super(holder);
    }

    public String getType() {
        return "Senior";
    }

    public double cost(double baseFare) {
        return baseFare * 0.7;
    }
}
