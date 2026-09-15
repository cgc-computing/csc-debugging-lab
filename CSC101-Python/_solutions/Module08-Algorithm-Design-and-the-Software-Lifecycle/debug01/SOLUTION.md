# Solution: Coldest Reading of the Day

**Course/Module/Activity:** CSC101 · Module 8 Algorithm Design and the Software Lifecycle · debug01  
**Bug type(s):** logic (initialization assumption)  
**Bug count:** 1

## Observed Behavior

```
Coldest reading: 0.0 F (reading #0)
```

The program reports a temperature that was never entered and a position that does not exist.

## The Bug(s)

`coldest_reading.py`, line 13: `coldest = 0` assumes that 0 is a safe "nothing seen yet" value.
Every sample reading is above 0, so `temperature < coldest` is false on every iteration and
`coldest` / `coldest_position` are never updated.

## Why the Program Behaved Incorrectly

The algorithm says to track "the coldest seen so far," but before any reading there *is* no
coldest so far. Using 0 silently invents a reading of 0 degrees. With winter data (negative
temperatures) the program would appear to work, which is why the misconception survives testing.

## The Concept This Illustrates

Implementing an algorithm faithfully, including its initial state. Min/max tracking must start
from the first real data value (or from a sentinel guaranteed to be beaten, or by treating the
first iteration specially). Tracing the code against the pseudocode with concrete data is the
lifecycle skill being practiced.

## The Correction

```python
# before
    if temperature < coldest:
# after
    if position == 1 or temperature < coldest:
```

Equally acceptable: read the first temperature before the loop and start `coldest` from it, or
initialize `coldest = float("inf")` with `coldest_position = 1`.

## Instructor Notes

* Students who change `coldest = 0` to `coldest = 1000` have a fix that "works" for the sample
  data. Ask what happens on Venus, or simply ask them to justify the number; steer toward
  "initialize from the data" rather than "pick a big constant."
* Ask them to draw the trace table for the sample data with the original code; the row for
  reading 2 (38 < 0 is false) is where the light goes on.
* Connect to the lifecycle: the design was fine; the implementation added an assumption the
  design never made. Testing with only negative temperatures would have missed it.
