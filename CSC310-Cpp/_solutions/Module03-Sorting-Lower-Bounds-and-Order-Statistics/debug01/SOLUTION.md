# Solution: LSD Radix Sort

**Course/Module/Activity:** CSC310 · Module 3 Sorting Lower Bounds and Order Statistics · debug01
**Bug type(s):** logic (stability)
**Bug count:** 1

## Observed Behavior

```
input:         170 45 75 90 802 24 2 66 
after digit 1: 90 170 2 802 24 75 45 66 
after digit 10: 802 2 24 45 66 75 170 90 
after digit 100: 90 75 66 45 24 2 170 802 
NOT SORTED
```

Each pass groups the digits correctly but reverses the order within a digit group, so the final array is largely descending.

## The Bug(s)

`radix_sort.cpp`, `countingSortByDigit`, placement loop:

```cpp
for (int j = 0; j < n; ++j) {
    int d = (a[j] / exp) % 10;
    output[count[d] - 1] = a[j];
    --count[d];
}
```

After the prefix sums, `count[d] - 1` is the *last* slot for digit `d`. Filling slots from the last one down while scanning the input left to right puts the first-seen element in the highest slot, which reverses equal-digit elements. CLRS's COUNTING-SORT scans `j = n downto 1` for exactly this reason.

## Why the Program Behaved Incorrectly

In pass 1, 170 and 90 both have ones digit 0. 170 is seen first and gets slot `count[0]-1 = 1`; 90 then gets slot 0. Their relative order is flipped. The tens pass sorts by tens digit but again flips ties, so after the last pass the elements with hundreds digit 0 (all but 170 and 802) appear in reverse order of the previous pass: 90 75 66 45 24 2. LSD radix sort depends on each pass preserving the order established by the earlier passes for elements whose current digits tie; an unstable pass destroys that information.

## The Concept This Illustrates

Stability is not a cosmetic property: it is the correctness condition for radix sort. Counting sort is stable only when elements are placed in reverse scan order (right to left) against a "number of elements ≤ d" array, or equivalently in forward order against a "number of elements < d" (starting-position) array. Students holding this bug see the output loop as "put each element in its bucket" without thinking about the order *inside* the bucket.

## The Correction

```cpp
for (int j = n - 1; j >= 0; --j) {
    int d = (a[j] / exp) % 10;
    output[count[d] - 1] = a[j];
    --count[d];
}
```

## Instructor Notes

- An equally valid fix is to convert `count` to starting positions (exclusive prefix sums) and place in forward order with `output[count[d]++] = a[j]`. Ask students to argue why both versions are stable.
- Ask what happens to a *single* counting sort with the unstable placement: the numbers still come out sorted by that digit. That is why the first pass "looks fine" and the defect only appears when passes are combined.
- Follow-up: why does LSD radix sort go from least to most significant digit rather than the reverse?
