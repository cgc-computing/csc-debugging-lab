# Solution: Paint Estimate

**Course/Module/Activity:** CSC101 · Module 9 Functions · debug01  
**Bug type(s):** runtime (TypeError on None) / conceptual (print vs. return)  
**Bug count:** 1

## Observed Behavior

```
Room length (ft): 15
Room width (ft): 12
Wall height (ft): 10
150.0
Traceback (most recent call last):
  File "paint_estimate.py", line 21, in <module>
    long_walls = 2 * wall_area(length, height)
TypeError: unsupported operand type(s) for *: 'int' and 'NoneType'
```

A stray `150.0` appears, then the program crashes.

## The Bug(s)

`paint_estimate.py`, line 9: `wall_area` prints the area instead of returning it. With no
`return`, the function's value is `None`, so `2 * None` fails.

## Why the Program Behaved Incorrectly

Calling `wall_area(15, 10)` runs the body, which displays `150.0` on the screen, then falls off
the end of the function and hands back `None`. The caller multiplies that `None` by 2 and Python
raises `TypeError`. The number went to the screen when it needed to go back to the expression.

## The Concept This Illustrates

`print` sends a value to the user; `return` sends a value to the *code that called the
function*. A function meant to be used inside an expression must return. Every function without an
explicit `return` returns `None`.

## The Correction

```python
# before
def wall_area(length, height):
    print(length * height)
# after
def wall_area(length, height):
    return length * height
```

## Instructor Notes

* Ask students to explain the `150.0` line: which call produced it, and why did only one appear
  before the crash?
* Some students add `return` but keep the `print`; the program then works but shows two extra
  numbers. Ask whether a helper function should be talking to the user at all.
* Contrast with `gallons_needed`, which is written correctly, to show both styles side by side.
