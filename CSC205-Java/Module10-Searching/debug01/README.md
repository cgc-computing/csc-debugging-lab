# Binary Search over Exam Scores

**Course:** CSC205 &nbsp;|&nbsp; **Module 10:** Searching &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`BinarySearch` looks up several target values in a sorted array of exam scores using binary search and reports the index where each one lives (or "not found"). A plain linear search runs alongside it as a cross-check.

## Expected Behavior

Every search finishes instantly and agrees with the linear search:

```
Scores: 3 8 15 21 27 34 42 50
search 21: index 3   (linear search says 3)
search 3: index 0   (linear search says 0)
search 50: index 7   (linear search says 7)
search 40: not found   (linear search says -1)
```

A correct binary search on eight values needs at most four comparisons, so the program should never pause. If it stops printing and the prompt does not come back, that is a symptom, not a slow machine: press `Ctrl+C` to stop it.

## How to Run

```bash
javac BinarySearch.java
java BinarySearch
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the algorithm a binary search; do not replace it with the linear search.

## Think About

- Trace the search for 40 by hand. Write down `low`, `high`, and `mid` at the top of each pass. What do you notice?
- Once you know `a[mid]` is *not* the target, which indices can still possibly hold it?
- What must change about the search range on every pass to guarantee the loop eventually ends?
- Why do the searches for 21, 3, and 50 work even though the code is broken?
