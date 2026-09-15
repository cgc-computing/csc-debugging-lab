# Solution: Card Hand Insertion Sort

**Course/Module/Activity:** CSC205 · Module 11 Sorting · debug02
**Bug type(s):** boundary, runtime (out-of-bounds read)
**Bug count:** 1

## Observed Behavior

With `-fsanitize=address`, the program prints the starting hand and aborts during the very first pass:

```
Start:   7 3 9 2 8 4
=================================================================
==...==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...5c
READ of size 4 at 0x...5c thread T0
    #0 ... in insertionSort(std::vector<int>&)
    #1 ... in main
0x...5c is located 4 bytes before 24-byte region [0x...60,0x...78)
allocated by thread T0 here:
    ... std::vector<int>::vector(...)
```

Without the sanitizer the behavior is undefined: the program usually appears to produce the correct sorted hand because the garbage read happens to compare as "not greater," but it may also crash or misbehave on another machine or with other data.

## The Bug(s)

`insertion_sort.cpp`, function `insertionSort`:

```cpp
while (a[j] > key && j >= 0) {
```

The two conditions are in the wrong order: `a[j]` is evaluated before `j >= 0` has confirmed that `j` is a valid index.

## Why the Program Behaved Incorrectly

Insertion sort shifts larger cards right until it either finds a card no larger than the key or runs off the left end of the sorted prefix. On pass 1, `key = 3`, `j = 0`, and `a[0] = 7 > 3`, so 7 is shifted and `j` becomes -1. The loop then evaluates `a[-1]` *first*. On a `vector<int>`, `operator[]` takes an unsigned index, so -1 becomes a huge `size_t` and the read lands 4 bytes before the vector's heap block — exactly what the sanitizer reports ("4 bytes before 24-byte region", since the vector holds 6 ints). Only after that read would `j >= 0` be tested and stop the loop. The guard exists, but it is checked too late to protect the access.

## The Concept This Illustrates

`&&` evaluates left to right and *short-circuits*: if the left operand is false, the right operand is never evaluated. That property is what makes `j >= 0 && a[j] > key` safe — the index check must come first so the array access is skipped when the index is bad. Students often treat `&&` as a symmetric "both must be true" and do not realize the order is a correctness feature. It also reinforces the Module 6 point that `vector::operator[]` performs no bounds checking and negative indices silently wrap.

## The Correction

```cpp
// before
while (a[j] > key && j >= 0) {
// after
while (j >= 0 && a[j] > key) {
```

## Instructor Notes

- Ask students to predict what happens if they remove `-fsanitize=address`. Many will see correct output and conclude "it works." Use that to discuss undefined behavior: an out-of-bounds read that happens not to crash is still a bug, and the sanitizer makes it deterministic.
- Some students will "fix" it by starting the loop at `j = i` or by adding a special case for `j == 0`. Ask them whether the code still reads outside the vector for a key smaller than everything to its left.
- A stronger variant to discuss: `a.at(j)` would throw `std::out_of_range` instead of reading garbage; ask when checked access is worth its cost.
- Follow-up: have them write the pass-by-pass trace for `9 8 7` by hand before running it, then confirm.
