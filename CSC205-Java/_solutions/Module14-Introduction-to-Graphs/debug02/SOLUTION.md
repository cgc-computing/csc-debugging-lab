# Solution: Router Hop Counts with BFS

**Course/Module/Activity:** CSC205 · Module 14 Introduction to Graphs · debug02
**Bug type(s):** logic, conceptual/design
**Bug count:** 1 (one misplaced marking step; the source is unmarked for the same reason)

## Observed Behavior

```
dequeue order: [0, 1, 2, 2, 3, 3, 4, 3, 4, 4, 4]
vertices dequeued: 11
hops to 0: 0
hops to 1: 1
hops to 2: 2
hops to 3: 3
hops to 4: 4
```

Vertices are dequeued repeatedly and every distance beyond vertex 1 is too large.

## The Bug(s)

`Graph.java`, `bfsDistances`: a vertex is marked visited when it is **dequeued** rather than when it is **enqueued**:

```java
int u = queue.remove();
visited[u] = true;          // too late
...
if (!visited[v]) {
    dist[v] = dist[u] + 1;  // no visited[v] = true here
    queue.add(v);
}
```

(The source is likewise never marked before the loop, which is the same omission.)

## Why the Program Behaved Incorrectly

After dequeuing 0, vertices 1 and 2 are enqueued with `dist = 1` but remain *unmarked*. Dequeuing 1 then sees 2 as unvisited, sets `dist[2] = dist[1] + 1 = 2` (overwriting the correct 1), and enqueues 2 a second time. Dequeuing the first copy of 2 finds 3 and 4 unvisited and stamps them with `dist[2] + 1 = 3` (correct values would be 2). The second copy of 2 does it again, later copies of 3 overwrite `dist[4]` with 4, and so on — eleven dequeues in total. Because the last write wins and later writes come from vertices that are themselves too far away, every distance except the source's immediate neighbor that was processed first ends up inflated.

## The Concept This Illustrates

BFS's shortest-path guarantee rests on one invariant: **a vertex enters the queue exactly once, the first time it is discovered, and its distance is fixed at that moment.** Marking on enqueue enforces that. Marking on dequeue leaves a window during which the same vertex can be discovered again by a *later* (farther) vertex and have its distance overwritten. The effect is not merely wasted work — it corrupts the answer. This is the single most common BFS mistake and it also appears as "why does my BFS visit nodes twice?"

## The Correction

```java
// before
dist[source] = 0;
queue.add(source);
while (!queue.isEmpty()) {
    int u = queue.remove();
    visited[u] = true;
    dequeued.add(u);
    for (int v : adj.get(u)) {
        if (!visited[v]) {
            dist[v] = dist[u] + 1;
            queue.add(v);
        }
    }
}
// after
dist[source] = 0;
visited[source] = true;
queue.add(source);
while (!queue.isEmpty()) {
    int u = queue.remove();
    dequeued.add(u);
    for (int v : adj.get(u)) {
        if (!visited[v]) {
            visited[v] = true;
            dist[v] = dist[u] + 1;
            queue.add(v);
        }
    }
}
```

## Instructor Notes

- Ask students to explain the eleven dequeues *before* looking at distances; once they see duplicates in the queue, the distance corruption follows.
- A common partial fix is to keep marking on dequeue but add `if (visited[u]) continue;` after `remove()`. That removes duplicate *processing* and prints each vertex once, but the distances are still wrong (1 and 2 are both enqueued unmarked, and 1 overwrites `dist[2]` before 2 is processed). Have them run it — the output exposes it.
- Another partial fix marks neighbors on enqueue but forgets `visited[source] = true`; the source is then re-enqueued by its neighbors with `dist[0] = 2`. Run it.
- Follow-up: "Would the same bug be harmful in DFS?" (Duplicate work, but reachability is still correct — DFS makes no shortest-path promise, which is exactly why BFS is the one that needs the discipline.)
