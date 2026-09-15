// TicketTester.java
// Sells three raffle tickets and prints them.

public class TicketTester {
    public static void main(String[] args) {
        Ticket first = new Ticket("Maria");
        Ticket second = new Ticket("Devon");
        Ticket third = new Ticket("Priya");

        System.out.println("Ticket #" + first.getTicketNumber() + " - " + first.getBuyer());
        System.out.println("Ticket #" + second.getTicketNumber() + " - " + second.getBuyer());
        System.out.println("Ticket #" + third.getTicketNumber() + " - " + third.getBuyer());

        System.out.println("Tickets sold so far: " + third.getTicketsSold());
    }
}
