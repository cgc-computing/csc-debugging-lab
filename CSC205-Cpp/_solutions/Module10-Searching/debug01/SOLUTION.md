# Solution: Part Number Lookup

**Course/Module/Activity:** CSC205 · Module 10 Searching · debug01
**Bug type(s):** boundary, runtime (infinite loop)
**Bug count:** 1

## Observed Behavior

```
part 522: found at index 4 (1 comparisons)
part 104: found at index 0 (4 comparisons)
part 1073: found at index 9 (4 comparisons)
part 741: found at index 6 (3 comparisons)
```

Then the program hangs on `part 300` and never prints anything else; it must be killed with Ctrl+C. (The comparison counts for 104 and 741 also differ from a correct search — 4 and 3 instead of 3 and 4 — because the search range is shrinking differently.)

## The Bug(s)

`binary_search.cpp`, function `binarySearch`, in the `else` branch:

```cpp
} else {
    high = mid;
}
```

When `a[mid] > target`, the code keeps `mid` inside the search range instead of excluding it.

## Why the Program Behaved Incorrectly

Searching for 300: the range narrows to `low = 2, high = 2`, so `mid = 2` and `a[2] = 305 > 300`. The code sets `high = mid = 2`, which changes nothing. The loop condition `low <= high` is still true, `mid` is computed as 2 again, and the same comparison repeats forever. The search never reaches the `low > high` exit because the `else` branch cannot shrink a range of width one.

The searches that succeed happen to hit the target before this stall, which is why the first four lines print; any target that is absent and smaller than some element eventually stalls.

## The Concept This Illustrates

Binary search is correct only if every iteration makes the candidate range strictly smaller. After comparing `a[mid]` with the target and finding they differ, `mid` is *known* not to hold the target and must be excluded from the next range on both sides — `low = mid + 1` on one side and `high = mid - 1` on the other. Writing `high = mid` is the classic asymmetric slip, and it turns a guaranteed-terminating O(log n) loop into one that can spin forever on a range of width one. It also shows why "not found" inputs are the essential test cases for a search.

## The Correction

```cpp
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

- Students sometimes "fix" the hang by changing the loop condition to `low < high`. Ask them to search for 1073 (the last element) or for any array of length 1: the last candidate is never examined. Both changes together are wrong too.
- Ask why the counts for 104 and 741 differ between the broken and correct versions even though both found the right index — a nice way to see that `high = mid` re-examines an element already ruled out.
- Follow-up: "Why `low + (high - low) / 2` rather than `(low + high) / 2`?" (overflow with large indices — a CSC205-appropriate aside).
- If a group finishes early, have them count comparisons for all ten present values and confirm none exceeds 4, then ask for the formula.
