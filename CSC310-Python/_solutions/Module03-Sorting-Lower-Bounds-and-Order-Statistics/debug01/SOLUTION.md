# Solution: LSD Radix Sort on Counting Sort

**Course/Module/Activity:** CSC310 · Module 3 Sorting Lower Bounds and Order Statistics · debug01
**Bug type(s):** logic (stability)
**Bug count:** 1

## Observed Behavior

```
input : [329, 457, 657, 839, 436, 720, 355]
pass 1: [720, 355, 436, 657, 457, 839, 329]
sorted: [355, 329, 457, 436, 657, 720, 839]
correct: False

student ids sorted: [1011, 1049, 1043, 2011, 2043, 2087, 3011, 3087]
correct: False
```

Each pass is sorted by its own digit (pass 1 really is ordered by ones digit), but ties are
reversed: 657 comes before 457. The final result has pairs out of order.

## The Bug(s)

`radix_sort.py`, function `counting_sort_by_digit`, placement loop:

```python
for x in A:
    d = digit(x, place)
    B[C[d] - 1] = x
    C[d] -= 1
```

CLRS's placement loop runs `for j = A.length downto 1`, i.e., over the input from *right to left*.
Iterating left to right while filling slots from the *top* of each digit's block (`C[d] - 1`,
decrementing) puts the first-seen element of a digit class in the highest slot, reversing every
group of equal digits.

## Why the Program Behaved Incorrectly

Counting sort is only useful as a radix-sort subroutine if it is stable. Pass 1 reverses equal
ones-digits (457, 657 → 657, 457). Pass 2 then orders by tens digit and again reverses ties. Because
each pass destroys the order established by the previous ones, the lower digits are not respected
in the final result: 355 and 329 share tens digit... no, they share hundreds digit 3; the last pass
places them by hundreds digit and, being unstable, flips them into `355, 329`. For the IDs, 1049 and
1043 share every digit but the ones, and the final (thousands) pass reverses them.

## The Concept This Illustrates

Radix sort's correctness proof (the radix-sort lemma in CLRS Section 8.3) hinges on the intermediate sort being stable: after
sorting on digit *i*, elements that agree on digit *i* must remain in the order given by the
lower-order digits. Counting sort achieves stability specifically by scanning the input backwards
while filling each block from its top; either direction alone can be made stable, but the two
choices must agree.

## The Correction

```python
# before
for x in A:
# after
for x in reversed(A):        # right to left keeps equal digits in order
```

An equivalent fix is to keep the forward scan but convert `C` to *starting* positions (exclusive
prefix sums) and increment after each placement.

## Instructor Notes

- Students often "fix" stability by sorting most-significant digit first. Ask them to try it; MSD
  radix sort without bucketing is simply wrong, and the exercise shows why LSD needs stability.
- The pass-1 output is deliberately printed so students can spot the tie reversal without tracing
  three passes.
- Ask students which of the two loops (the prefix-sum loop or the placement loop) could be altered
  to restore stability and why both variants are O(n + k).
- Good tie-in to the module's lower-bound discussion: radix sort beats Ω(n lg n) because it does
  not use comparisons; ask what assumption about the keys makes that possible.
