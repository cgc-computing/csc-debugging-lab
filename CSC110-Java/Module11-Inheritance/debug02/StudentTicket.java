// StudentTicket.java
// A student ticket costs half the base fare.

public class StudentTicket extends Ticket {
    public StudentTicket(String holder) {
        super(holder);
    }

    public String getType() {
        return "Student";
    }

    public double cost(int baseFare) {
        return baseFare * 0.5;
    }
}
