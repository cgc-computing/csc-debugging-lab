# Solution: Remove Even Numbers From a List

**Course/Module/Activity:** CSC205 · Module 6 Arrays, ArrayLists, Collections, and Iterators · debug01
**Bug type(s):** logic, boundary
**Bug count:** 1

## Observed Behavior

```
Before: [3, 8, 6, 10, 7, 12, 14, 5, 2]
After:  [3, 6, 7, 14, 5]
```

Every even number that immediately follows another even number survives.

## The Bug(s)

`RemoveEvens.java`, `removeEvens`: after `values.remove(i)` the elements to the right shift left by one, so the element that moves into index `i` is never examined; the loop's `i++` steps over it.

## Why the Program Behaved Incorrectly

Trace: at `i = 1` the value 8 is removed and 6 slides into index 1. The loop then advances to `i = 2`, which now holds 10; 6 is skipped. Removing 10 slides 7 into index 2; `i = 3` is 12 (removed), 14 slides into 3 and is skipped; `i = 4` is 5; `i = 5` is 2 (removed). Result: `[3, 6, 7, 14, 5]`. The pattern — consecutive evens lose only every other one — is the fingerprint of an index that advances past a shifted element.

## The Concept This Illustrates

An `ArrayList` is a *shifting* structure: removal changes the indices of everything after it, so an index-controlled loop must compensate. Options: decrement `i` after a removal, iterate from the end backward, or use an `Iterator` and call `iterator.remove()`. Using a for-each loop and calling `values.remove(...)` inside it is *not* an option — it throws `ConcurrentModificationException`.

## The Correction

```java
// before
if (values.get(i) % 2 == 0) {
    values.remove(i);
}
// after
if (values.get(i) % 2 == 0) {
    values.remove(i);
    i--;
}
```

Equivalent fixes: `for (int i = values.size() - 1; i >= 0; i--)`, or

```java
Iterator<Integer> it = values.iterator();
while (it.hasNext()) {
    if (it.next() % 2 == 0) it.remove();
}
```

## Instructor Notes

- Students who switch to a for-each loop with `values.remove(Integer.valueOf(x))` will see `ConcurrentModificationException`; that is a valuable detour — ask what the iterator is protecting them from.
- Some try `values.remove(values.get(i))`. With `Integer` this calls `remove(Object)` and removes the first equal value, which happens to be the same element here, but the skip problem remains. Also good to point out the overload trap between `remove(int index)` and `remove(Object o)`.
- Ask: "Why does the backward loop not need any adjustment?" (Removals only shift elements the loop has already visited.)
- `removeIf(v -> v % 2 == 0)` is the modern one-liner; mention it after the mechanics are understood.
