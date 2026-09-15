# Solution: Bake Sale Tracker

**Course/Module/Activity:** CSC101 · Module 9 Functions · debug03  
**Bug type(s):** runtime (UnboundLocalError) / conceptual (scope)  
**Bug count:** 1

## Observed Behavior

```
Bake Sale Tracker
How many sales to record? 3
Sale 1 amount: $2.50
Traceback (most recent call last):
  File "bake_sale.py", line 18, in <module>
    record_sale(amount)
  File "bake_sale.py", line 9, in record_sale
    total_sales = total_sales + amount
UnboundLocalError: local variable 'total_sales' referenced before assignment
```

## The Bug(s)

`bake_sale.py`, line 9: `total_sales = total_sales + amount` inside `record_sale`. Because the
function *assigns* to `total_sales`, Python treats `total_sales` as a local variable for the entire
function body. The right-hand side then tries to read that local before it has any value.

## Why the Program Behaved Incorrectly

Scope is decided when the function is compiled, not line by line. Any name assigned anywhere in a
function is local to that function. So the `total_sales` on the right side of line 9 refers to
the (empty) local, not the module-level variable defined on line 4, and Python raises
`UnboundLocalError`. Even if the read had succeeded, the assignment would only have updated the
local copy, and the final total would have stayed 0.00.

## The Concept This Illustrates

Local versus global scope and why functions should communicate through parameters and return
values rather than by reaching out to variables defined elsewhere. The caller owns the running
total; the function should receive it, compute the new value, and hand it back.

## The Correction

```python
# before
def record_sale(amount):
    total_sales = total_sales + amount
    print(...)
...
    record_sale(amount)
# after
def record_sale(total_so_far, amount):
    new_total = total_so_far + amount
    print(...)
    return new_total
...
    total_sales = record_sale(total_sales, amount)
```

## Instructor Notes

* Many students will discover `global total_sales` and it does make the program run. Accept it
  as *working*, then ask: how would a reader of `record_sale` know it changes something outside
  itself? Steer toward parameters and return values as the default design.
* Ask why the traceback shows two `File` lines and what each one tells you (call site vs. the
  line inside the function).
* Ask what would happen if line 9 only *read* `total_sales` (e.g., `print(total_sales)`) without
  assigning. (It works — reading a global is fine; assigning is what makes it local.)
