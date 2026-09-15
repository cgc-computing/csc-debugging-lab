// Computes Fibonacci numbers and reports how long each call takes.
// Running time: O(n), since fib(n) depends only on the two values before it.
public class Fibonacci {
    public static long fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    public static void main(String[] args) {
        int[] inputs = {35, 40};
        for (int n : inputs) {
            long start = System.nanoTime();
            long value = fib(n);
            long elapsedMs = (System.nanoTime() - start) / 1_000_000;
            System.out.println("fib(" + n + ") = " + value + "   [" + elapsedMs + " ms]");
        }
    }
}
