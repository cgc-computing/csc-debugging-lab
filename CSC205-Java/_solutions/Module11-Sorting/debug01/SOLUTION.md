# Solution: Selection Sort

**Course/Module/Activity:** CSC205 · Module 11 Sorting · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
Before: [29, 10, 14, 37, 13, 5]
After:  [5, 13, 10, 14, 29, 37]
Sorted? false
Small:  [2, 1, 3]  sorted? false
```

## The Bug(s)

`SelectionSort.java`, `sort`: the swap sits *inside* the inner `for (j …)` loop instead of after it:

```java
for (int j = i + 1; j < n; j++) {
    if (a[j] < a[minIndex]) {
        minIndex = j;
    }
    swap(a, i, minIndex);      // executes on every j
}
```

A misplaced closing brace — the swap should run once per pass, after the minimum has been found.

## Why the Program Behaved Incorrectly

Trace `[3, 1, 2]`, `i = 0`, `minIndex = 0`:

- `j = 1`: `1 < 3` → `minIndex = 1`; swap `a[0], a[1]` → `[1, 3, 2]`. Now `a[minIndex]` is `a[1] = 3`, the value that *used to be* at the front.
- `j = 2`: `2 < a[1] = 3` → `minIndex = 2`; swap `a[0], a[2]` → `[2, 3, 1]`. The 1 that was correctly placed has been swapped back out.

`i = 1`: `j = 2`: `1 < 3` → `minIndex = 2`; swap → `[2, 1, 3]`. Result `[2, 1, 3]`.

The comparison `a[j] < a[minIndex]` is meant to compare against the current minimum, but because each swap moves a different value into `a[minIndex]`, the comparison is made against the wrong value from then on. The last swap of each pass happens to put the pass's true minimum at `a[i]` only when the minimum is found on the final `j`, which is why the 5 ends up first in the six-element run but the rest is scrambled.

## The Concept This Illustrates

Selection sort separates *finding* (a full scan that only records an index) from *moving* (a single swap). The invariant students should be able to state is: "after pass `i`, `a[0..i]` holds the `i+1` smallest values in order, and nothing else has moved." Swapping while still scanning violates the second half and corrupts the very comparison that drives the scan.

## The Correction

```java
// before
    for (int j = i + 1; j < n; j++) {
        if (a[j] < a[minIndex]) {
            minIndex = j;
        }
        swap(a, i, minIndex);
    }
// after
    for (int j = i + 1; j < n; j++) {
        if (a[j] < a[minIndex]) {
            minIndex = j;
        }
    }
    swap(a, i, minIndex);
```

## Instructor Notes

- Students who reformat the file in their IDE will often spot this immediately from the indentation; ask them to explain *why* the output was wrong before they touch it.
- A tempting "fix" is `if (a[j] < a[i]) swap(a, i, j);` inside the inner loop. That does sort correctly (it is an exchange sort) but performs up to O(n²) swaps and is no longer selection sort; the README's scope sentence rules it out. Ask how many swaps it makes on `[5, 4, 3, 2, 1]`.
- Ask: "Why was 5 correctly placed first?" (5 is at the end of the array, so it is found on the last `j`; the final swap of the pass happens to be the right one.)
- Have students add a swap counter: correct selection sort makes exactly `n - 1` swaps (including no-op self-swaps).
