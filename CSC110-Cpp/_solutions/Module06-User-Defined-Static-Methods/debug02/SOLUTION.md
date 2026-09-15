# Solution: Two Values in Order

**Course/Module/Activity:** CSC110 · Module 6 User-Defined Static Methods · debug02
**Bug type(s):** conceptual/design (pass-by-value)
**Bug count:** 1

## Observed Behavior

With input `42 17` the values are not exchanged:

```
Smaller: 42
Larger:  17
```

The program compiles with no warnings.

## The Bug(s)

`swap_values.cpp`, the parameter list of `swapValues`:

```cpp
void swapValues(int a, int b)
```

Both parameters are passed by value, so the function swaps two private copies and the caller's
variables are unchanged.

## Why the Program Behaved Incorrectly

When `swapValues(low, high)` is called, C++ creates new variables `a` and `b` inside the function
and copies `42` and `17` into them. The three assignments correctly exchange `a` and `b` (`a = 17`,
`b = 42`), but those variables are destroyed when the function returns. `low` and `high` in `main`
still hold `42` and `17`.

## The Concept This Illustrates

Pass-by-value versus pass-by-reference. A function cannot modify its caller's variables through
value parameters; it needs either a return value (one result) or reference parameters (`int&`)
when it must change more than one caller variable, as a swap must. Students often believe the
parameter *is* the argument because it holds the same value at the start.

## The Correction

```cpp
// before
void swapValues(int a, int b)

// after
void swapValues(int& a, int& b)
```

## Instructor Notes

- Students will ask why `swapValues` cannot just `return` the answer. Ask how many values need
  to come back, and let them discover that one `return` is not enough.
- A common workaround is to delete the function and swap inline in `main`. That matches the
  output but sidesteps the lesson; ask them to make the function work as designed.
- If `using namespace std;` tempts someone to rename the function `swap`, `std::swap` may get
  called instead and "magically" work. That is a good conversation about why the name was
  `swapValues`.
- Follow-up: connect to debug01 — returning a value and modifying through a reference are the
  two ways a function affects its caller.
