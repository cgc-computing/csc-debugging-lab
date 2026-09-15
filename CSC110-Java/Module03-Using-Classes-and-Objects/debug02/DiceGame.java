// DiceGame.java
// A two-player dice game. Each player rolls two six-sided dice and the
// program reports each player's total; the higher total wins.
// The generator is seeded so that every run produces the same rolls,
// which makes the program easy to test.

import java.util.Random;

public class DiceGame {
    public static void main(String[] args) {
        Random generator = new Random(2024);

        System.out.println("=== Two-Dice Showdown ===");
        System.out.println();

        int player1Die1 = generator.nextInt(6);
        int player1Die2 = generator.nextInt(6);
        int player1Total = player1Die1 + player1Die2;

        System.out.println("Player 1 rolls: " + player1Die1 + " and " + player1Die2);
        System.out.println("Player 1 total: " + player1Total);
        System.out.println();

        int player2Die1 = generator.nextInt(6);
        int player2Die2 = generator.nextInt(6);
        int player2Total = player2Die1 + player2Die2;

        System.out.println("Player 2 rolls: " + player2Die1 + " and " + player2Die2);
        System.out.println("Player 2 total: " + player2Total);
        System.out.println();

        System.out.println("Higher total wins. Possible totals range from 2 to 12.");
    }
}
