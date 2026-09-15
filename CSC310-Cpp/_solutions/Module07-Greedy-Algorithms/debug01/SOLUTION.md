# Solution: Scheduling the Most Activities

**Course/Module/Activity:** CSC310 · Module 7 Greedy Algorithms · debug01
**Bug type(s):** conceptual/design (wrong greedy choice)
**Bug count:** 1

## Observed Behavior

```
textbook set: 3 activities: a3[0,6) a7[6,10) a11[12,16)
room schedule: 1 activities: seminar[8,13)
nested set: 1 activities: all-day[0,10)
```

Every answer is a valid set of compatible activities, but none is maximum: the program finds 3 instead of 4, 1 instead of 4, and 1 instead of 3.

## The Bug(s)

`activity_selection.cpp`, `selectActivities`, the sort comparator:

```cpp
std::sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
    return a.start < b.start;
});
```

Activities are ordered by **start** time. The greedy scan is only correct when they are ordered by **finish** time.

## Why the Program Behaved Incorrectly

Sorted by start, the first activity is the one that begins earliest, and the scan commits to it. In the "nested set" that is `all-day[0,10)`, which is incompatible with everything else, so the answer is a single activity. In the textbook set the earliest starter is `a3[0,6)`; it blocks `a1`, `a2`, `a4`, `a5`, `a6`, and `a10`, leaving only `a7` and `a11` to be added. Choosing by start time optimizes the wrong thing: it does not care how much of the timeline the chosen activity consumes.

## The Concept This Illustrates

A greedy algorithm is correct only when its local choice has the **greedy-choice property**: the chosen element belongs to some optimal solution. For activity selection, the activity with the earliest *finish* time has this property (exchange argument: take any optimal solution, replace its earliest-finishing activity with the globally earliest-finishing one; nothing overlaps and the count is unchanged). Earliest start, shortest duration, and fewest conflicts all look plausible and all fail on small counterexamples. Students often remember "sort, then scan greedily" without remembering *what* to sort by, and the sorting key is the entire algorithm.

## The Correction

```cpp
std::sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
    return a.finish < b.finish;
});
```

## Instructor Notes

- Ask students to propose other keys and break them: shortest duration fails on `[0,4) [3,5) [4,8)` (picks the middle one and blocks both others); fewest overlaps fails on CLRS Figure 15.1's third example.
- Some students will "fix" the nested case by sorting on start *descending* or by skipping activities longer than some threshold. Make them test on the textbook set.
- The scan uses `start >= lastFinish`, so an activity may begin exactly when the previous one ends; ask why `>` would be wrong for the room schedule (`lab` would be dropped).
- There are ties in finish times in the textbook set (`a5` and `a6` both finish at 9). `std::sort` is not stable, but the result is the same either way here; ask students to explain why.
