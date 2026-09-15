# Solution: Prim's Minimum Spanning Tree

**Course/Module/Activity:** CSC310 · Module 12 Spanning Trees · debug02
**Bug type(s):** conceptual/design (key updated as a path distance instead of an edge weight)
**Bug count:** 1

## Observed Behavior

```
tree edges (parent-child):
  a-b (4)
  b-c (8)
  c-d (7)
  f-e (10)
  g-f (2)
  h-g (1)
  a-h (8)
  c-i (2)
total weight: 98
```

The listed edges sum to 42, not 37 (the tree uses `a-h`, `f-e` instead of `c-f`, `d-e`), and the printed total, 98, does not even match the listed edges.

## The Bug(s)

`prim.cpp`, `prim`, the relaxation step:

```cpp
if (!inTree[v] && key[u] + nb.weight < key[v]) {
    key[v] = key[u] + nb.weight;
```

The key is set to the accumulated distance from the root. Prim's key must be the weight of the single connecting edge: `nb.weight < key[v]` / `key[v] = nb.weight`.

## Why the Program Behaved Incorrectly

With `key[u] + w`, `key[v]` becomes the length of the shortest *path* from `a` to `v` through tree vertices—the program has turned into Dijkstra's shortest-path algorithm and builds a shortest-path tree rooted at `a`. That tree reaches `h` directly from `a` (path length 8) rather than through `g` (edge weight 1) because 8 < 4 + 8 + 4 + 2 + 1, and reaches `e` via `f` (path 21) rather than via `d` (edge 9, path 28). The total is computed as the sum of keys, i.e. the sum of path lengths (98), which is neither the tree weight nor anything meaningful for a spanning tree.

## The Concept This Illustrates

Prim's algorithm and Dijkstra's algorithm have the same skeleton—grow a tree from a root, keep a priority queue of frontier vertices, "relax" edges—and differ in exactly one line: the priority. Prim asks "what is the cheapest edge that attaches `v` to the tree?" (a local quantity); Dijkstra asks "what is the cheapest path from the root to `v`?" (a global one). A minimum spanning tree minimizes total edge weight and says nothing about path lengths; a shortest-path tree does the opposite. Students who learn both in quick succession routinely merge them; the tell-tale symptom is a printed "total" that is not the sum of the edges it lists.

## The Correction

```cpp
if (!inTree[v] && nb.weight < key[v]) {
    key[v] = nb.weight;
    parent[v] = u;
    pq.push({key[v], v});
}
```

## Instructor Notes

- Students who only change `total += key[u]` to sum the actual edge weights will print 42 with the same wrong tree. Insist that the total be 37 and that the tree match.
- Ask them to overlay the two trees on the textbook figure: the shortest-path tree and the MST share five edges and differ on three. That makes the "same skeleton, different objective" point vivid.
- Point out that after the fix, `total += key[u]` *is* correct, because each key is exactly the weight of the edge that attaches `u`.
- Lazy deletion (`if (inTree[u]) continue;`) is already right in the buggy program; ask why a stale entry can never cause a wrong tree even though it can be popped.
