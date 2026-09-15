# Solution: Weekly Temperature Statistics

**Course/Module/Activity:** CSC110 · Module 9 Introduction to Arrays · debug01
**Bug type(s):** runtime (out-of-bounds read; undefined behavior)
**Bug count:** 1

## Observed Behavior

Compiled with `-fsanitize=address`, the program aborts during the summing loop with a report
like:

```
==12345==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x...
READ of size 4 at 0x... thread T0
    #0 0x... in main temperature_stats.cpp:18
  ...
  This frame has 1 object(s):
    [32, 60) 'highs' <== Memory access at offset 60 overflows this variable
```

Without the sanitizer the program prints a total that is off by whatever value happens to sit in
memory after the array (undefined behavior; often a large or negative number).

## The Bug(s)

`temperature_stats.cpp`, `main`, the summing loop:

```cpp
for (int i = 0; i <= DAYS; i++) {
    total += highs[i];
}
```

The condition `i <= DAYS` lets `i` reach `7`, but `highs` has valid indices `0` through `6`.

## Why the Program Behaved Incorrectly

The loop body runs eight times. On the eighth pass it reads `highs[7]`, four bytes past the end of
the array. C++ performs no bounds checking, so the read silently fetches whatever is in that memory
(the sanitizer instruments the program to detect and report it). The input loop uses `i < DAYS`
and is correct, which is why all seven values are read properly.

## The Concept This Illustrates

Array indices run from `0` to `size - 1`. An array of `DAYS` elements is walked with
`for (int i = 0; i < DAYS; i++)`. The off-by-one at the upper bound is the single most common
array mistake, and unlike Java, C++ does not throw an exception — it reads garbage or crashes.

## The Correction

```cpp
// before
for (int i = 0; i <= DAYS; i++)

// after
for (int i = 0; i < DAYS; i++)
```

## Instructor Notes

- Have students run without the sanitizer once to see how "reasonable-looking" the wrong total
  can be. That is the real danger of undefined behavior.
- Some students change `DAYS` to `6` in the second loop or subtract `highs[7]`; make them
  articulate the rule (`< size`) instead.
- Ask why the compiler did not warn. (Clang's `-Warray-bounds` only catches constant indices; a
  loop variable defeats it.)
- Java comparison for students who know it: `ArrayIndexOutOfBoundsException` is the same mistake
  with a friendlier symptom.
