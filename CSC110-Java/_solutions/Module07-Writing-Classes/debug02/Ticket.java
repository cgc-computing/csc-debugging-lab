// Ticket.java
// A raffle ticket. Each ticket is given the next available ticket number
// when it is created, starting from 1, and records the buyer's name.

public class Ticket {
    private static int nextNumber = 0;

    private int ticketNumber;
    private String buyer;

    public Ticket(String buyer) {
        nextNumber++;
        this.ticketNumber = nextNumber;
        this.buyer = buyer;
    }

    public int getTicketNumber() {
        return ticketNumber;
    }

    public String getBuyer() {
        return buyer;
    }

    public int getTicketsSold() {
        return nextNumber;
    }
}
