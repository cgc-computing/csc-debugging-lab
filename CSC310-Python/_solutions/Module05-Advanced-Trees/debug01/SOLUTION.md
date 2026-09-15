# Solution: Rotations in a BST With Parent Pointers

**Course/Module/Activity:** CSC310 · Module 5 Advanced Trees · debug01
**Bug type(s):** logic (pointer bookkeeping in a structural operation)
**Bug count:** 1

## Observed Behavior

The first four rotations look right (three are at the root; the fourth is a *right* rotation). The
final left rotation at a non-root node loses two keys:

```
after R-rotate at 3: root 4, inorder [1, 2, 3, 4, 5, 6, 7]
after L-rotate at 5: root 4, inorder [1, 2, 3, 4, 5]

final root      : 4
final height    : 2
parent links ok : False
```

## The Bug(s)

`bst_rotations.py`, method `left_rotate`. After computing `y.parent = x.parent`, the method handles
only the case where `x` was the root:

```python
y.parent = x.parent
if x.parent is None:
    self.root = y
y.left = x
x.parent = y
```

The `elif x is x.parent.left: x.parent.left = y` / `else: x.parent.right = y` branches that make the
old parent point *down* to `y` are missing. `right_rotate` has them and is correct.

## Why the Program Behaved Incorrectly

Left-rotating at 5 (whose parent is 4 and whose right child is 6) should make 6 the right child of 4.
The code sets `6.parent = 4` and `5.parent = 6`, but `4.right` still points at 5. From the root the
traversal reaches 5, whose `right` is now `None` (it received 6's old left subtree), so 6 and 7 are
unreachable: they are orphaned. `parent_links_ok` fails because `4.right` is 5 but `5.parent` is 6.
The earlier rotations happened at the root, where the `if x.parent is None` branch does the
re-linking correctly, which is why the symptom is delayed until the last step.

## The Concept This Illustrates

A rotation is a *local* restructuring that must update every pointer touching the two rotated nodes:
the child pointers of x and y, the parent pointers of x, y and the moved subtree, and the pointer
coming *down* from the grandparent. CLRS's LEFT-ROTATE has exactly one statement for each. Forgetting
the downward link from the parent is the classic mistake because it is the only pointer that lives
outside the two nodes being rotated. Red-black and AVL insert/delete fix-ups rely on rotations being
airtight; a rotation that orphans a subtree corrupts every later operation.

## The Correction

```python
# before
y.parent = x.parent
if x.parent is None:
    self.root = y

# after
y.parent = x.parent
if x.parent is None:
    self.root = y
elif x is x.parent.left:
    x.parent.left = y
else:
    x.parent.right = y
```

## Instructor Notes

- Students who "diff" `left_rotate` against `right_rotate` find this quickly; students who try to
  reason about the traversal alone take longer. Encourage both approaches and ask which one
  generalizes to the red-black fix-up code.
- A partial fix adds only `x.parent.right = y` (because in this program the rotated node happens to
  be a right child). Ask what happens when a left rotation is applied to a node that is a left
  child, and have them add a rotation at node 2 to test it.
- Ask why `parent_links_ok` is a useful invariant checker to keep around when implementing
  red-black trees, and what other invariants (BST order, black-height) could be checked the same way.
- Follow-up: the final tree has height 2. How many rotations would a red-black or AVL insert
  sequence have performed on the same input, and where?
