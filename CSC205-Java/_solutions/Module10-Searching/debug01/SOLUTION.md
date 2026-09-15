# Solution: Binary Search over Exam Scores

**Course/Module/Activity:** CSC205 · Module 10 Searching · debug01
**Bug type(s):** boundary, logic (infinite loop)
**Bug count:** 1

## Observed Behavior

The first three searches print correctly, then the program hangs on the fourth and never returns to the prompt (must be killed with `Ctrl+C`):

```
Scores: 3 8 15 21 27 34 42 50
search 21: index 3   (linear search says 3)
search 3: index 0   (linear search says 0)
search 50: index 7   (linear search says 7)
```

## The Bug(s)

`BinarySearch.java`, `binarySearch`, the `else` branch of the comparison:

```java
} else {
    high = mid;
}
```

When `a[mid] > target`, the code keeps `mid` inside the search range instead of excluding it.

## Why the Program Behaved Incorrectly

Searching for 40: `low=0, high=7, mid=3` (21 < 40) → `low=4`; `mid=5` (34 < 40) → `low=6`; `mid=6` (42 > 40) → `high=6`. Now `low == high == 6`, so `mid` is 6 again, `a[6]` is still 42, and `high` is set to 6 again — forever. The range `[low, high]` never shrinks once it has collapsed onto a single value that is greater than the target, so `low <= high` stays true and the loop never exits.

The other three targets are found before the range collapses, so the bug is invisible for them. Any target that is absent and lies *below* the value the range collapses onto will hang; a target absent and *above* it (e.g. 100) terminates correctly because the `low = mid + 1` branch does shrink the range.

## The Concept This Illustrates

Binary search relies on an invariant: after each comparison, the range `[low, high]` must strictly lose at least the element just examined. `a[mid]` has already been ruled out, so both adjustments must step *past* `mid` (`low = mid + 1`, `high = mid - 1`). Students often keep `high = mid` because they have seen the "half-open" `[low, high)` version of the algorithm, where `high = mid` is correct because `high` is exclusive and the loop runs `while (low < high)`. Mixing the two conventions produces exactly this hang.

## The Correction

```java
// before
} else {
    high = mid;
}
// after
} else {
    high = mid - 1;
}
```

## Instructor Notes

- Ask students to state the invariant in words ("the target, if present, is in `a[low..high]` inclusive") and check each branch against it.
- Some students "fix" it by changing the loop to `while (low < high)`. That stops the hang but breaks the last-element case (search for 50 fails, and a one-element array can never match). Ask them to run it: the cross-check with linear search will disagree.
- A student who switches fully to the half-open convention (`high = a.length`, `while (low < high)`, `high = mid`) has a correct alternative; make sure they can explain why `high = mid` is right *there* but wrong *here*.
- Good follow-up: "How many passes does the search for 40 make in the corrected version?" (4, then `low > high`.)
