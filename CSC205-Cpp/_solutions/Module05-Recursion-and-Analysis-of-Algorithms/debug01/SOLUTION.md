# Solution: Recursive Factorial

**Course/Module/Activity:** CSC205 · Module 5 Recursion and Analysis of Algorithms · debug01
**Bug type(s):** boundary, runtime
**Bug count:** 1

## Observed Behavior

```
5! = 120
10! = 3628800
1! = 1
Segmentation fault: 11
```

The first three values print, then the program crashes on `factorial(0)`.

## The Bug(s)

The base case tests only `n == 1`:

```cpp
if (n == 1) {
    return 1;
}
return n * factorial(n - 1);
```

## Why the Program Behaved Incorrectly

`factorial(0)` is not 1, so the function computes `0 * factorial(-1)`, which calls `factorial(-2)`, `factorial(-3)`, ... . `n` moves *away* from the base case forever. Each call pushes a new stack frame; after a few hundred thousand frames the call stack overflows and the OS kills the process with a segmentation fault. The crash is deterministic because the recursion can never terminate.

## The Concept This Illustrates

A base case must be reachable from *every* legal input, and the recursive step must move each input *toward* it. Checking a single "convenient" value (`n == 1`) instead of the true boundary of the domain (`n == 0`, or `n <= 1` for safety) leaves a legal input with no way to stop. A stack overflow is the runtime signature of a recursion that never bottoms out.

## The Correction

```cpp
// before
if (n == 1) {
// after
if (n <= 1) {
```

(`if (n == 0) return 1;` is also correct for non-negative input; `<=` additionally guards against negative arguments.)

## Instructor Notes

- Some students add a second `if (n == 0) return 1;` — correct, but ask them to combine it and explain why `<=` covers both and also stops negative inputs from crashing.
- Ask what the program would do on `factorial(-3)` after the `n == 0` fix versus the `n <= 1` fix. Good discussion of "defensive" base cases versus preconditions.
- If a student's machine shows a different crash message (e.g., "stack overflow" or a bus error), that is still the same phenomenon; the exact text varies by platform.
- Follow-up: how deep does the recursion go for `factorial(20)`? Then: why does `long long` still overflow at 21!? (Separate issue, but it connects to analysis of growth rates.)
