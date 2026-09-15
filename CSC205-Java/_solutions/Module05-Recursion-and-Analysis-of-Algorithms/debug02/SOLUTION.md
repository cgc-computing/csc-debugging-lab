# Solution: Recursive Character Count

**Course/Module/Activity:** CSC205 · Module 5 Recursion and Analysis of Algorithms · debug02
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

```
s in mississippi: 0
a in banana:      0
a in aardvark:    1
z in hello:       0
reverse(recursion) = noisrucer
```

## The Bug(s)

`StringRecursion.java`, `countChar`: the recursive call `countChar(s.substring(1), c);` is made as a bare statement and its return value is discarded. The method then returns `count`, which reflects only whether the *first* character matched.

## Why the Program Behaved Incorrectly

Every level of the recursion computes the correct answer for its own suffix and returns it, but the level above throws that number away. The outermost call therefore returns 1 if `s.charAt(0) == c` and 0 otherwise: `"mississippi"` starts with `m`, so 0; `"aardvark"` starts with `a`, so 1. All the recursive work is performed (the calls do happen) — it just never contributes to the result. `reverse` is written correctly and shows the right pattern: `reverse(rest) + firstChar` *uses* the recursive result.

## The Concept This Illustrates

A recursive solution has two parts: the work this call does on its own piece, and the *combination* of that with the result returned by the recursive call. Students who think of recursion as "a loop that calls itself" often make the call for its side effects and forget that the answer comes back as a value. In Java, a call expression used as a statement silently discards its value.

## The Correction

```java
// before
countChar(s.substring(1), c);
return count;

// after
return count + countChar(s.substring(1), c);
```

## Instructor Notes

- Some students try to make `count` a `static` field so the recursive calls can accumulate into it. It works once, then gives wrong answers on the second call unless reset. Discuss why shared mutable state undermines recursion and how the return value is the clean channel.
- Ask them to write the recurrence: `count(s) = [s[0]==c] + count(s[1..])`, then map each term to code.
- Analysis tie-in: `substring` copies, so this is O(n²) in the worst case; an index-passing version `countChar(s, c, i)` is O(n). Good stretch discussion for stronger groups.
