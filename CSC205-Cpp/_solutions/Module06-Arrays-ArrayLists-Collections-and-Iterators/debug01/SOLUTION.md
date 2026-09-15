# Solution: Remove the Even Numbers

**Course/Module/Activity:** CSC205 · Module 6 Arrays, ArrayLists, Collections, and Iterators · debug01
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
Before: [2, 4, 6, 7, 8, 10, 11, 12]
After:  [4, 7, 10, 11]
Remaining count: 4
```

Half of the even numbers survive — always the one immediately after an erased one.

## The Bug(s)

`removeEvens` advances `i` unconditionally after an `erase`:

```cpp
for (size_t i = 0; i < v.size(); i++) {
    if (v[i] % 2 == 0) {
        v.erase(v.begin() + i);
    }
}
```

## Why the Program Behaved Incorrectly

`erase` shifts every later element one slot to the left, so the element that *was* at `i + 1` is now at `i`. The loop's `i++` then steps past it without ever testing it. Trace: `i = 0` erases 2 → `[4, 6, 7, 8, 10, 11, 12]`; `i = 1` erases 6 (skipping 4) → `[4, 7, 8, 10, 11, 12]`; `i = 2` erases 8 → `[4, 7, 10, 11, 12]`; `i = 3` sees 11; `i = 4` erases 12; loop ends with `[4, 7, 10, 11]`. Because `v.size()` is re-read each iteration the loop never runs out of bounds — the result is simply wrong, deterministically.

## The Concept This Illustrates

Modifying a sequence while indexing through it changes the meaning of the index. The invariant "position `i` has been examined" breaks the moment an element is removed at `i`. The Java version of this lesson is `ConcurrentModificationException` or skipped neighbors with `remove(i)`; in C++ the same misconception appears as skipped elements with an index, or as iterator invalidation when using `erase(it)` inside a loop that then does `++it`. In both languages the fix is the same idea: after a removal, *do not advance*.

## The Correction

```cpp
// before
for (size_t i = 0; i < v.size(); i++) {
    if (v[i] % 2 == 0) {
        v.erase(v.begin() + i);
    }
}

// after
for (size_t i = 0; i < v.size(); ) {
    if (v[i] % 2 == 0) {
        v.erase(v.begin() + i);
    } else {
        i++;
    }
}
```

Equivalent accepted fixes: iterate from the back (`for (size_t i = v.size(); i-- > 0; )`), use `it = v.erase(it)` in an iterator loop, or the erase–remove idiom `v.erase(remove_if(...), v.end())`.

## Instructor Notes

- Some students write `i--` right after `erase`. With `size_t`, that wraps to a huge value when `i == 0`, and then `i++` brings it back to 0, so it "works" by accident; ask them what `i` holds between those two statements and whether they are comfortable with that.
- Students who switch to a range-for and call `erase` inside it will get undefined behavior (the loop's hidden `end()` iterator is stale). This is a good moment to discuss iterator invalidation and why `erase` returns the next valid iterator.
- Ask for the running time of this approach on a vector of n elements (each `erase` is O(n), so O(n²) worst case) and contrast with the erase–remove idiom, which is O(n).
