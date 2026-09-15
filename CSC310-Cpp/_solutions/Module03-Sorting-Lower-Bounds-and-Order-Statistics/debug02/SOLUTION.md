# Solution: Randomized Select

**Course/Module/Activity:** CSC310 · Module 3 Sorting Lower Bounds and Order Statistics · debug02
**Bug type(s):** boundary, runtime
**Bug count:** 1

## Observed Behavior

```
data: 29 3 47 12 8 35 21 40 15 6 33 

i = 1:  select -> 6   (sorted[1] = 3)
i = 3:  select -> 15   (sorted[3] = 8)
i = 6:  select -> 29   (sorted[6] = 21)
i = 9:  select -> 47   (sorted[9] = 35)
libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
```

Every answer is the (i+1)-th smallest rather than the i-th, and the query for i = 11 walks off the end of the array (caught by `.at()`; exit status 134).

## The Bug(s)

`randomized_select.cpp`, function `randomizedSelect`:

```cpp
int k = q - p;               // should be q - p + 1
```

`k` is meant to be the number of elements in the low side *including the pivot*, i.e. the pivot's rank within `a[p..r]`.

## Why the Program Behaved Incorrectly

With `k` one too small, the pivot's rank is misreported: when the pivot really is the i-th smallest (`i == q - p + 1`), the test `i == k` fails and `i < k` is false, so the code recurses to the right with `i - k = 1` and returns the smallest element there: the (i+1)-th smallest overall. When i is the maximum rank, the right side eventually becomes empty (`q + 1 > r`), and `a.at(p)` for `p == r + 1` throws `out_of_range`. Because a random pivot is used, some queries could come out right by luck (when `i < k` is decided correctly), but with the fixed seed every query in the sample goes wrong.

## The Concept This Illustrates

Order-statistic selection works by comparing the target rank with the pivot's rank and *renumbering* the rank when recursing to the right (`i - k`). Students who see `q - p` as "the size of the left part" forget that the pivot occupies position `q` and is itself the `(q - p + 1)`-th element. This is the same 1-based versus 0-based bookkeeping that makes CLRS's `k = q - p + 1` essential, and the sample is designed so every query is off by exactly one.

## The Correction

```cpp
int k = q - p + 1;           // number of elements in the low side, including the pivot
if (i == k) return a.at(q);
if (i < k)  return randomizedSelect(a, p, q - 1, i);
return randomizedSelect(a, q + 1, r, i - k);
```

## Instructor Notes

- Some students "fix" it by changing the recursive call to `i - k - 1` or by making `i` 0-based in the driver; ask them to check the `i == k` case as well, which those changes leave broken.
- The exception is deterministic because `.at()` is used; if a student changes it to `[]` the same run becomes undefined behavior. This is a good moment to discuss why `.at()` is a debugging aid.
- Ask why the expected running time is Θ(n) even though the worst case is Θ(n²), and how the random pivot achieves that.
