# Solution: Disjoint-Set Forest with Union by Rank

**Course/Module/Activity:** CSC310 · Module 6 Disjoint Sets and Introduction to Graphs · debug01
**Bug type(s):** logic (operation applied to elements instead of set representatives)
**Bug count:** 1

## Observed Behavior

```
union(0, 1)   sets = 7
union(0, 2)   sets = 6
union(3, 4)   sets = 5
union(1, 4)   sets = 4
union(5, 6)   sets = 3
union(2, 3)   sets = 2
parent: 2 4 2 2 4 6 6 7
connected(0, 1) = false
connected(1, 2) = false
connected(0, 4) = false
connected(2, 3) = true
connected(5, 6) = true
connected(6, 7) = false
connected(4, 5) = false
number of sets: 2
```

Elements 0 and 1 were united first, yet `connected(0, 1)` is false; the set counter claims two sets while the queries reveal at least four groups.

## The Bug(s)

`union_find.cpp`, `DisjointSets::unite`:

```cpp
void unite(int x, int y) {
    link(x, y);
}
```

`link` is applied directly to the elements rather than to the roots of their sets. CLRS's UNION is `LINK(FIND-SET(x), FIND-SET(y))`.

## Why the Program Behaved Incorrectly

`union(0, 1)`: both ranks are 0, so `parent[0] = 1`, `rank[1] = 1`. `union(0, 2)`: `link(0, 2)` compares `rank[0] = 0` with `rank[2] = 0` and sets `parent[0] = 2`—overwriting 0's link to 1. Element 0 has been moved from {0, 1} to {2}, and 1 is now alone again, but the set counter was still decremented. Every later `link` on non-roots does the same kind of damage: `union(1, 4)` hangs 1 under 4 (fine by luck), `union(2, 3)` hangs 3 under 2 (also by luck), and the counter reaches 2 although the parent array actually describes the sets {0, 2, 3}, {1, 4}, {5, 6}, {7}. Ranks are also meaningless because they are only maintained at roots, so the rank comparison in `link` compares stale numbers.

## The Concept This Illustrates

In a disjoint-set forest a *set* is identified by its root. Every operation that changes set membership must operate on roots: overwriting the parent pointer of a non-root node relinks that single node (and its subtree) and silently detaches it from the rest of its set. Students who see `parent[x] = y` as "put x in y's set" have not internalized that the parent pointer of an interior node is structural, not a membership tag. The same misunderstanding produces bugs in Kruskal's algorithm later in the course.

## The Correction

```cpp
void unite(int x, int y) {
    link(find(x), find(y));
}
```

## Instructor Notes

- Some students "fix" `link` by walking up to the roots inside it. That works, but ask them why CLRS separates LINK from FIND-SET (so that `find` does path compression on the way, keeping the amortized bound).
- Ask students to explain the observed `parent: 2 4 2 2 4 6 6 7` array by hand; it makes the detachment of element 1 concrete.
- Follow-up: why does the corrected run end with `union(2, 3)` reporting `sets = 3` rather than 2? (2 and 3 are already in the same set, so `link` sees equal roots and returns without decrementing.)
- The `a == b` early return in `link` is what makes the set counter correct; without it the count would go negative on repeated unions.
