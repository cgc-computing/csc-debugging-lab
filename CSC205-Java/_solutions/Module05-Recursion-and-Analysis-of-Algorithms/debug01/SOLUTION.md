# Solution: Recursive Factorial

**Course/Module/Activity:** CSC205 · Module 5 Recursion and Analysis of Algorithms · debug01
**Bug type(s):** runtime, boundary
**Bug count:** 1

## Observed Behavior

```
5! = 120
3! = 6
1! = 1
Exception in thread "main" java.lang.StackOverflowError
	at Factorial.factorial(Factorial.java:7)
	at Factorial.factorial(Factorial.java:7)
	...
```

## The Bug(s)

`Factorial.java`, `factorial`: the base case is `if (n == 1)`. The input `0` never equals `1`, so the recursion never stops.

## Why the Program Behaved Incorrectly

`factorial(0)` evaluates `0 * factorial(-1)`, which evaluates `-1 * factorial(-2)`, and so on. Each call pushes a stack frame; `n` decreases forever and never hits `1`, so the JVM eventually runs out of stack space and throws `StackOverflowError`. The first three inputs are fine because they reach `1` from above.

## The Concept This Illustrates

A recursive definition needs a base case that *every* legal input eventually reaches. The mathematical definition has 0! = 1; the code's stopping condition covers only n = 1, so the set of inputs that terminate is `n >= 1`. Writing the base case as `n <= 1` (or `n == 0`) covers 0 and also guards against negative arguments overflowing the stack.

## The Correction

```java
// before
if (n == 1) {
// after
if (n <= 1) {
```

## Instructor Notes

- Students may propose `if (n == 0 || n == 1)`. Correct; ask what happens for `factorial(-3)` and whether `<=` or an `IllegalArgumentException` is better.
- Ask them to add a print at the top of `factorial` and run once with input 0 to *see* the descent into negative numbers.
- Good discussion: why is `StackOverflowError` an `Error` rather than an `Exception`, and why you should not catch it as a fix.
- Connect to analysis: each call is O(1) work and there are n frames, so the recursion depth (and space) is O(n).
