# Solution: Library Shelf Search

**Course/Module/Activity:** CSC205 · Module 10 Searching · debug02
**Bug type(s):** logic
**Bug count:** 2 (related, and each appears in both search functions: the loop never stops at a match, and the "not found" sentinel is a valid index)

## Observed Behavior

```
First book by Austen: #4 "Sense and Sensibility"
First book by Gibson: #3 "Neuromancer"
First book by Tolkien: #0 "Dune"
First checked-out book: #4 "Sense and Sensibility"
```

Searches that have several matches report the *last* one, and a search with no match reports book #0.

## The Bug(s)

`first_match.cpp`, functions `findFirstByAuthor` and `findFirstCheckedOut` (identical structure):

1. When a match is found, the code records `found = i` and keeps looping. Every later match overwrites the earlier one, so the function returns the position of the last match.
2. `found` is initialized to `0`, so when nothing matches the function returns 0 — the index of a real book — instead of the documented `-1`.

## Why the Program Behaved Incorrectly

For "Austen", books #1, #2, and #4 all match. `found` becomes 1, then 2, then 4, and the loop ends with 4. The Gibson search looks right only because there is a single Gibson book. For "Tolkien", no book matches, `found` never changes from its initial 0, and `report` happily prints `#0 "Dune"` because 0 is a legal index.

## The Concept This Illustrates

A linear search for the *first* match has an early exit: the moment the condition is true, the answer is known and the loop must stop (via `return` or `break`). Continuing to scan is not just slower — it changes the answer. The second half of the lesson is that the "not found" result must be a value that cannot collide with a legitimate answer; `-1` is the conventional sentinel for index-returning searches, and callers rely on it (`report` tests `index < 0`). Students often conflate "the loop finished" with "the search succeeded."

## The Correction

```cpp
// before
int found = 0;
for (size_t i = 0; i < books.size(); i++) {
    if (books[i].author == author) {
        found = static_cast<int>(i);
    }
}
return found;

// after
for (size_t i = 0; i < books.size(); i++) {
    if (books[i].author == author) {
        return static_cast<int>(i);
    }
}
return -1;
```

(Same change in `findFirstCheckedOut`.)

## Instructor Notes

- Some students add `break` but leave `found = 0`; the Tolkien line still says Dune. Others change only the sentinel and get `#4` for Austen. Make sure they run all four lines after each change.
- Ask about efficiency: without the early exit the search is always Θ(n); with it, the best case is O(1). This connects to the Big-O discussion from Module 5.
- A student may propose returning `books.size()` as the "not found" value instead of `-1`. That is a valid convention (it is what the STL does with `end()`), but `report` would then index out of range; ask what else would have to change.
- Follow-up: "What would you change to find the *last* checked-out book efficiently?" (iterate from the back).
