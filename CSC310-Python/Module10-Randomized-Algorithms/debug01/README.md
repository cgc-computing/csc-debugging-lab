# In-Place Random Shuffle With a Tally

**Course:** CSC310 &nbsp;|&nbsp; **Module 10:** Randomized Algorithms &nbsp;|&nbsp; **Activity:** debug01
**Language:** Python 3

## Goal

`shuffle_tally.py` implements RANDOMIZE-IN-PLACE (CLRS Section 5.3), which must produce each of the
n! permutations with equal probability. To test that claim empirically, the `main` block shuffles
`['A', 'B', 'C']` 100 000 times with a fixed seed, tallies the position where `A` lands, and tallies
how often each of the six permutations appears.

## Expected Behavior

```
100000 shuffles of ['A', 'B', 'C']
where 'A' ends up:
  position 0:  33089   (33.09%)
  position 1:  33594   (33.59%)
  position 2:  33317   (33.32%)
  expected about 33333 each; largest deviation 261

permutation frequencies (expected about 16667 each):
  ABC:  16490
  ACB:  16599
  BAC:  16812
  BCA:  16743
  CAB:  16782
  CBA:  16574
  spread between most and least common: 322
  uniform within 3%: True
```

The exact counts depend on the random generator, but all six permutations should be within a few
hundred of 16 667 and the final line should be `True`.

## How to Run

```bash
python3 shuffle_tally.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
in-place swap loop; do not call `random.shuffle` or `random.sample`.

## Think About

- The shuffle makes three random choices for three elements. How many equally likely outcomes does
  that produce, and how many permutations are there? Can one be divided evenly into the other?
- `A` lands in each position about one third of the time, yet the permutations are not equally
  likely. Why is "each element is equally likely to be anywhere" a weaker statement than "every
  permutation is equally likely"?
- In CLRS's argument, before iteration i the prefix `A[0..i-1]` is a uniformly random (i)-permutation
  of the elements. Which elements are eligible to be placed at position i to keep that invariant
  true, and which elements does the program actually choose among?
- Some permutations are over-represented and some under-represented. Try to enumerate all 27
  outcomes by hand for the program's rule and count how many produce `ABC`.
