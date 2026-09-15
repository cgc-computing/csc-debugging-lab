// Computes n! recursively for several values of n.
public class Factorial {
    public static long factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int[] inputs = {5, 3, 1, 0};
        for (int n : inputs) {
            System.out.println(n + "! = " + factorial(n));
        }
    }
}
