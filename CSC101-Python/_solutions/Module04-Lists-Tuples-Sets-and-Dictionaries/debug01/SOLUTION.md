# Solution: Grocery List

**Course/Module/Activity:** CSC101 · Module 4 Lists, Tuples, Sets, and Dictionaries · debug01  
**Bug type(s):** runtime (AttributeError on None)  
**Bug count:** 1

## Observed Behavior

```
Starting list: ['milk', 'bread', 'apples']
What else do you need? eggs
Traceback (most recent call last):
  File "grocery_list.py", line 11, in <module>
    groceries.sort()
AttributeError: 'NoneType' object has no attribute 'sort'
```

## The Bug(s)

`grocery_list.py`, line 9: `groceries = groceries.append(new_item)`. `append` modifies the list
in place and returns `None`; assigning that result replaces the list with `None`. The traceback
points at line 11 (`sort`), but the damage was done on line 9.

## Why the Program Behaved Incorrectly

After line 9, `groceries` is `None`, not a list. The original list object still had `eggs`
appended to it, but no variable refers to it anymore. Line 11 asks `None` to sort, and `None`
has no such method.

## The Concept This Illustrates

Mutating methods on lists (`append`, `sort`, `reverse`, `extend`) work in place and return
`None`; you do not assign their result. This is the mirror image of string methods, which return a
new value that *must* be assigned. Also: a traceback's line number shows where the crash surfaced,
not necessarily where the mistake was made.

## The Correction

```python
# before
groceries = groceries.append(new_item)
# after
groceries.append(new_item)
```

## Instructor Notes

* Students who just learned `text = text.upper()` in Module 3 apply the same pattern here; make
  the contrast explicit.
* Some students will "fix" line 11 (the line in the traceback) by writing
  `groceries = sorted(groceries)`; it still crashes because `groceries` is already `None`.
  Use that to teach reading *backward* from the traceback.
* Ask: if the program were changed to `sorted_list = groceries.sort()`, what would print?
