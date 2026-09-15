# Solution: Bellman-Ford with Negative Edges

**Course/Module/Activity:** CSC310 · Module 13 Shortest Paths · debug02
**Bug type(s):** boundary (one pass too few, which turns the negative-cycle check into a false alarm)
**Bug count:** 1

## Observed Behavior

```
textbook graph: negative-weight cycle reachable from the source
chain: negative-weight cycle reachable from the source
bad loop: negative-weight cycle reachable from the source
```

Every graph is reported as having a negative cycle, including the two that do not.

## The Bug(s)

`bellman_ford.cpp`, `bellmanFord`, the pass counter:

```cpp
for (int pass = 1; pass < n - 1; ++pass) {
```

This executes `n - 2` passes. Bellman-Ford requires `|V| - 1` passes: `pass <= n - 1`.

## Why the Program Behaved Incorrectly

A shortest path has at most `n - 1` edges, and one pass is only guaranteed to extend correct distances by *one* more edge along every path (in the worst edge order). The chain `0 -> 1 -> 2 -> 3 -> 4` with edges listed in reverse needs exactly `n - 1 = 4` passes: pass 1 fixes vertex 1, pass 2 fixes 2, pass 3 fixes 3—and vertex 4 is still at infinity when the three passes end. The final check then finds that `3 -> 4` can be relaxed, and the program concludes "negative cycle". The textbook graph behaves the same way: with CLRS's edge order the value for `z` (`4=-2`) is only reached on the fourth pass (see the worked example in CLRS §22.1, part (e)), so after three passes the check pass still finds an improvement. The "bad loop" graph is reported correctly only because it really does contain a negative cycle.

## The Concept This Illustrates

Bellman-Ford's correctness has two halves that depend on each other. The path-relaxation property says: after `k` complete passes, every vertex whose shortest path has at most `k` edges has its correct distance. After `|V| - 1` passes that covers every simple path, so *any* remaining relaxable edge must lie on a cycle that keeps decreasing—a negative cycle. Run one pass too few and the second half's premise fails: a relaxable edge may simply belong to a long simple path that has not been finished yet. Students often treat the pass count as "roughly n" and the check as an independent test; this activity shows that the check is only meaningful *because* the passes were complete.

## The Correction

```cpp
for (int pass = 1; pass <= n - 1; ++pass) {
```

## Instructor Notes

- Running `n` passes (or more) also produces the expected output; ask why extra passes are harmless but wasteful, and why `n - 1` is exactly enough.
- Some students remove or weaken the check instead. Have them run the "bad loop" case: the check is what detects a genuine negative cycle, and without it the function returns distances that keep decreasing.
- Good follow-up: add early termination (stop when a pass changes nothing). Ask whether the negative-cycle check is still needed (yes—if all `n - 1` passes made changes you still have to test).
- The chain example is deliberately ordered from the far end; ask how many passes it would need if the edges were listed source-first (one), and why the algorithm cannot count on a good order.
