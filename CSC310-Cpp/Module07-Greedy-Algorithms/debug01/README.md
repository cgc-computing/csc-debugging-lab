# Scheduling the Most Activities

**Course:** CSC310 &nbsp;|&nbsp; **Module 7:** Greedy Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`selectActivities` solves the activity-selection problem from CLRS 15.1: given activities with start and finish times, choose a largest possible set of activities whose time intervals do not overlap (an activity may start exactly when another finishes). The driver runs it on the textbook's eleven activities, a room-booking list, and a set where one long activity overlaps several short ones.

## Expected Behavior

```
textbook set: 4 activities: a1[1,4) a4[5,7) a8[8,11) a11[12,16)
room schedule: 4 activities: lecture[9,10) lab[10,11) office-hours[11,12) club[12,13)
nested set: 3 activities: short-1[1,2) short-2[2,3) short-3[3,4)
```

## How to Run

```bash
g++ -std=c++17 -Wall -o activity_selection activity_selection.cpp
./activity_selection
```

(on Windows: `activity_selection.exe` or `.\activity_selection.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the sort-then-scan structure; it is the right shape for this algorithm.

## Think About

- The algorithm commits to one activity, then repeatedly takes the next compatible one. What should be true of the first activity it commits to so that as much of the timeline as possible remains free?
- In the "nested set" the best answer has three activities. Which activity does the program commit to first, and what does that single decision cost?
- Pick any ordering rule and try to argue that the first activity in that order belongs to *some* optimal solution (swap it into an optimal solution and check nothing breaks). For which rule does the argument go through?
