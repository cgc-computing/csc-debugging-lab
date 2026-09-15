// SumToN.java
// Reads a positive whole number n and prints the sum 1 + 2 + ... + n,
// then checks the result against the closed-form formula n(n+1)/2.

import java.util.Scanner;

public class SumToN {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.print("Enter a positive whole number: ");
        int n = keyboard.nextInt();

        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += i;
        }

        int formula = n * (n + 1) / 2;

        System.out.println("Loop total:    " + sum);
        System.out.println("Formula total: " + formula);

        if (sum == formula) {
            System.out.println("The two totals agree.");
        } else {
            System.out.println("The two totals do NOT agree.");
        }
    }
}
