# Solution: Fibonacci Timing

**Course/Module/Activity:** CSC205 · Module 5 Recursion and Analysis of Algorithms · debug03
**Bug type(s):** conceptual/design (algorithm analysis)
**Bug count:** 1

## Observed Behavior

On the validation machine (Apple clang, no optimization):

```
fib(30) = 832040   (8 ms)
fib(40) = 102334155   (472 ms)
```

Both values are correct, but `fib(40)` takes roughly 60–150 times longer than `fib(30)`, not the ~1.3× a linear algorithm would show. `fib(35)` lands at about 45 ms — each +5 in `n` multiplies the time by about 11, i.e., the time grows exponentially (~1.618ⁿ).

## The Bug(s)

`fib` is the naive doubly recursive definition:

```cpp
return fib(n - 1) + fib(n - 2);
```

The comment claims O(n); the implementation is O(φⁿ), where φ ≈ 1.618.

## Why the Program Behaved Incorrectly

Each call spawns two more calls, and the two subtrees overlap almost completely: `fib(n-2)` is computed once directly and again inside `fib(n-1)`, `fib(n-3)` three times, `fib(n-4)` five times, and so on — the *number of calls* is itself a Fibonacci-like sequence. `fib(30)` makes about 2.7 million calls; `fib(40)` about 331 million. The results are right because the arithmetic is right; only the *amount of repeated work* is wrong.

## The Concept This Illustrates

Correctness and efficiency are separate properties, and Big-O is a claim about the *structure* of the computation, not the size of the code. A two-line recursive function can be exponential. Recognizing overlapping subproblems — the same argument recomputed many times — is the cue to either remember results (memoization) or rebuild them bottom-up (iteration). The timing experiment is the point of the activity: students should be able to reconcile measured growth (×~11 per +5) with a claimed bound and reject the claim.

## The Correction

```cpp
// before
long long fib(int n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}

// after (iterative, O(n) time, O(1) space)
long long fib(int n) {
    if (n < 2) return n;
    long long previous = 0, current = 1;
    for (int i = 2; i <= n; i++) {
        long long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}
```

A memoized recursive version (array or `vector<long long>` cache indexed by `n`, filled on first computation) is equally acceptable and keeps the recursive shape.

## Instructor Notes

- Times vary by machine; at `-O2` the naive version is several times faster but the *ratio* between `fib(30)` and `fib(40)` stays around 100×. Have students focus on ratios, not absolute values.
- Some students will "fix" the comment to say O(2ⁿ) and stop. That is an honest analysis but not a fix; the Expected Behavior requires the fast program.
- If students propose memoization, make sure the cache is consulted *before* recursing and written *after*; a cache that is only written never speeds anything up (common mistake).
- Follow-up questions: how large can `n` be before `long long` overflows (n = 92)? Does the iterative version's running time even register in milliseconds at that size?
- Good bridge to later modules: this is the first place students see that recursion can be *the* cost, which comes back in merge sort versus naive approaches.
