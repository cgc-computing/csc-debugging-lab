# Fibonacci Running Time

**Course:** CSC205 &nbsp;|&nbsp; **Module 5:** Recursion and Analysis of Algorithms &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

`fib(n)` returns the n-th Fibonacci number (fib(0) = 0, fib(1) = 1, fib(n) = fib(n−1) + fib(n−2)). The header comment claims the method runs in O(n) time. `main` computes `fib(35)` and `fib(40)` and prints how many milliseconds each call took.

## Expected Behavior

The values must be correct, and the running time must actually behave like an O(n) algorithm: going from n = 35 to n = 40 is only about 14 % more work, so the second timing should be close to the first — both essentially instantaneous.

```
fib(35) = 9227465   [0 ms]
fib(40) = 102334155   [0 ms]
```

(Exact millisecond values vary from machine to machine; what matters is that both are tiny and roughly equal.)

## How to Run

```bash
javac Fibonacci.java
java Fibonacci
```

## Your Task

Run the program twice and note the two timings each run. Compare the *ratio* of the two timings with what an O(n) algorithm predicts. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The output values are correct; the claim in the header comment and the behavior must be made to agree.

## Think About

- Draw the call tree for `fib(5)`. How many times is `fib(2)` computed? How many total calls are there?
- If `fib(n)` makes two recursive calls, roughly how does the number of calls grow when n increases by 1? By 5?
- What information would each call need to remember (or receive) so that no Fibonacci number is computed twice?
