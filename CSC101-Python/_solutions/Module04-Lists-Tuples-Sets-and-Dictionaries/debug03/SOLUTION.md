# Solution: Store Inventory Lookup

**Course/Module/Activity:** CSC101 · Module 4 Lists, Tuples, Sets, and Dictionaries · debug03  
**Bug type(s):** runtime (KeyError)  
**Bug count:** 1

## Observed Behavior

The `Backpack` run works. The `stapler` run crashes:

```
Items we track: ['notebook', 'pencil', 'backpack', 'calculator']
Which item are you looking for? stapler
Traceback (most recent call last):
  File "inventory.py", line 15, in <module>
    count = inventory[item]
KeyError: 'stapler'
```

## The Bug(s)

`inventory.py`, line 15: `inventory[item]` uses subscript lookup, which raises `KeyError` when
the key is absent. The specification says a missing item should be reported as `0`.

## Why the Program Behaved Incorrectly

Square-bracket lookup on a dictionary is strict: the key must exist. `"stapler"` is not a key, so
Python raises `KeyError` and the program stops before printing anything else. The `get` method
performs the same lookup but returns a default value (here `0`) instead of raising.

## The Concept This Illustrates

Dictionary lookup semantics: `d[key]` versus `d.get(key, default)`. Choosing between them is a
design decision — is a missing key a mistake in the program, or an expected situation the program
should handle gracefully?

## The Correction

```python
# before
count = inventory[item]
# after
count = inventory.get(item, 0)
```

## Instructor Notes

* Students who have peeked at Module 5 may propose `if item in inventory: ... else: ...`. That is
  a correct approach and worth acknowledging, but at this point in the course `get` with a default
  is the intended tool; ask which is shorter and clearer.
* Some students propose adding `"stapler": 0` to the dictionary. Ask what happens for the *next*
  item that is not there.
* Ask why the program lowercases the input, and what would happen with `"Backpack"` if it did not.
