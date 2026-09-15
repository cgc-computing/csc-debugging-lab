// Computes Fibonacci numbers and reports how long each call takes.
// Running time: O(n), since fib(n) depends only on the two values before it.
public class Fibonacci {
    public static long fib(int n) {
        long[] memo = new long[n + 2];
        return fib(n, memo);
    }

    // Memoized helper: memo[k] holds fib(k) once computed (0 means not yet, k >= 2).
    private static long fib(int n, long[] memo) {
        if (n <= 1) {
            return n;
        }
        if (memo[n] == 0) {
            memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        }
        return memo[n];
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
