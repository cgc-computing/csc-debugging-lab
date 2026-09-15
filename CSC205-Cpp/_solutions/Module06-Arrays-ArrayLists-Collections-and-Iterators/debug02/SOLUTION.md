# Solution: Day-to-Day Temperature Changes

**Course/Module/Activity:** CSC205 · Module 6 Arrays, ArrayLists, Collections, and Iterators · debug02
**Bug type(s):** boundary, runtime
**Bug count:** 1

## Observed Behavior

Weeks 1 and 2 print correctly; the program crashes on the empty week 3. With `-fsanitize=address`:

```
Week 3 changes:
AddressSanitizer:DEADLYSIGNAL
==...==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000004
    #0 ... in printChanges(std::vector<int> const&) daily_changes.cpp:12
```

Without the sanitizer the program dies with `Segmentation fault: 11` at the same point.

## The Bug(s)

The loop bound in `printChanges`:

```cpp
for (size_t i = 0; i < temps.size() - 1; i++) {
```

## Why the Program Behaved Incorrectly

`size()` returns `size_t`, an *unsigned* type. When the vector is empty, `temps.size() - 1` is `0 - 1`, which wraps around to the largest possible `size_t` (18 446 744 073 709 551 615 on a 64-bit machine) instead of −1. The condition `i < huge` is true, so the body executes and reads `temps[0]` and `temps[1]` from a vector with no storage at all — an empty `vector` holds a null data pointer, so the read is a null dereference and the program segfaults. Week 2 (one element) works only because `1 - 1 == 0` does not wrap.

## The Concept This Illustrates

Container sizes are unsigned, so "size minus one" is not a safe expression unless the size is known to be at least one. Boundary conditions for collections must be checked with the empty collection in mind. Rewriting the comparison as `i + 1 < size()` moves the arithmetic to the side that cannot go negative. This is the C++ face of the Java `ArrayList` iterator lessons: the container's *bounds* must govern the loop, and the empty case is the one students forget to test.

## The Correction

```cpp
// before
for (size_t i = 0; i < temps.size() - 1; i++) {
// after
for (size_t i = 0; i + 1 < temps.size(); i++) {
```

An explicit guard (`if (temps.size() < 2) return;`) at the top of the function is also acceptable.

## Instructor Notes

- Some students cast to a signed type: `(int)temps.size() - 1`. It works here, and `-Wall` stays quiet, but ask them about vectors larger than `INT_MAX` and about why mixing signed and unsigned in comparisons is a warning in stricter modes (`-Wsign-compare` is part of `-Wall` in g++ but only fires for signed/unsigned *comparisons*, not this subtraction).
- Ask students to print `temps.size() - 1` for the empty vector to see the wrapped value. Seeing the 20-digit number makes the unsigned point stick.
- Watch for students who "fix" `main` by removing week 3. The function must be correct for any input; the driver is the test, not the bug.
- Follow-up: the same wrap happens with `for (size_t i = v.size() - 1; i >= 0; i--)` — a loop that never terminates. Have them write a correct backwards loop.
