# Solution: AVL Tree Insert and Delete

**Course/Module/Activity:** CSC310 · Module 5 Advanced Trees · debug02
**Bug type(s):** logic (order of state updates; stale cached values)
**Bug count:** 1 misconception, present in both rotation functions

## Observed Behavior

```
after inserting 1..15
  inorder        : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
  root           : 12
  stored height  : 9
  measured height: 5
  balanced       : False
after deleting 1, 2, 3, 4, 8
  inorder        : [5, 6, 7, 9, 10, 11, 12, 13, 14, 15]
  root           : 9
  stored height  : 3
  measured height: 3
  balanced       : True
```

The keys are all present and in order, but the tree built by insertion has height 5 instead of 3,
the root is 12 instead of 8, the root's stored height (9) is wildly larger than the real height, and
the balance check fails. After the deletions the tree happens to be repaired.

## The Bug(s)

`avl_tree.py`, functions `rotate_right` and `rotate_left`. The two `update_height` calls are in the
wrong order:

```python
def rotate_right(y):
    x = y.left
    y.left = x.right
    x.right = y
    update_height(x)      # x is now the parent of y ...
    update_height(y)      # ... but y's height is recomputed second
    return x
```

(and symmetrically in `rotate_left`).

## Why the Program Behaved Incorrectly

After `x.right = y`, node `x`'s height is `1 + max(height(x.left), height(y))`. Recomputing `x`
first uses `y`'s *old* height, which was the height of the whole pre-rotation subtree; that value is
one too large, so `x.height` is inflated by one. The inflated value is then returned to the caller
(`rebalance` → `insert`), whose own `update_height` propagates it upward. Every rotation adds
another unit of error, which is why the stored root height grows to 9. The inflated heights also
feed `balance`, so `rebalance` sees phantom imbalances and rotates when it should not (and, at other
times, misses real imbalances), producing a tree of height 5 with 12 at the root. The deletions
happen to trigger rotations that recompute the affected heights from children whose stored heights
were already correct, so the tree "heals", which is a coincidence rather than a fix.

## The Concept This Illustrates

AVL and red-black trees cache structural information (heights, colors, sizes) in nodes, and every
structural change must update that cache *bottom-up*: a node's cached value may only be recomputed
after all of its children's values are final. A rotation reverses the parent/child relationship of
two nodes, so the order of the two updates must follow the *new* shape, not the old one. The bug is
a stale-cache problem; students who hold it usually think of the two updates as independent
bookkeeping rather than as a dependency chain.

## The Correction

```python
# before (rotate_right)
update_height(x)
update_height(y)
# after
update_height(y)      # new child first
update_height(x)      # new parent second

# before (rotate_left)
update_height(y)
update_height(x)
# after
update_height(x)
update_height(y)
```

## Instructor Notes

- Students often fix only one of the two rotations. The ascending insert sequence exercises
  `rotate_left` almost exclusively, so fixing `rotate_left` alone makes this run pass. Ask them to
  insert 15 down to 1 to exercise the other rotation.
- Another "fix" is to have `rebalance` call `measured_height` instead of using stored heights. It
  makes the output correct but turns every insert into O(n); ask what the stored heights are *for*.
- Have students add a print inside `rotate_left` showing the two heights before and after; the
  off-by-one at each rotation is easy to see.
- Follow-up: why is the AVL height bound about 1.44 log2 n, and what would the stored heights have
  to be for the tree of height 5 to be reported as balanced?
