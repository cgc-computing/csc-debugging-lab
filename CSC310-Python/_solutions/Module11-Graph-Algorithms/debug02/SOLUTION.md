# Solution: Topological Sort by Depth-First Search

**Course/Module/Activity:** CSC310 · Module 11 Graph Algorithms · debug02
**Bug type(s):** conceptual/design (vertex recorded at discovery instead of at finish), logic (finish list never reversed)
**Bug count:** 2 (related: both concern *when* and *in which direction* finished vertices enter the order)

## Observed Behavior

```
order:
  1. undershorts
  2. pants
  3. belt
  4. jacket
  5. shoes
  6. shirt
  7. tie
  8. socks
  9. watch
edges out of order: [('shirt', 'belt'), ('tie', 'jacket'), ('socks', 'shoes')]
valid topological order: False
```

## The Bug(s)

`topological_sort.py`, function `topological_sort`, inner `visit`:

```python
def visit(u):
    color[u] = GRAY
    finished.append(u)          # appended on discovery, not on finish
    for v in adj[u]:
        if color[v] == WHITE:
            visit(v)
    color[u] = BLACK
...
return finished                 # increasing order, never reversed
```

The list is a DFS *preorder* (discovery order), and even if it were the finishing order it would be in
increasing rather than decreasing order of finishing time.

## Why the Program Behaved Incorrectly

Discovery order respects an edge `u -> v` only when `v` is discovered *through* `u` (a tree edge).
`belt` is discovered from `pants`, and `shirt` is only reached later by the outer loop; the edge
`shirt -> belt` is a cross edge to an already-finished vertex, and nothing in discovery order
accounts for it. Finishing times do: a vertex finishes only after everything reachable from it has
finished, whether via tree edges or cross edges, so for every edge `u -> v` of a DAG, `v` finishes
before `u`. CLRS therefore inserts each vertex at the *front* of the list as it finishes, producing
decreasing finishing time. Appending to the end and returning the list as is gives increasing
finishing time, which puts every edge backwards.

## The Concept This Illustrates

Topological order comes from finishing times, not discovery times: the DFS "finish" event is the
moment at which a vertex's entire reachable set is known to be complete. Two habits are being tested:
knowing which DFS event carries the information, and remembering that "push front as you finish" is
the same as "append as you finish, then reverse."

## The Correction

```python
# before
def visit(u):
    color[u] = GRAY
    finished.append(u)
    for v in adj[u]:
        if color[v] == WHITE:
            visit(v)
    color[u] = BLACK
...
return finished

# after
def visit(u):
    color[u] = GRAY
    for v in adj[u]:
        if color[v] == WHITE:
            visit(v)
    color[u] = BLACK
    finished.append(u)
...
return list(reversed(finished))
```

## Instructor Notes

- Each fix on its own still fails, which makes a good discussion. Reversing the preorder gives
  `watch socks tie shirt shoes jacket belt pants undershorts` with six backwards edges. Moving the
  append without reversing gives increasing finishing order, `jacket belt shoes pants undershorts tie
  shirt socks watch`, in which *all nine* edges are backwards — a nice confirmation of "every edge
  goes from later-finishing to earlier-finishing".
- `finished.insert(0, u)` is the literal CLRS translation and is also fine; mention that it is O(V)
  per insert but irrelevant at this size.
- Some students will want to switch to the in-degree method (Kahn's algorithm). It is correct, but the
  README rules it out; ask them to explain instead why the DFS version works.
- Follow-up: when is preorder accidentally a valid topological order? Exactly when the DFS forest has
  no cross edges (for example a graph that is itself a path or a rooted tree).
