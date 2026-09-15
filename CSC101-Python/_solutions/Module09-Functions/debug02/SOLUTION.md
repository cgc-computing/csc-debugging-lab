# Solution: Daily Weather Summary

**Course/Module/Activity:** CSC101 · Module 9 Functions · debug02  
**Bug type(s):** logic (arguments passed in the wrong order)  
**Bug count:** 1

## Observed Behavior

```
Low:  54.0 F
High: 78.0 F
The temperature rose -24.0 degrees, a small swing.
```

The change is reported as negative and described as small.

## The Bug(s)

`weather_summary.py`, line 23: `daily_range(morning, afternoon)`. The function is defined as
`daily_range(high, low)`, so the morning (low) temperature lands in `high` and the afternoon
(high) temperature lands in `low`. The function then computes `54 - 78`.

## Why the Program Behaved Incorrectly

Positional arguments are matched to parameters by *position*, not by meaning or by name. The
function body is correct for its own parameter names; the call site handed it the values in the
opposite order. The negative result then falls into the "small swing" branch of `describe_range`,
which is doing exactly what it was told.

## The Concept This Illustrates

The contract between a function definition and its callers: parameter order is part of the
interface. Well-chosen parameter names help, but only if the caller reads them. This also
demonstrates how one incorrect value propagates through later, correct code.

## The Correction

```python
# before
swing = daily_range(morning, afternoon)
# after
swing = daily_range(afternoon, morning)
```

Swapping the parameter order in the `def` (and leaving the call alone) is equally valid, as is
calling with keyword arguments: `daily_range(high=afternoon, low=morning)`.

## Instructor Notes

* Ask students to annotate the call with the parameter names as comments; the mismatch becomes
  visible immediately.
* Some students "fix" the function body to `return low - high`, which works only because both
  ends of the mistake now cancel. Ask them to read the new function body aloud and say whether it
  matches its docstring.
* Others wrap the result in `abs()`; ask why hiding the sign is not the same as computing the
  right thing.
