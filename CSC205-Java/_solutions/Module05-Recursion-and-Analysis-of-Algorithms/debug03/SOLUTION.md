# Solution: Fibonacci Running Time

**Course/Module/Activity:** CSC205 · Module 5 Recursion and Analysis of Algorithms · debug03
**Bug type(s):** conceptual/design (algorithm analysis)
**Bug count:** 1

## Observed Behavior

The values are right but the timings are not remotely O(n). On the validation machine:

```
fib(35) = 9227465   [21 ms]
fib(40) = 102334155   [239 ms]
```

Increasing n by 5 multiplies the time by roughly 11, and the ratio would stay about the same for 40 → 45 (each +1 multiplies the work by about φ ≈ 1.618).

## The Bug(s)

`Fibonacci.java`, `fib`: the method is the naive double recursion `fib(n - 1) + fib(n - 2)` with no memoization. The comment's O(n) claim describes the *recurrence* (each value depends on two earlier values), not the *algorithm*, which recomputes the same subproblems exponentially many times.

## Why the Program Behaved Incorrectly

The call tree for `fib(n)` has about `2·fib(n)` nodes — roughly `1.618^n`. `fib(35)` makes about 30 million calls, `fib(40)` about 330 million. Each is cheap, but the count grows geometrically, so the observed ratio between the two timings (~11×) matches `1.618^5 ≈ 11.1`, the signature of an exponential algorithm. An O(n) algorithm would show a ratio of 40/35 ≈ 1.14.

## The Concept This Illustrates

Big-O describes the *number of operations the code actually performs*, which must be read off the code's structure, not from the mathematical relation it implements. Overlapping subproblems in a recursion tree are the telltale sign; the remedies are memoization (top-down, keep the recursion) or an iterative bottom-up loop. Measuring two inputs and comparing the ratio to the prediction is a practical way to check a complexity claim.

## The Correction

```java
// before
public static long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// after (memoized)
public static long fib(int n) {
    long[] memo = new long[n + 2];
    return fib(n, memo);
}
private static long fib(int n, long[] memo) {
    if (n <= 1) return n;
    if (memo[n] == 0) memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}
```

An iterative version with two running variables is an equally acceptable fix and is O(1) space.

## Instructor Notes

- Absolute timings vary widely and the first call includes JIT warm-up; steer students to the *ratio* and to running more than once. If a machine is very fast, have them try 40 and 45 to see the ratio again.
- Some students will change the comment to O(2^n) and declare victory. That is an honest fix of the *claim*; ask them to also make the code match the original claim, since the module is about both recursion and analysis.
- Ask why `memo[n] == 0` is a safe "not computed" sentinel here (fib(k) > 0 for k >= 1) and what they would do if 0 were a legitimate result.
- Watch for the off-by-one in the memo array size (`n + 1` suffices; `n + 2` is just slack).
- Stretch: `long` overflows at fib(93). What would you change for larger n?
