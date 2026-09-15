# Disjoint-Set Forest with Union by Rank

**Course:** CSC310 &nbsp;|&nbsp; **Module 6:** Disjoint Sets and Introduction to Graphs &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`DisjointSets` implements the disjoint-set forest from CLRS 19.3 for elements `0..n-1`: `find` returns the representative of an element's set (with path compression), `unite` merges two sets using union by rank, and `setCount` tracks how many sets remain. The driver performs six unions on eight elements, prints the parent array, and answers connectivity queries.

## Expected Behavior

After the unions, elements {0, 1, 2, 3, 4} form one set, {5, 6} another, and 7 is alone, so three sets remain. (The exact parent array depends on the rank rules, but every element in {0,1,2,3,4} must lead to the same root.)

```
union(0, 1)   sets = 7
union(0, 2)   sets = 6
union(3, 4)   sets = 5
union(1, 4)   sets = 4
union(5, 6)   sets = 3
union(2, 3)   sets = 3
parent: 1 4 4 4 4 6 6 7
connected(0, 1) = true
connected(1, 2) = true
connected(0, 4) = true
connected(2, 3) = true
connected(5, 6) = true
connected(6, 7) = false
connected(4, 5) = false
number of sets: 3
```

## How to Run

```bash
g++ -std=c++17 -Wall -o union_find union_find.cpp
./union_find
```

(on Windows: `union_find.exe` or `.\union_find.exe`)

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep union by rank and path compression; the structure of the class is fine.

## Think About

- `link` hangs one tree under another. What must be true about its two arguments for that to merge two *sets* rather than just two elements?
- Trace `union(0, 1)` followed by `union(0, 2)` by hand, drawing the forest after each. Which element ends up pointing where, and did anything get disconnected?
- The program says two sets remain but its own `connected` answers describe more than two groups. Which of the two is lying, and why?
