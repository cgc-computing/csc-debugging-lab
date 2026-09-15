# Solution: Connected Components With a Disjoint-Set Forest

**Course/Module/Activity:** CSC310 · Module 6 Disjoint Sets and Introduction to Graphs · debug01
**Bug type(s):** logic (operating on set members instead of set representatives)
**Bug count:** 1

## Observed Behavior

```
components     : ['abc', 'd', 'eg', 'f', 'hi', 'j']
set count      : 4

same_set(a, d) = False
...
chain 0-1-2-3-4-5 sets: 1  same_set(0,5) = False
```

Vertex `d` is split off from `a, b, c`, the set counter (4) disagrees with the number of groups
actually present (6), and in the chain test the counter says one set while `same_set(0, 5)` is
`False`.

## The Bug(s)

`disjoint_set.py`, method `union`:

```python
def union(self, x, y):
    if self.parent[x] != self.parent[y]:
        self._link(x, y)
```

`union` compares and links the two *vertices* themselves (via their immediate `parent` entries)
rather than the roots of their trees.

## Why the Program Behaved Incorrectly

`_link` assumes its arguments are roots and does `parent[x] = y` (or the reverse). When `x` is not a
root, overwriting `parent[x]` detaches `x` from its current tree, taking nothing else with it, so the
old set is silently split. Trace: after `(b, d)` we have `parent[b] = d`; after `(a, c)` we have
`parent[a] = c`. The edge `(a, b)` then compares `parent[a] = c` with `parent[b] = d`, finds them
different, and links `a` under `b`: `parent[a] = b`. Vertex `a` has left `c`'s set, and `c`'s tree
still contains only `c`. Finally `(b, c)` links `parent[b] = c`, dragging `a` and `b` under `c` but
leaving `d` alone. Every `_link` also decrements `sets`, so the counter counts *link operations*
rather than merges, which is why it reads 4 while six groups exist. In the chain test, `union(1, 2)`
sets `parent[1] = 2` even though `parent[0] = 1` already, so 0's chain is repeatedly broken.

## The Concept This Illustrates

In a disjoint-set forest, a set is identified by its *representative* (root), and UNION is defined on
representatives: CLRS writes `UNION(x, y) = LINK(FIND-SET(x), FIND-SET(y))`. Only a root can be
re-parented without changing the membership of anything else. Students holding this bug think of
`parent[x]` as "the set x is in", when it is only one step toward that set; the FIND-SET call is what
turns a member into its set.

## The Correction

```python
# before
if self.parent[x] != self.parent[y]:
    self._link(x, y)

# after
rx, ry = self.find(x), self.find(y)
if rx != ry:
    self._link(rx, ry)
```

## Instructor Notes

- Some students change only the comparison to `self.find(x) != self.find(y)` but still call
  `_link(x, y)`. The output improves for some inputs and not others; ask them what `_link`'s
  precondition is.
- Others make `_link` itself call `find` on its arguments. That works, but ask why the ranks would
  then be meaningless if `_link` were ever called with non-roots by another path.
- Ask students to write out `parent[]` after every edge, with and without path compression, and
  to observe that path compression alone cannot repair a split set.
- Follow-up: the `sets` counter is decremented inside `_link`. Is that the right place once
  `union` is fixed? (Yes: `_link` is then only called for two distinct roots.)
