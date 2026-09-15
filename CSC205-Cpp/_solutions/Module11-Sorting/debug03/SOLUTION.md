# Solution: Race Time Merge Sort

**Course/Module/Activity:** CSC205 · Module 11 Sorting · debug03
**Bug type(s):** logic, boundary
**Bug count:** 1

## Observed Behavior

The program compiles cleanly and runs to completion, but the result is not a permutation of the input: 412 and 520 vanish, and 377 and 455 each appear twice.

```
Before: 301 412 350 377 388 520 399 455
  merged [0..1]: 301 412
  merged [2..3]: 350 377
  merged [0..3]: 301 350 377 377
  merged [4..5]: 388 520
  merged [6..7]: 399 455
  merged [4..7]: 388 399 455 455
  merged [0..7]: 301 350 377 377 388 399 455 455
After:  301 350 377 377 388 399 455 455
```

The two-element merges are correct; the damage starts at the first four-element merge.

## The Bug(s)

`merge_sort.cpp`, function `merge`. After the main loop that compares `a[i]` with `a[j]`, only the right half's leftovers are copied:

```cpp
    while (i <= mid && j <= high) {
        ...
    }
    while (j <= high) {          // right-half leftovers
        merged.push_back(a[j]);
        j++;
    }
    // (nothing copies a[i..mid])
```

There is no corresponding loop for the left half, so whenever the right half is exhausted first, the remaining elements `a[i..mid]` are never added to `merged`.

## Why the Program Behaved Incorrectly

Merging `301 412` (left, indices 0..1) with `350 377` (right, indices 2..3):

| step | compare | pushed | i | j |
|---|---|---|---|---|
| 1 | 301 vs 350 | 301 | 1 | 2 |
| 2 | 412 vs 350 | 350 | 1 | 3 |
| 3 | 412 vs 377 | 377 | 1 | 4 |

Now `j > high`, so the main loop stops with `i = 1` still pointing at 412. The right-leftover loop does nothing (`j` is already past `high`), and there is no left-leftover loop, so `merged` holds only three values. The copy-back loop runs `merged.size()` = 3 times, overwriting `a[0..2]` with `301 350 377` and leaving `a[3]` untouched — it still holds the old 377. So 412 is lost and 377 is duplicated. The same thing happens in `[4..7]` (520 lost, 455 duplicated), and the final merge faithfully merges the two already-damaged halves.

The two-element merges never show the problem because with one element per side the main loop always consumes one side completely and then the other side has exactly one element left, which is either the right side (copied) or the left side — and in the pairs used here (`301 412`, `350 377`, `388 520`, `399 455`) the smaller value is always on the left, so it is the *right* element that is left over each time.

## The Concept This Illustrates

The merge step's main loop can only run while *both* halves still have elements. When it stops, exactly one half is exhausted and the other may have any number of elements left — and it can be either half. A correct merge must drain whichever half is not empty. Students who have watched a merge animation often remember "copy the rest at the end" as one step and write only one loop, or assume the leftovers are always on the right because that is what happened in the example they traced. It also reinforces that a sort must produce a permutation of its input: if a value disappears or duplicates, the merge is wrong even though the output *looks* sorted.

## The Correction

```cpp
// before
    while (j <= high) {
        merged.push_back(a[j]);
        j++;
    }

// after
    while (i <= mid) {                // leftovers from the left half
        merged.push_back(a[i]);
        i++;
    }
    while (j <= high) {               // leftovers from the right half
        merged.push_back(a[j]);
        j++;
    }
```

The full corrected file sits beside this document.

## Instructor Notes

- Ask students first to check whether the output is a permutation of the input before they look at the code. Noticing "412 is gone, 377 is twice" is the whole diagnostic; the output is sorted, so a student who only checks "is it in order?" may miss the problem.
- A common partial fix is to change the copy-back loop to run `high - low + 1` times. Ask what values `merged[3]` would then hold — the vector only has three elements, so that is an out-of-bounds read (`-fsanitize=address` will catch it). The real problem is that `merged` is short, not that the copy is short.
- Another wrong fix: swapping `<=` for `<` in the main loop's condition, or changing `a[i] <= a[j]` to `<`. Have them trace the four-element merge again; the leftovers are still dropped.
- Ask: "Can both halves have leftovers at the same time?" (No — the main loop only exits when one is exhausted.) "So why do we need two loops?" (Because we do not know in advance *which* one is exhausted.) Some students will reason that a single `if` is enough; have them write it and compare with the two-loop version — they are equivalent, but the loops are the conventional form.
- Follow-up: change the input so the right half runs out first in a two-element merge (e.g. `412 301`) and predict the output before running it. Then ask why the Java-style version with a shared scratch array would show zeros in the same positions instead of duplicates.
