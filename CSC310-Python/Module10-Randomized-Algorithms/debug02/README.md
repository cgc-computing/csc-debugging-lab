# Reservoir Sampling From a Stream

**Course:** CSC310 &nbsp;|&nbsp; **Module 10:** Randomized Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`reservoir_sampling.py` implements Algorithm R: read a stream once, keep the first k items, and let
the t-th item (counting from 1) replace a uniformly chosen reservoir slot with probability k/t. At the
end every k-subset of the stream should be equally likely, so every item should be selected equally
often. The `main` block repeats the sampling 40 000 times with a fixed seed and tallies how often each
item is chosen, first for k = 1 of 4 items and then for k = 3 of 10 items.

## Expected Behavior

```
sample 1 of 4 items, 40000 trials, expected about 10000 selections each
  item  1:  10020   (25.05%)
  item  2:   9966   (24.91%)
  item  3:   9925   (24.81%)
  item  4:  10089   (25.22%)
  largest deviation from expected: 89 (0.9%)

sample 3 of 10 items, 40000 trials, expected about 12000 selections each
  item  1:  12041   (10.03%)
  item  2:  11931   ( 9.94%)
  item  3:  11921   ( 9.93%)
  item  4:  12301   (10.25%)
  item  5:  11929   ( 9.94%)
  item  6:  11857   ( 9.88%)
  item  7:  11777   ( 9.81%)
  item  8:  12186   (10.15%)
  item  9:  11982   ( 9.98%)
  item 10:  12075   (10.06%)
  largest deviation from expected: 301 (2.5%)
```

Exact counts depend on the generator, but every item should be within a few percent of its expected
count.

## How to Run

```bash
python3 reservoir_sampling.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
single-pass design; do not store the whole stream and sample from it afterwards.

## Think About

- In the k = 1 case, item 1 is never selected. Trace what happens when the second item arrives:
  what is the probability that it replaces the reservoir, and what should it be?
- The algorithm needs "replace with probability k/t". The code implements that by drawing an
  integer and comparing it with k. How many equally likely integers must the draw produce for the
  comparison to have probability exactly k/t?
- Why are items 1 through k (the ones that fill the reservoir) the ones that are under-sampled, and
  the later ones over-sampled?
- Work out by hand the probability that item 1 survives for a stream of 4 items with k = 1, both
  for the correct rule and for the program's rule.
