// BoxOffice.java
// Sells a mix of ticket types for a show with a $12.00 base fare and
// prints each ticket's cost plus the total collected.

public class BoxOffice {
    public static void main(String[] args) {
        final double BASE_FARE = 12.00;

        Ticket[] sold = {
            new Ticket("Noah"),
            new StudentTicket("Elena"),
            new SeniorTicket("Walter"),
            new StudentTicket("Kai")
        };

        double collected = 0.0;

        System.out.printf("Base fare: $%.2f%n%n", BASE_FARE);
        for (int i = 0; i < sold.length; i++) {
            double price = sold[i].cost(BASE_FARE);
            collected += price;
            System.out.printf("%-8s %-8s $%6.2f%n",
                              sold[i].getHolder(), sold[i].getType(), price);
        }

        System.out.println();
        System.out.printf("Total collected: $%.2f%n", collected);
    }
}
