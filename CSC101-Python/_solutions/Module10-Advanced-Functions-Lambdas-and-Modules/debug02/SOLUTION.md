# Solution: Shopping Carts

**Course/Module/Activity:** CSC101 · Module 10 Advanced Functions, Lambdas, and Modules · debug02  
**Bug type(s):** conceptual/design (mutable default argument)  
**Bug count:** 1

## Observed Behavior

```
Alice's cart: ['apples', 'bread', 'cereal', 'milk']
Bob's cart:   ['apples', 'bread', 'cereal', 'milk']
```

Both carts contain all four items — they are the same list.

## The Bug(s)

`shopping_cart.py`, line 5: `def add_item(item, cart=[])`. The default list is created once,
when the `def` statement runs, and that single list object is reused for every call that omits
`cart`.

## Why the Program Behaved Incorrectly

`add_item("apples")` appends to the shared default list and returns it; `alice_cart` now refers
to that object. Later, `add_item("cereal")` again receives the *same* default list (which already
holds apples and bread), appends cereal, and returns it, so `bob_cart` is the identical object.
Every subsequent append is visible through both names.

## The Concept This Illustrates

Default argument values are evaluated once at function-definition time, not per call. With an
immutable default (`0`, `""`, `None`) this is harmless; with a mutable default (`[]`, `{}`) the
state leaks between calls. The idiom is `cart=None` plus `if cart is None: cart = []`.

## The Correction

```python
# before
def add_item(item, cart=[]):
    cart.append(item)
    return cart
# after
def add_item(item, cart=None):
    if cart is None:
        cart = []
    cart.append(item)
    return cart
```

## Instructor Notes

* Show `print(add_item.__defaults__)` before and after the calls in the original version; students
  can watch the default list grow.
* A tempting non-fix is `cart = cart + [item]` in the body. It happens to work here because it
  never mutates the default, but ask whether the callers who *pass* a cart still see their cart
  updated (they do not, unless they use the return value). Compare the trade-offs.
* Connect back to Module 4 aliasing: two names, one list.
